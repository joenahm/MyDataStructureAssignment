objects = main.o stack.o
publicPath = ../public
test : $(objects)
	gcc -o test $(objects)

main.o : main.c header.h
	gcc -c -g main.c

stack.o : $(publicPath)/stack/stack.c $(publicPath)/stack/stack.h $(publicPath)/stack/stack_elem_type.h $(publicPath)/stack/stack_storage.h
	gcc -c -g $(publicPath)/stack/stack.c

clean-all :
	rm test $(objects)

clean-o :
	rm $(objects)