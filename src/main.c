/*
*	Assignment 4: Elevator
*
*	PURPOSE: Control an elevator inside a building
*
*	HISTORY: Written by Victor Fernandes April 16, 2015
*
*	STUDENT #: 040772243
*
**/

/***********************
* Import Statements
***********************/
#include <stdio.h>
#include <stdlib.h>
#include "ESS.h"

/***********************
* Forward Declarations
***********************/
int pendingRequests(int);
/**
*	PURPOSE: Check if there are any floors that have called the elevator
*		above or below it, or any pending calls inside the elevator
*	INPUT: The direction the elevator is currently heading.
*	OUTPUTS:1 if there is a pending call for the elevator ahead
*			of its trip up or down.
*		0 if none.
*	ALGORYTHM: Iterate through the array of requests of the elevator's
*		inner buttons until it finds a non-zero element or reaches
*		the end of the array. If a non-zero element is found, return.
*		Otherwise continue and iterate the same way through the array
*		of buttons outside. The outer button array checke will
*		be decided by the direction passed as argument.
**/
int main ()
{

	//Initialize variables
	int array[FLOORS] = {0};
	int* upRequests;
	int* downRequests;
	int* requestIn;

	int currentFloor = 0;
	int destinationFloor = 0;
	int floorRequest = 0;

	// Start up the elevator
	initialize();

while (POWERGOOD)
{

	upRequests = (int *) malloc(sizeof(int) * FLOORS);
	downRequests = (int *) malloc(sizeof(int) * FLOORS);
	requestIn = (int *) malloc(sizeof(int) * FLOORS);

	while(currentFloor < TOP)
	{


		floorRequest = buttonPressedInside();
		system("sleep 2");
		*(requestIn + floorRequest) = 1;

		while ( (currentFloor < TOP) &&
				(( *(array + currentFloor) == 0) &&
				( *(requestIn + currentFloor) == 0) &&
				( *(upRequests + currentFloor) == 0) /*||
				( pendingRequests(UP) != 1)*/))
		{
			upRequests = buttonPressedOutsideGoingUp();
			downRequests = buttonPressedOutsideGoingDown();
			currentFloor = Go(UP); //Go to next floor up
			wprintf(L"Current Floor: %d\n", currentFloor);
			wprintf(L"Requested Floor: %d\n",
					*(requestIn + currentFloor));
			wprintf(L"Up Pressed?: %d\n",
					*(upRequests + currentFloor));
			system("sleep 1");

		}

		if ( *(requestIn + currentFloor) != 0)
		{
			currentFloor = Go(STOP);
			openDoorCloseDoor();
			*(requestIn + currentFloor) = 0;
		}

		if ( *(upRequests + currentFloor) != 0 )
		{
			currentFloor= Go(STOP);
			openDoorCloseDoor();
			*(upRequests + currentFloor) = 0;
		}

	}

	while(currentFloor > BASEMENT)
	{

		floorRequest = buttonPressedInside();
		system("sleep 2");
		*(requestIn + floorRequest) = 1;

		while ( (currentFloor > BASEMENT) &&
				((*(array + currentFloor) == 0) &&
				(*(requestIn + currentFloor) == 0 ) &&
				(*(downRequests + currentFloor) == 0)/* ||
				( pendingRequests(DOWN) != 1)*/))
		{
			upRequests = buttonPressedOutsideGoingUp();
			downRequests = buttonPressedOutsideGoingDown();
			currentFloor = Go(DOWN); //Go to next floor down
			wprintf(L"Current Floor: %d\n", currentFloor);
			wprintf(L"Requested Floor: %d\n",
					*(requestIn + currentFloor));
			wprintf(L"Down Pressed?: %d\n",
					*(downRequests + currentFloor));
			system("sleep 1");
		}

		if ( *(requestIn + currentFloor) != 0 )
		{
			Go(STOP);
			openDoorCloseDoor();
			*(requestIn + currentFloor) = 0;
		}

		if ( *(downRequests + currentFloor) != 0 )
		{
			Go(STOP);
			openDoorCloseDoor();
			*(downRequests + currentFloor) = 0;
		}


	}


	}
}


int pendingRequests(int direction){
	return 1;
}
