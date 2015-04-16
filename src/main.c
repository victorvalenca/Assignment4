*
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
#include "ESS.h"

/***********************
* Forward Declarations
***********************/
int* pendingRequests();

/***********************
	Define Variables
***********************/

int *array				//Pointer to main array of building floors
int *upRequests			//Pointer to an array returned from buttonPressedOutsideGoingUp();
int *downRequests		//Pointer to an array returned from buttonPressedOutsideGoingDown();
int *requestIn			//Variable to hold requested floor inside the elevator
int currentFloor		//Variable to hold current floor of the elevator initialized to BASEMENT
int destinationFloor	//Variable to hold next destination
int floorRequest		//Variable holding last floor called inside

/**
*	PURPOSE: Check if there are any floors that have called the elevator above or below it, or any
*			pending calls inside the elevator
*	INPUT: The direction the elevator is currently heading.
*	OUTPUTS: 	1 if there is a pending call for the elevator ahead of its trip up or down.
*				0 if none.
*	ALGORYTHM: Iterate through the array of requests of the elevator's inside buttons until it 
*				finds a non-zero element or reaches
*				the end of the array. If a non-zero element is found, return. Otherwise continue
*				and iterate the same way through the array of buttons outside. The outer button
*				array checked will be decided by the direction passed as argument.
**/

WHILE(POWERGOOD){

	upRequests = buttonPressedOutsideGoingUp();
	downRequests = buttonPressedOutsideGoingDown();

	while(currentFloor < TOP){

		floorRequest = buttonPressedInside();
		requestIn[floorRequest] = 1;
		openDoorCloseDoor(); //Close Doors

		while (currentFloor == TOP || array[currentFloor] == 1 || requestIn[currentFloor] == 1 || 
				upRequests[currentFloor] = 1 || pendingRequests(UP) == 1){
			GO(UP); //Go to next floor up
		}

		//Stop elevator, clear buttons and open doors. It is assumed GO() automatically assigns
		//the new currentFloor value.
		GO(STOP);

		requestsIn[currentFloor] = 0
		upRequests[currentFloor] = 0

		openDoorCloseDoor(); //Open Doors

	}

	while(currentFloor > BASEMENT){

		floorRequest <- buttonPressedInside();
		requestIn[floorRequest] <- 1;
		openDoorCloseDoor(); //Close Doors

		while (currentFloor == BASEMENT || array[currentFloor] == 1 || requestIn[currentFloor] == 1
				|| downRequests[currentFloor] == 1 || pendingRequests(DOWN) == 1){
			GO(DOWN); //Go to next floor down
		}

		//Stop elevator and open doors
		GO(STOP);

		requestsIn[currentFloor] = 0;
		upRequests[currentFloor] = 0;

		openDoorCloseDoor(); //Open Doors

	}
}
