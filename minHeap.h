#ifndef _minHeap_h
#define _minHeap_h

//For float payload
typedef stuct minHeap {

    float *list;
    unsigned listLen;
    unsigned heapLen;

} minHeap;

//Creates a minHeap of maximum length maxLen
minHeap *createMinHeap(unsigned maxLen);
//Destroys a minHeap
void destroyMinHeap(minHeap *heap);

//Inserts payload into the heap. Returns 1 if heap is full
int minHeapInsert(float payload, minHeap *heap);
//Pops smallest value off heap and returns it.
float minHeapDeleteMin(minHeap *heap);






#endif
