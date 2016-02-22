#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "completeGraph.h"
#include "minHeap.h"
#include <time.h>


//Andrew note: magic number 2 << 14.

int Prims(completeGraph *graph);


completeGraph *genCompleteGraph(unsigned numNodes) {

    assert(numNodes != 0);

    //allocate Graph structure and error handle
    completeGraph *graph = calloc(1, sizeof(completeGraph));
    if (!graph) {
        printf("Allocating Graph structure failed.\n");
        return NULL;
    }
    graph->numNodes = numNodes;

    /* Allocate edge array and error handle
       Since we have complete graphs, store each edge once, and use the fact
       that 1 + 2 + ... + n = (n + 1) * n / 2 to determine array len with
       n = numNodes - 1 */
    graph->edges = calloc(((numNodes - 1) * numNodes) / 2, sizeof(float));
    if (!graph->edges) {
        printf("Allocating graph edgeList with number of nodes: %d failed.\n", numNodes);
        free(graph);
        return NULL;
    }

    graph->vertexList = calloc(numNodes, sizeof(vertex));
    if (!graph->vertexList) {
        printf("Allocating graph vertexList with number of nodes: %d failed.\n", numNodes);
        free(graph->edges);
        free(graph);
    }
    for (unsigned i = 0; i < numNodes; i++) {
        graph->vertexList[i].vName = i;
        graph->vertexList[i].distanceToPrevVertex = INFINITY;
    }

    return graph;
}

//Randomly populates graph by randomly placing nodes in dimension-cube
//and assigning edges by Euclidean distance.
//Returns 1 on error.
//TODO: UPDATE
int eucPopulateCompleteGraph(completeGraph *graph, unsigned dimension) {

    int nodes = graph->numNodes;
    int num_edges = (nodes*(nodes-1))/2;


    // populate the edge array for each dimension
    if (dimension == 0){
        for (int i = 0; i <= num_edges; i++){
            graph->edges[i] = rand_num();
        }
    }

    if (dimension == 2){

        // produce random location for each vertex
        for (int i = 0; i < nodes; i++){
            graph->vertexList[i].x = rand_num();
            graph->vertexList[i].y = rand_num();

        }

        // edge array updated to hold euclidean distance between vertex (i,j)
        int counter = 0;
        for (int i = 0; i <= nodes; i++){
            for (int j = (i+1); j < nodes; j++){
                graph->edges[counter] = sqrt( pow((graph->vertexList[i].x - graph->vertexList[j].x), 2)  +  pow((graph->vertexList[i].y - graph->vertexList[j].x), 2));
                counter++;

            }
        }
    }

    if (dimension == 3){

        // produce random location for each vertex
        for (int i = 0; i < nodes; i++){
            graph->vertexList[i].x = rand_num();
            graph->vertexList[i].y = rand_num();
            graph->vertexList[i].z = rand_num();

        }

        int counter = 0;
        for (int i = 0; i <= nodes; i++){
            for (int j = (i+1); j < nodes; j++){
                graph->edges[counter] = sqrt( pow((graph->vertexList[i].x - graph->vertexList[j].x), 2)  +  pow((graph->vertexList[i].y - graph->vertexList[j].y), 2) + pow((graph->vertexList[i].z - graph->vertexList[j].z), 2));
                counter++;

            }
        }
    }

    if (dimension == 4){
        // produce random location for each vertex
        for (int i = 0; i < nodes; i++){
            graph->vertexList[i].x = rand_num();
            graph->vertexList[i].y = rand_num();
            graph->vertexList[i].z = rand_num();
            graph->vertexList[i].w = rand_num();
        }

        int counter = 0;
        for (int i = 0; i <= nodes; i++){
            for (int j = (i+1); j < nodes; j++){
                graph->edges[counter] = sqrt( pow((graph->vertexList[i].x - graph->vertexList[j].x), 2)  +  pow((graph->vertexList[i].y - graph->vertexList[j].y), 2) + pow((graph->vertexList[i].z - graph->vertexList[j].z), 2) + pow((graph->vertexList[i].w - graph->vertexList[j].w), 2) );
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
    free(graph->vertexList);
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

//List has length completeGraph->(numNodes - 1)
//Returns list of edgesMaps for each edge connecting to v
edgeMap *getEdgesToVertex(completeGraph *g, vertex *v) {

    edgeMap *mapList = calloc(g->numNodes - 1, sizeof(edgeMap));
    if (!mapList) {
        printf("Memory error: failed to generate mapList for vertex %d.\n", v->vName);
        return NULL;
    }

    for(int i = 0; i < g->numNodes - 1; i++) {
        if (i != v->vName) {
            mapList[i].v = &g->vertexList[i];
            mapList[i].distance = getEdge(g, i, v->vName);
        }
    }
    return mapList;
}

// algorithm: given population, find MST
// given: heap structure, populated graph, 

int Prims(completeGraph *graph) {

    unsigned n = graph->numNodes;
    edgeMap* edges; 
    vertex *smallestVertex;

    // set of vertices, initially empty
    vertex **growingSet = calloc(n, sizeof(vertex *));

    minHeap *vertexHeap = createMinHeap(n);
    minHeapInsert(&graph->vertexList[0], vertexHeap);
    int firstTime = 1;
    unsigned counter = 0;
    while(vertexHeap->heapLen) {
        smallestVertex = minHeapDeleteMin(vertexHeap);

        // insert smallest Vertex into growing set
        growingSet[counter] = smallestVertex;

        // mark that the vertex is in the set S 
        smallestVertex->visited = 1; 
        if (firstTime) {
            firstTime = 0;
            smallestVertex->distanceToPrevVertex = 0;
        }

        edges = getEdgesToVertex(graph, smallestVertex);

        for (int i = 0; i < (n-1); i++) {
            if (edges[i].v->visited) {
                break;
            }

            else {
                if(edges[i].v->distanceToPrevVertex == INFINITY){
                    minHeapInsert(edges[i].v, vertexHeap);
                }

                if (edges[i].distance < edges[i].v->distanceToPrevVertex) {
                    edges[i].v->distanceToPrevVertex = edges[i].distance;
                    edges[i].v->prevVertex = smallestVertex;
                }
            }

        }
        free(edges);
        heapify(vertexHeap);
        counter++;
    }
    return 0;
    
}
