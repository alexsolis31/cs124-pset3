#ifndef _minHeap_h
#define _minHeap_h

typedef struct vertex {
    unsigned vNum;
    vertex *prevVertex;
    float distance;

} vertex;

//For float payload
typedef stuct minHeap {

    heapNode **vertex;
    unsigned maxLen;
    unsigned heapLen;

} minHeap;


//Creates a minHeap of maximum length maxLen
minHeap *createMinHeap(unsigned maxLen);

//Destroys a minHeap
void destroyMinHeap(minHeap *heap);

//Inserts payload into the heap. Returns 1 if heap is full
int minHeapInsert(vertex *payload, minHeap *heap);

//Pops smallest value off heap and returns it.
vertex *minHeapDeleteMin(minHeap *heap);


#endif
