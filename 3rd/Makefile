#
#	Author	: Joe Nahm
#	Email	: joenahm@yeah.net
#
objects = main.o tbt.o functions.o stack.o
tbt : $(objects)
	gcc -o tbt $(objects)

main.o : main.c ./binary-tree/tbt.h functions.h
	gcc -c -g main.c

tbt.o : ./binary-tree/tbt.c ./binary-tree/tbt.h ./binary-tree/tbt_elem_type.h
	gcc -c -g ./binary-tree/tbt.c

functions.o : functions.c functions.h
	gcc -c -g functions.c

stack.o : ./stack/stack.c ./stack/stack.h ./stack/stack_elem_type.h
	gcc -c -g ./stack/stack.c
clean-all : 
	rm tbt $(objects)

clean-o :
	rm $(objects)