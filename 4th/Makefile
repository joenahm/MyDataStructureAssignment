#
#	Author	: Joe Nahm
#	Email	: joenahm@yeah.net
#
objects = main.o dg.o queue.o
bfst : $(objects)
	gcc -o bfst $(objects)

main.o : main.c ./digraph/dg.h
	gcc -c -g main.c

dg.o : ./digraph/dg.c ./digraph/dg.h
	gcc -c -g ./digraph/dg.c

queue.o : ./queue/queue.c ./queue/queue.h
	gcc -c -g ./queue/queue.c

clean-all :
	rm bfst $(objects)

clean-o :
	rm $(objects)