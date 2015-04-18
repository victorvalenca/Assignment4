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
					( *(upRequests + currentFloor) == 0)))
			{
				upRequests = buttonPressedOutsideGoingUp();
				downRequests = buttonPressedOutsideGoingDown();
				//Go to next floor up
				currentFloor = Go(UP);
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
					(*(downRequests + currentFloor) == 0)))
			{
				upRequests = buttonPressedOutsideGoingUp();
				downRequests = buttonPressedOutsideGoingDown();
				
				//Go to next floor down
				currentFloor = Go(DOWN); 
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
