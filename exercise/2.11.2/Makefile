objects = main.o sqlist.o
test : $(objects)
	gcc -o test $(objects)

main.o : main.c header.h
	gcc -c -g main.c

sqlist.o : ./sequence-list/sqlist.c ./sequence-list/sqlist.h ./sequence-list/sqlist_elem_type.h
	gcc -c -g ./sequence-list/sqlist.c

clean-all :
	rm test $(objects)

clean-o :
	rm $(objects)