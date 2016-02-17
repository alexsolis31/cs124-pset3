#ifndef _completeTree_h
#define _completeTree_h

typedef struct completeTree {

    float *edges;
    unsigned numNodes; //len(edges) = (num_nodes)(num_nodes - 1) / 2

} completeTree;

//Allocates a completeTree with numNodes nodes.
//Returns NULL on error
completeTree *genCompleteTree(unsigned numNodes);

//Randomly populates tree by randomly placing nodes in dimension-cube
//and assigning edges by Euclidean distance.
//Returns 1 on error.
int eucPopulateCompleteTree(completeTree *tree, unsigned dimension);

//Frees all memeory associated with a completeTree
void destroyCompleteTree(completeTree *tree);

//Changes the edge value for the edge connecting from and to.
//Returns 1 on error
int updateEdge(completeTree *tree, unsigned from, unsigned to, float val);

//Returns the edge value for the edge connecting from and to.
//Returns 0 on error
float getEdge(completeTree *tree, unsigned from, unsigned to);

static inline unsigned calc_index(unsigned lowN, unsigned highN,
                                  unsigned numNodes);

#endif
