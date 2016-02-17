#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "completeTree.h"


//Allocates a completeTree with numNodes nodes.
//Returns NULL on error
completeTree *genCompleteTree(unsigned numNodes) {

    //for compile purposes
    completeTree *tree = calloc(1, sizeof(completeTree));
    if (!tree) {
        printf("Allocating tree structure failed.\n");
        return NULL;
    }

    tree->numNodes = numNodes;
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

    //for compile purposes
    (void) tree;

}

//Changes the edge value for the edge connecting from and to.
//Returns 1 on error
int updateEdge(completeTree *tree, unsigned from, unsigned to, float val) {

    //for compile purposes
    (void) tree, (void) from, (void) to, (void) val;
    return 1;
}

//Returns the edge value for the edge connecting from and to.
//Returns 0 on error
float getEdge(completeTree *tree, unsigned from, unsigned to) {

    //for compile purposes
    (void) tree, (void) from, (void) to;
    return 0;
}
