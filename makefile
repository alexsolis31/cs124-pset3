randmst: randmst.c completeTree.c
	gcc -o randmst randmst.c completeTree.c -I . -DNDEBUG

debug: randmst.c completeTree.c
	gcc -o randmst randmst.c completeTree.c -I .
