/*
N = number of guests
Only guest 0 can replace cupcake
Guest R = random guest (excluding guest 0)

0.0 One chosen guest at a time
1.0 If guest 0 sees no cupcake, add 1 to counter and replace cupcake
2.0 If guest 0 sees cupcake, do nothing
3.0 If guest R sees no cupcake, do nothing
4.0 If guest R sees cupcake:
	4.1 If already eaten one, do nothing
	4.2 If not already eaten one, eat cupcake
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