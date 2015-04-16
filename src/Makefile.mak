$FLAGS = std=gnu99
$DEBUG = -g
$CC = gcc

Elevator.o: main.c ESS.h 
	$(CC) -c main.c $(FLAGS) $(DEBUG)
	
Elev64: Elevator.o ESS64.o
	$(CC) -o Elev_AMD_x64 Elevator.o ESS64.o $(FLAGS) $(DEBUG)
	
Elev32: Elevator.o ESS.32.o
	$(CC) -o Elev_i386 Elevator.o ESS32.o $(FLAGS) $(DEBUG)
	
all:
	make Elev64 && make Elev32