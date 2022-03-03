// Includes
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

// Defines
#define DEF_GUEST_COUNT 12

// Globals
std::mutex mutex;
std::condition_variable guests;
bool roomAvailable = 1;

// Function prototypes
void guest(int tid);


int main() {
    // Create threads
    std::thread guestThreads[DEF_GUEST_COUNT];
    for (int i = 0; i < DEF_GUEST_COUNT; i++) {
        guestThreads[i] = std::thread(guest, i);
    }


    // Join threads
    for (int i = 0; i < DEF_GUEST_COUNT; ++i) {
        guestThreads[i].join();
    }

    return 0;
}

void guest(int tid) {
    // Wait until notifed guest can enter the room
    std::unique_lock<std::mutex> lock(mutex);
    while (roomAvailable == 0) guests.wait(lock);

    // Lock the doors, look at the vase
    roomAvailable = 0;
    std::cout << "Guest " << tid << " is viewing the vase\n";

    // Unlock the door and leave
    roomAvailable = 1;
    guests.notify_one();
}