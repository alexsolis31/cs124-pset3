randmst: randmst.c completeGraph.c minHeap.c
	gcc -o randmst randmst.c completeGraph.c minHeap.c -I . -DNDEBUG -O3 -std=gnu99 -lm

debug: randmst.c completeGraph.c minHeap.c
	gcc -o randmst randmst.c completeGraph.c minHeap.c -I . -O0 -std=gnu99 -lm

heapTest: heapTest.c minHeap.c completeGraph.c
	gcc -o heapTest heapTest.c minHeap.c completeGraph.c -I . -O0 -std=gnu99 -lm

clean:
	rm randmst
	rm heapTest

prims: prims.c minHeap.c completeGraph.c
	gcc -o prims prims.c minHeap.c completeGraph.c -I . -O0 -std=gnu99 -lm

primsTest: primsTest.c prims.c minHeap.c completeGraph.c
	gcc -o primsTest primsTest.c prims.c minHeap.c completeGraph.c -I . -O0 -std=gnu99 -lm
