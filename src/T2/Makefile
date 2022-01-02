output: main.o command_line_ui.o
	gcc -o output main.o command_line_ui.o

main.o: gameplay_functions.h structures.h
	gcc -c main.c

command_line_ui.o: gameplay_functions.h structures.h
	gcc -c command_line_ui.c

clean:
	rm *.o output

