objects = main.o sllist.o
publicPath = ../public
test : $(objects)
	gcc -o test $(objects)

main.o : main.c header.h
	gcc -c -g main.c

sllist.o : $(publicPath)/link-list/sllist.c $(publicPath)/link-list/sllist.h $(publicPath)/link-list/sllist_elem_type.h
	gcc -c -g $(publicPath)/link-list/sllist.c

clean-all :
	rm test $(objects)

clean-o :
	rm $(objects)