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
	int upRequests[FLOORS] = {0};
	int downRequests[FLOORS] = {0};
	int requestIn[FLOORS] = {0};

	int currentFloor = 0;
	int destinationFloor = 0;
	int floorRequest = 0;

	// Start up the elevator
	initialize();

while (POWERGOOD)
{


	*upRequests = buttonPressedOutsideGoingUp();
	*downRequests = buttonPressedOutsideGoingDown();

	while(currentFloor < TOP)
	{

		system("sleep 1");
		floorRequest = buttonPressedInside();
		system("sleep 1");
		*(requestIn + floorRequest) = 1;
		system("sleep 1");
		openDoorCloseDoor(); //Close Doors

		while ( (currentFloor != TOP) ||
				( *(array + currentFloor) != 1) ||
				( *(requestIn + currentFloor) != 1) ||
				( *(upRequests + currentFloor) != 1) /*||
				( pendingRequests(UP) != 1)*/)
		{
			currentFloor = Go(UP); //Go to next floor up
			wprintf(L"Current Floor: %d", currentFloor);
			system("sleep 1");
		}

		//Stop elevator, clear buttons and open doors. It is assumed
		//GO() automatically assigns the new currentFloor value.
		currentFloor = Go(STOP);
		openDoorCloseDoor(); //Open Doors

		system("sleep 1");
		*(requestIn+currentFloor) = 0;
		system("sleep 1");
		*(upRequests+currentFloor) = 0;


	}

	while(currentFloor > BASEMENT)
	{

		*upRequests = buttonPressedOutsideGoingUp();
		*downRequests = buttonPressedOutsideGoingDown();


		floorRequest = buttonPressedInside();
		system("sleep 1");
		*(requestIn + floorRequest) = 1;
		system("sleep 1");
		openDoorCloseDoor(); //Close Doors

		while ( (currentFloor != BASEMENT) ||
				(*(array + currentFloor) != 1) ||
				(*(requestIn + currentFloor) != 1 )||
				(*(downRequests + currentFloor) != 1)/* ||
				( pendingRequests(DOWN) != 1)*/)
		{
			currentFloor = Go(DOWN); //Go to next floor down
			wprintf(L"Current Floor: %d", currentFloor);
			system("sleep 1");
		}
		}

		//Stop elevator and open doors
		currentFloor = Go(STOP);
		openDoorCloseDoor(); //Open Doors

		system("sleep 1");
		*(requestIn + currentFloor) = 0;
		*(upRequests + currentFloor) = 0;


	}
}
}

int pendingRequests(int direction){
	return 1;
}
