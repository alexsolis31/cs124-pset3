#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "completeGraph.h"
#include <time.h>

typedef struct {
    float x;
    float y;
    float z;
    float w;

} coordinate;


completeGraph *genCompleteGraph(unsigned numNodes) {

    assert(numNodes != 0);

    //allocate Graph structure and error handle
    completeGraph *graph = malloc(sizeof(completeGraph));
    if (graph == NULL) {
        printf("Allocating Graph structure failed.\n");
        return NULL;
    }
    graph->edges = NULL;
    graph->numNodes = numNodes;
    /* Allocate edge array and error handle
       Since we have complete graphs, store each edge once, and use the fact
       that 1 + 2 + ... + n = (n + 1) * n / 2 to determine array len with
       n = numNodes - 1 */
    graph->edges = calloc(((numNodes - 1) * numNodes) / 2, sizeof(float));
    if (graph->edges == NULL) {
        printf("Allocating graph with number of nodes: %d failed.\n", numNodes);
        free(graph);
        return NULL;
    }

    return graph;
}

//Randomly populates graph by randomly placing nodes in dimension-cube
//and assigning edges by Euclidean distance.
//Returns 1 on error.
int eucPopulateCompleteGraph(completeGraph *graph, unsigned dimension) {

    int nodes = graph->numNodes;
    int num_edges = (nodes*(nodes-1))/2;

    // array of structs to hold vertex coordinates
    coordinate vertices [nodes];

    // populate the edge array for each dimension
    if (dimension == 0){
        for (int i = 0; i <= num_edges; i++){
            graph->edges[i] = rand_num();
        }
    }

    if (dimension == 2){

        // produce random location for each vertex
        for (int i = 0; i < nodes; i++){
            vertices[i].x = rand_num();
            vertices[i].y = rand_num();

        }

        // edge array updated to hold euclidean distance between vertex (i,j)
        int counter = 0;
        for (int i = 0; i <= nodes; i++){
            for (int j = (i+1); j < nodes; j++){
                graph->edges[counter] = sqrt( pow((vertices[i].x - vertices[j].x), 2)  +  pow((vertices[i].y - vertices[j].x), 2));
                counter++;

            }
        }
    }

    if (dimension == 3){

        // produce random location for each vertex
        for (int i = 0; i < nodes; i++){
            vertices[i].x = rand_num();
            vertices[i].y = rand_num();
            vertices[i].z = rand_num();

        }

        int counter = 0;
        for (int i = 0; i <= nodes; i++){
            for (int j = (i+1); j < nodes; j++){
                graph->edges[counter] = sqrt( pow((vertices[i].x - vertices[j].x), 2)  +  pow((vertices[i].y - vertices[j].y), 2) + pow((vertices[i].z - vertices[j].z), 2));
                counter++;

            }
        }
    }

    if (dimension == 4){
        // produce random location for each vertex
        for (int i = 0; i < nodes; i++){
            vertices[i].x = rand_num();
            vertices[i].y = rand_num();
            vertices[i].z = rand_num();
            vertices[i].w = rand_num();
        }

        int counter = 0;
        for (int i = 0; i <= nodes; i++){
            for (int j = (i+1); j < nodes; j++){
                graph->edges[counter] = sqrt( pow((vertices[i].x - vertices[j].x), 2)  +  pow((vertices[i].y - vertices[j].y), 2) + pow((vertices[i].z - vertices[j].z), 2) + pow((vertices[i].w - vertices[j].w), 2) );
                counter++;

            }
        }

    }
    //calcIndex testing
    /*int counter = 0;
    for (int i = 0; i < nodes; i++) {
        for(int j = i+1; j < nodes; j++) {
            printf("i is %d j is %d counter is %d\n", i, j, counter);
            printf("calc index is: %d\n", calcIndex(i, j, nodes));
            assert(graph->edges[counter] == graph->edges[calcIndex(i, j, nodes)]);
            counter++;
        }
    }*/

    return 0;

}

//Frees all memeory associated with a completeGraph
void destroyCompleteGraph(completeGraph *graph) {
    assert(graph);
    free(graph->edges);
    free(graph);
}

//Changes the edge value for the edge connecting from and to.
//Returns 1 on error
static inline int updateEdge(completeGraph *graph, unsigned from,
                             unsigned to, float val) {

    assert(from != to); //or maybe just return 1 and print error?
    assert(from < graph->numNodes);
    assert(to < graph->numNodes);
    assert(val >= 0);

    if (from < to) {
        graph->edges[calcIndex(from, to, graph->numNodes)] = val;
    }
    else {
        graph->edges[calcIndex(to, from, graph->numNodes)] = val;
    }
    return 0;
}

//Returns the edge value for the edge connecting from and to.
//Returns 0 on error
static inline float getEdge(completeGraph *graph, unsigned from, unsigned to) {

    assert(from != to); //or maybe just return 0 and print error?
    assert(from < graph->numNodes);
    assert(to < graph->numNodes);

    if (from < to) {
        return graph->edges[calcIndex(from, to, graph->numNodes)];
    }
    else {
        return graph->edges[calcIndex(to, from, graph->numNodes)];
    }
}

//Finds the index on the edge linking the vertices lowN and highN for
//a graph with numNodes nodes.
static inline unsigned calcIndex(unsigned lowN, unsigned highN,
                                  unsigned numNodes) {

    assert(lowN < highN);
    assert(highN < numNodes);

    //distance from beginning of array to beginning of edges leaving lowN
    unsigned lowN_offset;
    //how far into the lowN zone one must go for the edge to highN
    unsigned highN_offset = highN - lowN - 1;

    if (lowN == 0) {
        lowN_offset = 0;
    }
    else if (lowN == 1) {
        lowN_offset = numNodes - 1;
    }
    //sum from numnodes-low to numnodes - 1
    else {
        lowN_offset = ((2*numNodes - lowN - 1) * lowN) / 2;
    }
    return lowN_offset + highN_offset;
}


//Returns the weight of the MST for the graph. Returns 0 on error.
float findMST_Weight(completeGraph *graph) {
    (void) graph;
    return 1.0f;
}

//Use tick count and clock as seed for RNG
unsigned rand_calls = 0;

static inline float rand_num() {

    if (rand_calls > 1000) {
        srand(time(NULL) + clock());
        rand_calls = 0;
    }
    rand_calls++;
    return rand() / (double)(RAND_MAX);
}
