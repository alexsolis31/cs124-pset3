#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "completeGraph.h"
#include <time.h>

unsigned rand_calls = 0;
unsigned seeded_once = 0;

typedef struct {
    float x; 
    float y;
} coordinate;

float rand_num()
{
	if (!seeded_once) {
		srand(time(NULL));
		seeded_once = 1;
	}
	if (rand_calls > 1000) {
		srand(clock() + time(NULL));
		rand_calls = 0;
	}
	rand_calls++;
	return rand() / (double)(RAND_MAX);
	
}


int main (int argc, char **argv) {

    int numNodes = 4; 
    int num_edges = (numNodes*(numNodes-1))/2; 
    coordinate vertices [numNodes]; 


    float *graph_edges = calloc(((numNodes - 1) * numNodes) / 2, sizeof(float));
    if (!graph_edges) {
        printf("Allocating graph with number of nodes: %d failed.\n", numNodes);
        free(graph_edges);
    }


  // produce random location for each vertex
    for (int i = 0; i < numNodes; i++){
        vertices[i].x = rand_num();
        vertices[i].y = rand_num(); 

    }

    int counter = 0; 
    for (int i = 0; i <= numNodes; i++){
        for (int j = i+1; j < numNodes; j++){
            

            graph_edges[counter] = sqrt( pow((vertices[i].x - vertices[j].x), 2)  +  pow((vertices[i].y - vertices[j].x), 2)); 

            counter++; 

        }
    }

    printf("%f\n", graph_edges[0]); 
    printf("%f\n", graph_edges[1]);
   	printf("%f\n", graph_edges[2]); 
   	printf("%f\n", graph_edges[3]);  

   	printf("Vertices:" );

   	for (int i = 0; i <= numNodes; i++){
   		printf("%f ", vertices[i].x); 
   		printf("%f\n", vertices[i].y); 

   	}



}