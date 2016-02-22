#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "completeGraph.h"
#include "minHeap.h"
#include <time.h>



int main (void){

// **************************************************************
// case 1: standard 5 node case 
// **************************************************************
unsigned nodes1 = 5; 
completeGraph *testGraph1 = genCompleteGraph(nodes1);

vertex a = {0, NULL, INFINITY, 0, 0, 0, 0, 0};
vertex b = {1, NULL, INFINITY, 0, 0, 0, 0, 0};
vertex c = {2, NULL, INFINITY, 0, 0, 0, 0, 0};
vertex d = {3, NULL, INFINITY, 0, 0, 0, 0, 0};
vertex e = {4, NULL, INFINITY, 0, 0, 0, 0, 0};


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

// **************************************************************
// case 2:  numNodes = 1
// **************************************************************

completeGraph *testGraph2 = genCompleteGraph(1);
vertex f = {0, NULL, INFINITY, 0, 0, 0, 0, 0};
float edgeList2[1] = {0};


testGraph2->edges = edgeList2; 
testGraph2->vertexList[0] = f; 
testGraph2->numNodes = 1; 

float weight2 = findMST_Weight(testGraph2);
printf("The weight of the Test Graph: %f\n", weight2);

// **************************************************************
// case 3: some edges are the same 
// **************************************************************
unsigned nodes3 = 5; 
completeGraph *testGraph3 = genCompleteGraph(nodes3);

vertex g = {0, NULL, INFINITY, 0, 0, 0, 0, 0};
vertex h = {1, NULL, INFINITY, 0, 0, 0, 0, 0};
vertex i = {2, NULL, INFINITY, 0, 0, 0, 0, 0};
vertex j = {3, NULL, INFINITY, 0, 0, 0, 0, 0};
vertex k = {4, NULL, INFINITY, 0, 0, 0, 0, 0};


float edgeList3[10] = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100};


testGraph3->edges = edgeList3; 

testGraph3->vertexList[0] = g; 
testGraph3->vertexList[1] = h; 
testGraph3->vertexList[2] = i; 
testGraph3->vertexList[3] = j; 
testGraph3->vertexList[4] = k; 

testGraph3->numNodes = 5; 


float weight3 = findMST_Weight(testGraph3);


 printf("The weight of the Test Graph: %f\n", weight3);

// **************************************************************
// case 4: some edges are the same 
// **************************************************************

unsigned nodes4 = 4; 
completeGraph *testGraph4 = genCompleteGraph(nodes4);

vertex t = {0, NULL, INFINITY, 0, 0, 0, 0, 0};
vertex u = {1, NULL, INFINITY, 0, 0, 0, 0, 0};
vertex v = {2, NULL, INFINITY, 0, 0, 0, 0, 0};
vertex w = {3, NULL, INFINITY, 0, 0, 0, 0, 0};

float edgeList4[6] = {3, 3, 10, 100, 3, 2};


testGraph4->edges = edgeList4; 

testGraph4->vertexList[0] = g; 
testGraph4->vertexList[1] = h; 
testGraph4->vertexList[2] = i; 
testGraph4->vertexList[3] = j; 

testGraph4->numNodes = 4; 


float weight4 = findMST_Weight(testGraph4);


 printf("The weight of the Test Graph: %f\n", weight4);

}

