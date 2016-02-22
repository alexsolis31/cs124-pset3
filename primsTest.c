#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "completeGraph.h"
#include "minHeap.h"
#include <time.h>



int main (void){


// standard 5 node case 
unsigned nodes1 = 5; 
completeGraph *testGraph1 = genCompleteGraph(nodes1);

vertex a = {0, NULL, INFINITY, 0, 0, 0, 0, 0};
vertex b = {0, NULL, INFINITY, 0, 0, 0, 0, 0};
vertex c = {0, NULL, INFINITY, 0, 0, 0, 0, 0};
vertex d = {0, NULL, INFINITY, 0, 0, 0, 0, 0};
vertex e = {0, NULL, INFINITY, 0, 0, 0, 0, 0};

float edgeList1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

testGraph1->edges = edgeList1; 

testGraph1->vertexList[0] = a; 
testGraph1->vertexList[1] = b; 
testGraph1->vertexList[2] = c; 
testGraph1->vertexList[3] = d; 
testGraph1->vertexList[4] = e; 

testGraph1->numNodes = 5; 


float weight1 = findMST_Weight(testGraph1);
printf("The weight of the Test Graph: %f\n", weight1);

// numNodes = 1
completeGraph *testGraph2 = genCompleteGraph(1);
vertex f = {0, NULL, INFINITY, 0, 0, 0, 0, 0};

float edgeList2[1] = {0};
testGraph2->edges = edgeList2; 
testGraph2->vertexList[0] = f; 
testGraph2->numNodes = 1; 
float weight2 = findMST_Weight(testGraph2);
printf("The weight of the Test Graph: %f\n", weight2);


}

