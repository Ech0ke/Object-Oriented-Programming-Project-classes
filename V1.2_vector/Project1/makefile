vector: main.o functions.o create_file.o file.o manual.o 
	g++ -m64 -o main main.o file.o functions.o create_file.o  manual.o -O2 
main:
	g++ -c main.cpp
functions:
	g++ -c functions.cpp
create_file:
	g++ -c create_file.cpp
file:
	g++ -c file.cpp
manual:
	g++ -c manual.cpp
clean:
	del *.o main.exe