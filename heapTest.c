#include "minHeap.h"
#include <stdio.h>
#include <stdlib.h>

vertex a = {0, NULL, 1.23f, 0, 0, 0, 0, 0};

vertex b = {1, NULL, 1.15f, 0, 0, 0, 0, 0};

vertex c = {2, NULL, .97f, 0, 0, 0, 0, 0};

vertex d = {3, NULL, .88f, 0, 0, 0, 0, 0};

vertex e = {4, NULL, .76f, 0, 0, 0, 0, 0};

vertex f = {5, NULL, .65f, 0, 0, 0, 0, 0};

vertex g = {6, NULL, .54f, 0, 0, 0, 0, 0};

vertex h = {7, NULL, .43f, 0, 0, 0, 0, 0};

vertex k = {8, NULL, .21f, 0, 0, 0, 0, 0};

vertex j = {9, NULL, .11f, 0, 0, 0, 0, 0};

int hasHeapProp(minHeap *h) {

    if (h->heapLen == 1) {
        return 1;
    }
    int parent;
    for (int i = h->heapLen - 1; i >= 0; i--) {
        parent = (i - 1) / 2;
        if (h->vertexList[i]->distanceToPrevVertex < h->vertexList[parent]->distanceToPrevVertex) {
            return 0;
        }
    }
    return 1;

}

int main(void) {

    //Generate some vertex lists;
    vertex list1[10] = {a, b, c, d, e, f, g, h, k, j};
    vertex list2[9] = {e, f, b, g, c, d, h, k, a} ;
    vertex list3[1] = {a};
    vertex list4[5] = {d, a, j, b, g};
    vertex list5[6] = {a, j, b, k, c, h};
    vertex list6[8] = {j, k, h, g, f, e, d, c};

    //generate some heaps based on lists.
    minHeap *heap1 = genMinHeapFromList(list1, 10, 10, 1);
    minHeap *heap2 = genMinHeapFromList(list2, 9, 10, 1);
    minHeap *heap3 = genMinHeapFromList(list3, 1, 10, 1);
    minHeap *heap4 = genMinHeapFromList(list4, 5, 10, 1);
    minHeap *heap5 = genMinHeapFromList(list5, 6, 10, 1);
    minHeap *heap6 = genMinHeapFromList(list6, 8, 10, 1);

    //check heap property
    if (!hasHeapProp(heap1)) {
         printf("heap1 does not have prop after initial heapify\n");
         return 1;
    }
    if (!hasHeapProp(heap2)) {
         printf("heap2 does not have prop after initial heapify\n");
         return 1;
    }
    if (!hasHeapProp(heap3)) {
         printf("heap3 does not have prop after initial heapify\n");
         return 1;
    }
    if (!hasHeapProp(heap4)) {
         printf("heap4 does not have prop after initial heapify\n");
         return 2;
    }
    if (!hasHeapProp(heap5)) {
         printf("heap5 does not have prop after initial heapify\n");
         return 1;
    }
    if (!hasHeapProp(heap6)) {
         printf("heap6 does not have prop after initial heapify\n");
         return 1;
    }
    printf("First round success. Heaps get initialized properly\n");

    //delete a few elements
    vertex *deleted;
    deleted = minHeapDeleteMin(heap1);
    deleted = minHeapDeleteMin(heap1);
    deleted = minHeapDeleteMin(heap1);
    deleted = minHeapDeleteMin(heap2);
    deleted = minHeapDeleteMin(heap2);
    deleted = minHeapDeleteMin(heap2);
    deleted = minHeapDeleteMin(heap3);
    deleted = minHeapDeleteMin(heap4);
    deleted = minHeapDeleteMin(heap5);
    deleted = minHeapDeleteMin(heap5);
    deleted = minHeapDeleteMin(heap5);
    deleted = minHeapDeleteMin(heap1);
    deleted = minHeapDeleteMin(heap6);
    deleted = minHeapDeleteMin(heap6);
    deleted = minHeapDeleteMin(heap6);
    deleted = minHeapDeleteMin(heap6);
    deleted = minHeapDeleteMin(heap6);

    //check heap property
    if (!hasHeapProp(heap1)) {
         printf("heap1 does not have prop after deleting\n");
         return 1;
    }
    if (!hasHeapProp(heap2)) {
         printf("heap2 does not have prop after deleting\n");
         return 1;
    }
    if (!hasHeapProp(heap3)) {
         printf("heap3 does not have prop after deleting\n");
         return 1;
    }
    if (!hasHeapProp(heap4)) {
         printf("heap4 does not have prop after deleting\n");
         return 2;
    }
    if (!hasHeapProp(heap5)) {
         printf("heap5 does not have prop after deleting\n");
         return 1;
    }
    if (!hasHeapProp(heap6)) {
         printf("heap6 does not have prop after deleting\n");
         return 1;
    }
    printf("Second round success. Heaps have deleteMin working\n");

    //insert a few heap elements

    //check heap property

}
