// Includes
#include <iostream>
#include <thread>

// Defines
#define MIN_RAND_N 5
#define MAX_RAND_N 15


// Globals
int guestCount; // Amount of guests
int currentGuestID = -1; // The guest currently in the maze
int counter = 1; // includes the Counting Guest
bool cupcakeIsThere = true; // Cupcake exists at start
bool waiting = true; // Counting not done yet

/* N = number of guests
Only guest 0 can replace cupcake
Guest R = random guest (excluding guest 0)

1.0 If guest 0 sees no cupcake, add 1 to counter and replace cupcake
2.0 If guest 0 sees cupcake, do nothing
3.0 If guest R sees no cupcake, do nothing
4.0 If guest R sees cupcake:
	4.1 If already eaten one, do nothing
	4.2 If not already eaten one, eat cupcake */


// Function prototypes
int randomInt(int min, int max); // A random number between min and max, inclusive of both
void guestThread(int id);

int main() {
	// Choosing the amount of guests
	std::cout << "How many guests? Enter 0 or less for a random number between 5 and 15\n";
	std::cin >> guestCount;
	if (guestCount <= 0) {
		guestCount = randomInt(MIN_RAND_N, MAX_RAND_N);
	}
	std::cout << "guestCount chosen to be " << guestCount << std::endl;

	// Create threads
	// std::thread* threads = (std::thread*) malloc(guestCount * sizeof(std::thread));

	std::thread threads[15];
	if (threads != NULL) { // In case not enough space for the threads to be allocated as an array
		for (int i = 0; i < guestCount; i++) {
			std::cout << "Creating thread " << i << std::endl;
			threads[i] = std::thread(guestThread, i);
		}
	}

	while (waiting) {
		while (currentGuestID != -1) {
			continue;
		}
		int x = randomInt(0, guestCount - 1);
		// std::cout << "Random guest " << x << " is up!\n";
		currentGuestID = x;
		
	}
	std::cout << "Done!\n";

	for (int i = 0; i < guestCount; i++) {
		threads[i].join();
	}

	// free(threads);
	std::cout << "Counted " << counter << " guests\n";
	return 0;
}

int randomInt(int min, int max) {
	return rand() % (max - min + 1) + min;
}

void guestThread(int tid) {
	std::string msg = "Starting thread " + std::to_string(tid) + "\n";
	// std::cout << msg;

	bool eaten = false;

	while (tid != currentGuestID && waiting) {
		continue;
	}

	while (!waiting) {
		continue;
	}
		
	msg = "Thread " + std::to_string(tid) + " in the maze\n";
	// std::cout << msg;

	if (tid == 0 && !cupcakeIsThere) { // Rule 1.0
		cupcakeIsThere = true;
		counter++;
		if (counter == guestCount) {
			waiting = false;
			return;
		}
	} // Rule 2.0

	else if (tid != 0) { // Not guest 0
		if (cupcakeIsThere) { // Rule 4.0
			if (!eaten) { // Rule 4.2
				eaten = true;
				cupcakeIsThere = false;
			} // Rule 4.1
		} // Rule 3.0
	}


	currentGuestID = -1;

	msg = "Thread " + std::to_string(tid) + " is done\n";
	// std::cout << msg;
}