output: main.o evaluation.o map.o miscellaneous.o movement.o placement.o command_line_ui.o
	gcc -o output main.o evaluation.o map.o miscellaneous.o movement.o placement.o command_line_ui.o
	
main.o: gameplay_functions.h structures.h
	gcc -c main.c

command_line_ui.o: gameplay_functions.h structures.h
	gcc -c command_line_ui.c

map.o: gameplay_functions.h structures.h
	gcc -c map.c

miscellaneous.o: gameplay_functions.h structures.h
	gcc -c miscellaneous.c

movement.o: gameplay_functions.h structures.h
	gcc -c movement.c

placement.o: gameplay_functions.h structures.h
	gcc -c placement.c

clean:
	rm *.o output

