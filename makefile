randmst: randmst.c completeGraph.c
	gcc -o randmst randmst.c completeGraph.c -I . -DNDEBUG

debug: randmst.c completeGraph.c
	gcc -o randmst randmst.c completeGraph.c -I .

clean:
	rm randmst
