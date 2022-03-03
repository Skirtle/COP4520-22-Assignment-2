/*
N = number of guests
Only guest 0 can replace cupcake
Guest R = random guest (excluding guest 0)

0.0 One guest at a time
*/

// Includes
#include <iostream>
#include <thread>
#include<cstdlib>

// Defines
#define MIN_RAND_N 5
#define MAX_RAND_N 15
#define GUEST_COUNT 12


// Globals


// Function prototypes
int randomInt(int min, int max); // A random number between min and max, inclusive of both


int main() {
	// Start
	srand(time(0));

	
	return 0;
}

int randomInt(int min, int max) {
	return rand() % (max - min + 1) + min;
}