#
#	Author	: Joe Nahm
#	Email	: joenahm@yeah.net
#
objects = main.o bt.o functions.o
bt : $(objects)
	gcc -o bt $(objects)

main.o : main.c ./binary-tree/bt.h functions.h
	gcc -c -g main.c

bt.o : ./binary-tree/bt.c ./binary-tree/bt.h ./binary-tree/bt_elem_type.h
	gcc -c -g ./binary-tree/bt.c

functions.o : functions.c functions.h
	gcc -c -g functions.c

clean-all : 
	rm bt $(objects)

clean-o :
	rm $(objects)