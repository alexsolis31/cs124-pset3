#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "completeGraph.h"
#include "minHeap.h"
#include <time.h>

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