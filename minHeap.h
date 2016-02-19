#ifndef _minHeap_h
#define _minHeap_h


typedef stuct minHeap {

} minHeap;

minHeap *createMinHeap(unsigned heapLen);
void destroyMinHeap(minHeap *heap);

int minHeapInsert(float payload);

float minHeapDeleteMin(void);






#endif
