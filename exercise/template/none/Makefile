objects = main.o
test : $(objects)
	gcc -o test $(objects)

main.o : main.c header.h
	gcc -c -g main.c

clean-all :
	rm test $(objects)

clean-o :
	rm $(objects)
