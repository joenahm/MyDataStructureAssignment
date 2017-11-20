#
#	Author	: Joe Nahm
#	Email	: joenahm@yeah.net
#
objects = main.o functions.o
bfst : $(objects)
	gcc -o bfst $(objects)

main.o : main.c functions.h
	gcc -c -g main.c

functions.o : functions.c functions.h
	gcc -c -g functions.c


clean-all :
	rm bfst $(objects)

clean-o :
	rm $(objects)