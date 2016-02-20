#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//Declare our heap helpers, but privately
void shift_down(heapNode **list, unsigned start, unsigned end);
void heapify(heapNode **list, unsigned length);

//Creates a minHeap of maximum length maxLen.
//Returns NULL on error
minHeap *createMinHeap(unsigned maxLen) {

    assert(maxLen > 0);

    heap = calloc(1, sizeof(minHeap));
    if (!heap) {
        printf("Memory error: could not allocate heap struct.\n");
        return NULL;
    }

    heap->list = calloc(maxLen, sizeof(heapNode *));
    if (!heap->list) {
        printf("Memory error: could not allocate heap list of lenght %d.\n", maxLen);
        free(heap);
        return NULL;
    }

    heap->heapLen = 0;
    heap->maxLen = maxLen;
    return heap;
}


//Destroys a minHeap
void destroyMinHeap(minHeap *heap) {

    assert(heap);

    free(heap->list);
    free(heap);
}



//Inserts payload into the heap. Returns 1 if heap is full
int minHeapInsert(vertex *payload, minHeap *heap) {


}


//Pops smallest value off heap and returns it.
vertex *minHeapDeleteMin(minHeap *heap) {


}



//HEAP HELPERS

//Make list[start...end]; a valid heap assuming
//List[start+1...end] is.
void shift_down(vertex **list, unsigned start, unsigned end) {
//look at start and its children. Swap start with
//larger of two children. May need to swap down from
//There as well if this breaks the heap property for the
//Sub heap
	int cur_root = start;
	int node_to_swap;
	//This checks if root can have children
	while(cur_root * 2 + 1 <= end) {

		int child = cur_root * 2 + 1;
		node_to_swap = cur_root;

		if (list[cur_root] < list[child]) {
			node_to_swap = child;
		}
		//Handle right side
		if (child + 1 <= end && list[node_to_swap] < list[child + 1]) {
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

void heapify(vertex **list, unsigned length) {
	//Find index of lowest possible parent node
	int start = (length - 2) / 2;
	while(start >= 0) {
		shift_down(list, start, length - 1);
		start--;
	}
}
