/*
1.0 One guest at a time
*/

// Includes
#include <iostream>
#include <thread>
#include<cstdlib>

// Defines
#define MIN_RAND_N 0
#define MAX_RAND_N 14
#define DEF_GUEST_COUNT 12

// Function prototypes
int randomInt(int min, int max); // A random number between min and max, inclusive of both
void guestThread(int tid) {

}

// Classes
class Queue {
public:
	int size = 0;
	int maxSize;

	Queue(int length) {
		arr = (int*)malloc(length * sizeof(int));
		maxSize = length;
		if (arr != NULL) {
			for (int i = 0; i < maxSize; i++) {
				arr[i] = -1;
			}
		}
	}
	
	~Queue() {
		free(arr);
	}

	int dequeue() {
		if (size <= 0) return -1;
		int front = arr[0];
		for (int i = 0; i < maxSize - 1; i++) {
			arr[i] = arr[i + 1];
		}
		arr[maxSize - 1] = -1;
		size--;
		return front;
	}

	int peek() {
		if (size <= 0) return -1;
		return arr[0];
	}

	void enqueue(int val) {
		if (size < maxSize) {
			arr[size] = val;
			size++;
		}
	}

	void print() {
		for (int i = 0; i < maxSize; i++) {
			std::cout << arr[i] << " ";
		}
		std::cout << "\n";
	}

private:
	int* arr;
};

// Globals
bool roomOccupied = false;
Queue queue = Queue(DEF_GUEST_COUNT);


int main() {
	// Start
	srand(time(0));

	
	return 0;
}

// Function defines
int randomInt(int min, int max) {
	return rand() % (max - min + 1) + min;
}