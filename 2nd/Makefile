objects = main.o functions.o stack.o
calc.exe : $(objects)
	gcc -g -o calc.exe $(objects)

main.o : main.c functions.h ./stack/stack.h
	gcc -c main.c

functions.o : functions.c functions.h ./stack/stack.h
	gcc -c functions.c

stack.o : ./stack/stack.c ./stack/stack.h
	gcc -c ./stack/stack.c

clean-all : 
	rm calc.exe $(objects)
clean-o :
	rm $(objects)