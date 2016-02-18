#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "completeGraph.h"


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

    //for compile purposes
    (void) graph, (void) dimension;
    return 1;

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
    else {
        lowN_offset = ((((numNodes - 1) * numNodes) / 2) -
                       (((numNodes - lowN - 1) * (numNodes - lowN - 2)) / 2));
    }
    return lowN_offset + highN_offset;
}  //motivating logic below
//let's see: find beginning of "lowN" "zone"
//offset into zone is highN - lowN - 1
//so our function looks like: ((zoneCalc) + highN - lowN - 1)

//how can we get beginning of lowN?
/*
0 --> 0
1 --> numNodes - 1
2 --> numNodes - 1 + numNodes - 2
3 --> numNodes - 1 + numNodes - 2 + numNodes - 3
......

sum from (numNodes - low to numNodes - 1) with 0 if 0.
(((numNodes - 1) * numNodes) / 2 - ((numNodes - i - 1)*(numNodes - i - 2)) / 2)


*/
//  sum from (numNodes - lowN) to (numNodes - 1)


//Returns the weight of the MST for the graph. Returns 0 on error.
float findMST_Weight(completeGraph *graph) {
    (void) graph;
    return 0;
}
