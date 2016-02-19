randmst: randmst.c completeGraph.c minHeap.c
	gcc -o randmst randmst.c completeGraph.c minHeap.c -I . -DNDEBUG

debug: randmst.c completeGraph.c minHeap.c
	gcc -o randmst randmst.c completeGraph.c minHeap.c -I .

clean:
	rm randmst
