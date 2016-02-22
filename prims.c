#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "completeGraph.h"
#include "minHeap.h"
#include <time.h>

// algorithm: given population, find MST
// given: heap structure, populated graph, 

int Prims(completeGraph *graph){

	n = graph->numNodes
	edgeMap* edges; 

	// create the minHeap and initialize with all the vertices
	minHeap vertexHeap = genMinHeapFromList(graph->vertexList, n, n, 1);

	// set of vertices, initially empty
	vertex* growingSet = calloc(n, sizeof(vertex));

	minHeap* vertexHeap = createMinHeap(n);
	mimHeapInsert(graph->vertexList[0], vertexHeap);

	while(vertexHeap->heapLen){
		smallestVertex = minHeapDeleteMin(vertexHeap);

		// insert smallest Vertex into growing set
		smallestVertex = growingSet[i] ;

		// mark that the vertex is in the set S 
		graph->vertexList->visited = 1; 

		edges = getEdgesToVertex(graph, smallestVertex);

		for (int i = 0; i <= (n-1); i++){
			if (graph->vertexList[i]->visited){
				break;
			}

			else {
				if(graph->vertexList[i]->distance == INFINITY){
					minHeapInsert(graph->vertexList[i], vertexHeap);
				}

				if (edges->distance < edges->vertex->distanceToPrevVertex){
					vertex->distanceToPrevVertex = edges->distance
					edges->vertex->prevVertex = smallestVertex;
				}
			}

		}

		heapify(vertexHeap);
	
	
}