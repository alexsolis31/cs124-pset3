#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "minHeap.h"

//Declare our heap helpers, but privately
void shift_down(vertex **list, unsigned start, unsigned end);
void shift_up(vertex **list, unsigned start, unsigned end);
void swap(vertex **a, vertex **b);

//Creates a minHeap of maximum length maxLen.
//Returns NULL on error
minHeap *createMinHeap(unsigned maxLen) {

    assert(maxLen > 0);

    minHeap *heap = calloc(1, sizeof(minHeap));
    if (!heap) {
        printf("Memory error: could not allocate heap struct.\n");
        return NULL;
    }

    heap->vertexList = calloc(maxLen, sizeof(vertex *));
    if (!heap->vertexList) {
        printf("Memory error: could not allocate heap list of lenght %d.\n", maxLen);
        free(heap);
        return NULL;
    }

    heap->heapLen = 0;
    heap->maxLen = maxLen;
    return heap;
}

//Copies addresses of contents of list into a fresh heap then heapifies
//Returns NULL on error
minHeap *genMinHeapFromList(vertex *list, unsigned listLen, unsigned maxHeapLen, int shouldHeapify) {

    minHeap *heap = createMinHeap(maxHeapLen);
    if (!heap) return NULL;

    for (unsigned i = 0; i < listLen; i++) {
        heap->vertexList[i] = &(list[i]);
    }
    heap->heapLen = listLen;
    if (shouldHeapify) {
        heapify(heap);
    }
    return heap;
}


//Destroys a minHeap
void destroyMinHeap(minHeap *heap) {

    assert(heap);

    free(heap->vertexList);
    free(heap);
}


//Should not be used but keep around just in case
//Inserts payload into the heap. Returns 1 if heap is full
int minHeapInsert(vertex *payload, minHeap *heap) {

    assert(heap);
    assert(payload);
    assert(heap->heapLen != heap->maxLen);

    heap->vertexList[heap->heapLen] = payload;
    heap->heapLen++;
    shift_up(heap->vertexList, 0, heap->heapLen - 1);
    return 0;


}


//Pops smallest value off heap and returns it.
vertex *minHeapDeleteMin(minHeap *heap) {

    assert(heap->heapLen);

    vertex *ret = heap->vertexList[0];
    heap->vertexList[0] = heap->vertexList[heap->heapLen - 1];
    heap->vertexList[heap->heapLen - 1] = NULL;
    heap->heapLen--;

    if (heap->heapLen == 0) return ret;

    shift_down(heap->vertexList, 0, heap->heapLen - 1);
    return ret;
}



//HEAP HELPERS

//Make list[start...end]; a valid heap assuming
//List[start+1...end] is.
void shift_down(vertex **list, unsigned start, unsigned end) {
//look at start and its children. Swap start with
//larger of two children. May need to swap down from
//There as well if this breaks the heap property for the
//Sub heap
	unsigned cur_root = start;
	unsigned node_to_swap;
	//This checks if root can have children
	while(cur_root * 2 + 1 <= end) {

		unsigned child = cur_root * 2 + 1;
		node_to_swap = cur_root;

		if (list[cur_root]->distanceToPrevVertex > list[child]->distanceToPrevVertex) {
			node_to_swap = child;
		}
		//Handle right side
		if (list[child + 1] && child + 1 <= end && list[node_to_swap]->distanceToPrevVertex > list[child + 1]->distanceToPrevVertex) {
			node_to_swap = child + 1;
		}
		if (node_to_swap == cur_root) {
			break;
		}
		else {
			swap(&list[cur_root], &list[node_to_swap]);
			cur_root = node_to_swap;
		}
	}
}

void shift_up(vertex **list, unsigned start, unsigned end) {

    if (end == start) return;
    int parent = (end - 1) / 2;

    if (list[parent]->distanceToPrevVertex > list[end]->distanceToPrevVertex) {
        swap(&list[parent], &list[end]);
        shift_up(list, start, parent);
    }
}

void heapify(minHeap *heap) {

    vertex **list = heap->vertexList;
    unsigned length = heap->heapLen;
    if (length == 1 || length == 0) {
        return;
    }

	//Find index of lowest possible parent node
	int start = (length - 2) / 2;
	while(start >= 0) {
		shift_down(list, start, length - 1);
		start--;
	}
}

void swap(vertex **a, vertex **b) {
    vertex *temp = *a;
    *a = *b;
    *b = temp;
}
