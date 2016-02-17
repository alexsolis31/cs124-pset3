#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "completeTree.h"

#define CALC_INDEX(lowN, highN, nodes)    (0) //todo


//Allocates a completeTree with numNodes nodes.
//Returns NULL on error
completeTree *genCompleteTree(unsigned numNodes) {

    assert(numNodes != 0);

    //allocate tree structure and error handle
    completeTree *tree = calloc(1, sizeof(completeTree));
    if (!tree) {
        printf("Allocating tree structure failed.\n");
        return NULL;
    }

    tree->numNodes = numNodes;
    /* Allocate edge array and error handle
       Since we have complete trees, store each edge once, and use the fact
       that 1 + 2 + ... + n = (n + 1) * n / 2 to determine array len with
       n = numNodes - 1 */
    tree->edges = calloc(((numNodes - 1) * numNodes) / 2, sizeof(float));
    if (!tree->edges) {
        printf("Allocating tree with number of nodes: %d failed.\n", numNodes);
        free(tree);
        return NULL;
    }

    return tree;
}

//Randomly populates tree by randomly placing nodes in dimension-cube
//and assigning edges by Euclidean distance.
//Returns 1 on error.
int eucPopulateCompleteTree(completeTree *tree, unsigned dimension) {

    //for compile purposes
    (void) tree, (void) dimension;
    return 1;

}

//Frees all memeory associated with a completeTree
void destroyCompleteTree(completeTree *tree) {

    assert(tree);
    free(tree->edges);
    free(tree);
}

//Changes the edge value for the edge connecting from and to.
//Returns 1 on error
int updateEdge(completeTree *tree, unsigned from, unsigned to, float val) {

    assert(from != to); //or maybe just return 1 and print error?
    assert(from < tree->numNodes);
    assert(to < tree->numNodes);
    assert(val >= 0);

    if (from < to) {
        tree->edges[CALC_INDEX(from, to, tree->numNodes)] = val;
    }
    else {
        tree->edges[CALC_INDEX(to, from, tree->numNodes)] = val;
    }
    return 0;
}

//Returns the edge value for the edge connecting from and to.
//Returns 0 on error
float getEdge(completeTree *tree, unsigned from, unsigned to) {

    assert(from != to); //or maybe just return 0 and print error?
    assert(from < tree->numNodes);
    assert(to < tree->numNodes);

    if (from < to) {
        return tree->edges[CALC_INDEX(from, to, tree->numNodes)];
    }
    else {
        return tree->edges[CALC_INDEX(to, from, tree->numNodes)];
    }
}
