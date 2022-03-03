/*
1.0 One guest at a time
*/

// Includes
#include <iostream>
#include <thread>
#include<cstdlib>
#include <queue>

// Defines
#define MIN_RAND_N 0
#define MAX_RAND_N 14
#define DEF_GUEST_COUNT 12

// Function prototypes
int randomInt(int min, int max); // A random number between min and max, inclusive of both
void guestThread(int tid);

// Globals
bool roomOccupied = false;
std::queue<int> queue;


int main() {
	// Start
	srand(time(0));


	// Create threads
	std::thread threads[DEF_GUEST_COUNT];
	for (int i = 0; i < DEF_GUEST_COUNT; i++) {
		threads[i] = std::thread(guestThread, i);
	}


	// Create queue
	queue = std::queue<int>();
	int temp[DEF_GUEST_COUNT] = {0};
	for (int i = 0; i < DEF_GUEST_COUNT; i++) {
		int guest = randomInt(0, DEF_GUEST_COUNT - 1);

		while (temp[guest] == 1) {
			guest = randomInt(0, DEF_GUEST_COUNT - 1);
		}

		queue.push(guest);
		temp[guest] = 1;
	}






	// Join threads
	for (int i = 0; i < DEF_GUEST_COUNT; i++) {
		threads[i].join();
	}
	
	
	return 0;
}

// Function defines
int randomInt(int min, int max) {
	return rand() % (max - min + 1) + min;
}

void guestThread(int tid) {
	
}