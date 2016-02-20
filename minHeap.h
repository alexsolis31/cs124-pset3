#ifndef _minHeap_h
#define _minHeap_h


//For float payload
typedef stuct minHeap {
    //pointer to array of vertex pointers
    heapNode **vertexList;
    unsigned maxLen;
    unsigned heapLen;

} minHeap;


//Creates a minHeap of maximum length maxLen
minHeap *createMinHeap(unsigned maxLen);

//Copies addresses of contents of list into a fresh heap then heapifies
//Returns NULL on error
minHeap *genMinHeapFromList(vertex *list, unsigned listLen);

//Destroys a minHeap
void destroyMinHeap(minHeap *heap);

//Inserts payload into the heap. Returns 1 if heap is full
int minHeapInsert(vertex *payload, minHeap *heap);

//Pops smallest value off heap and returns it.
vertex *minHeapDeleteMin(minHeap *heap);


#endif
