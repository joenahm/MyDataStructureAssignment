objects = main.o sqlist.o
publicPath = ../public
test : $(objects)
	gcc -o test $(objects)

main.o : main.c header.h
	gcc -c -g main.c

sqlist.o : $(publicPath)/sequence-list/sqlist.c $(publicPath)/sequence-list/sqlist.h $(publicPath)/sequence-list/sqlist_elem_type.h
	gcc -c -g $(publicPath)/sequence-list/sqlist.c

clean-all :
	rm test $(objects)

clean-o :
	rm $(objects)