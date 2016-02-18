#include <stdio.h>
#include <stdlib.h>
#include "completeGraph.h"


int main (int argc, char **argv) {

    //parse inputs
    if (argc != 5) {
        printf("Command line input should be in the form \
randmst flag numPoints numTrials dimension.\n");
                return 1;
    }
    unsigned numPoints = strtoul(argv[2], NULL, 10);
    unsigned numTrials = strtoul(argv[3], NULL, 10);
    unsigned dimension = strtoul(argv[4], NULL, 10);

    if (numPoints == 0) {
        printf("The second argument should be a positive integer.\n");
        return 1;
    }
    if (numTrials == 0) {
        printf("The third argument should be a positive integer.\n");
        return 1;
    }
    if (dimension != 0  && dimension != 2 && dimension != 3 && dimension !=4) {
        printf("The fourth argument must be 0, 2, 3, or 4.\n");
        return 1;
    }

    //get results array
    float *treeWeights = calloc((size_t) numTrials, sizeof(float));
    if (treeWeights == NULL) {
        printf("Memory error: treeWeights array allocation failed.\n");
        return 1;
    }
    //do each trial
    completeGraph *graph = genCompleteGraph(numPoints);
    if(graph == NULL) {
        printf("Memory error: could not generate Graph\n");
        free(treeWeights);
        return 1;
    }

    int err;
    float curWeight;
    for(unsigned i = 0; i < numTrials; i++) {

        //reinitialize graph
        err = eucPopulateCompleteGraph(graph, dimension);
        if (err) {
            printf("Error: could not populate Graph on %dth trial.\n", i);
            destroyCompleteGraph(graph);
            free(treeWeights);
            return 1;
        }

        //Find the MST weight and clean up
        curWeight = findMST_Weight(graph);
        if (curWeight == 0) {
            printf("Error: could not find MST weight on %dth trial.\n", i);
            destroyCompleteGraph(graph);
            free(treeWeights);
            return 1;
        }
        treeWeights[i] = curWeight;
    }

    //find the average MST weight
    float averageWeight = 0;
    for (unsigned i = 0; i < numTrials; i++) {
        averageWeight += treeWeights[i];
    }
    averageWeight = averageWeight / (float) numTrials;

    //output: average(weight) numPoints numTrials dimension
    printf("%f %d %d %d\n", averageWeight, numPoints, numTrials, dimension);


    //appropriate response


}
