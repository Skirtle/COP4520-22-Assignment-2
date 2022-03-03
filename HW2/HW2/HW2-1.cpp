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
#define GUEST_COUNT 15


// Globals
int currentGuestID = -1; // The guest currently in the maze
int counter = 1; // includes the Counting Guest
bool cupcakeIsThere = true; // Cupcake exists at start
bool waiting = true; // Counting not done yet


// Function prototypes
int randomInt(int min, int max); // A random number between min and max, inclusive of both
void guestThread(int id);


int main() {
	// Start
	srand(time(0));

	// Create threads
	std::thread threads[GUEST_COUNT];
	for (int i = 0; i < GUEST_COUNT; i++) {
		threads[i] = std::thread(guestThread, i);
	}


	// Wait for guests do to everything
	while (waiting) {
		currentGuestID = randomInt(0, GUEST_COUNT - 1);
		while (currentGuestID != -1) {
			continue;
		}
	}


	// Free threads when done
	for (int i = 0; i < GUEST_COUNT; i++) {
		threads[i].join();
	}

	// Finish
	std::cout << "Counted " << counter << " guests\n";
	return 0;
}

int randomInt(int min, int max) {
	return rand() % (max - min + 1) + min;
}

void guestThread(int tid) {
	bool eaten = false;
	while (waiting) {
		// Rule 0.0 One chosen guest at a time
		if (tid != currentGuestID) {
			continue;
		}

		// Rule 1.0 If guest 0 sees no cupcake, add 1 to counter and replace cupcake
		else if (tid == 0 && !cupcakeIsThere) {
			counter++;
			cupcakeIsThere = true;
			if (counter == GUEST_COUNT) {
				waiting = false;
			}
		}

		// Rule 2.0 If guest 0 sees cupcake, do nothing
		else if (tid == 0 && cupcakeIsThere) {
			// do nothing
		}

		// Rule 3.0 If guest R sees no cupcake, do nothing
		else if (tid != 0 && !cupcakeIsThere) {
			// do nothing
		}

		// Rule 4.0 If guest R sees cupcake
		else if (tid != 0 && cupcakeIsThere) {
			// Rule 4.1 If already eaten one, do nothing
			if (eaten) {
				// do nothing
			}

			// Rule 4.2 If not already eaten one, eat cupcake
			else if (!eaten) {
				eaten = true;
				cupcakeIsThere = false;
			}
		}

		// Guest leaves
		currentGuestID = -1;
	}
}