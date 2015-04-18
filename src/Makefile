FLAGS = -std=gnu99
DEBUG = -g
X86 = -m32
CC = gcc

default: all

Elevator_i386.o: main.c ESS.h
	$(CC) -c main.c -o Elevator_i386.o $(FLAGS) $(DEBUG) $(x86)

Elevator_x64.o: main.c ESS.h
	$(CC) -c main.c -o Elevator_x64.o $(FLAGS) $(DEBUG)

Elev64: Elevator_x64.o ESS64.o
	$(CC) -o Elev_x64 Elevator_x64.o ESS64.o $(FLAGS) $(DEBUG)

Elev32: Elevator_i386.o ESS32.o
	$(CC) -o Elev_i386 Elevator_i386.o ESS32.o $(FLAGS) $(DEBUG) $(X86)

all:	Elev32 Elev64

clean:
	rm Elevator_i386.o Elevator_x64.o
