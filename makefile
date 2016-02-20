randmst: randmst.c completeGraph.c minHeap.c
	gcc -o randmst randmst.c completeGraph.c minHeap.c -I . -DNDEBUG -O3

debug: randmst.c completeGraph.c minHeap.c
	gcc -o randmst randmst.c completeGraph.c minHeap.c -I . -O0

clean:
	rm randmst
