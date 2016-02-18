#ifndef _completeGraph_h
#define _completeGraph_h

typedef struct completeGraph {

    float *edges;
    unsigned numNodes; //len(edges) = (num_nodes)(num_nodes - 1) / 2

} completeGraph;

//Allocates a completeGraph with numNodes nodes.
//Returns NULL on error
completeGraph *genCompleteGraph(unsigned numNodes);

//Randomly populates graph by randomly placing nodes in dimension-cube
//and assigning edges by Euclidean distance.
//Returns 1 on error.
int eucPopulateCompleteGraph(completeGraph *graph, unsigned dimension);

//Frees all memeory associated with a completeGraph
void destroyCompleteGraph(completeGraph *graph);

//Changes the edge value for the edge connecting from and to.
//Returns 1 on error
static inline int updateEdge(completeGraph *graph, unsigned from,
                             unsigned to, float val);

//Returns the edge value for the edge connecting from and to.
//Returns 0 on error
static inline float getEdge(completeGraph *graph, unsigned from, unsigned to);

static inline unsigned calcIndex(unsigned lowN, unsigned highN,
                                  unsigned numNodes);

//Returns the weight of the MST for the graph. Returns 0 on error.
float findMST_Weight(completeGraph *graph);

// generate a random number between [0,1]
static inline float rand_num();

#endif
