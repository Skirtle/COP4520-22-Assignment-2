# COP4520-HW2
Assignment 2 for COP4520-22 <br/>
Made by Dalton Kajander

# Assignments
Each assignment is in it's own file to be compiled and ran seperately, named HW2-1 and HW2-2 for problem 1 and 2 respectively. <br>

## Problem 1
Compiled using Windows PowerShell with the command "g++ -o HW2-1.exe HW2-1.cpp -lpthread" <br>
The program uses a concrete number of 12 guests (my CPU (Ryzen 5 3600X) has 12 threads) <br>

### Method
The way the program works is that one guest (in this case, guest 0) is chosen as The Counter. The Counter has one job, to add up how how many guests there are. Everytime The Counter goes into the maze and does not see a cupcake, that means a guest ate it. The Counter adds 1 to the count and requests a new cupcake. To stop the count from going up infinitely, each guest is only allowed to eat a single cupcake. If there is no cupcake and you are not the counter, do ***not*** request a new cupcake, just leave the maze. If you already ate a cupcake, simply leave the maze without doing anything. <br>
This method ensures that each guest only ever eats one cupcake so The Counter can add up the number of eaten cupcakes correctly. <br>

### Rules as a list
- N = number of guests
- Only guest 0 can replace cupcake
- Guest R = random guest (excluding guest 0)

- 0.0 One chosen guest at a time
- 1.0 If guest 0 sees no cupcake, add 1 to counter and replace cupcake. If counter == N, finished. 
- 2.0 If guest 0 sees cupcake, do nothing
- 3.0 If guest R sees no cupcake, do nothing
- 4.0 If guest R sees cupcake:
- 4.1 If already eaten one, do nothing
- 4.2 If not already eaten one, eat cupcake

### Runtime
The runtime of this program is variable. It sends in random guests and if unlucky, it can take a while for The Counter to go back into the maze to reset the cupcake. 


## Problem 2
Compiled using Windows PowerShell with the command "g++ -o HW2-2.exe HW2-2.cpp -lpthread" <br>
The program uses a concrete number of 12 guests (my CPU (Ryzen 5 3600X) has 12 threads) <br>

### Method
The method this program uses is the second strategy given. The room has a sign that states whether it is busy or available to be used, and each guest has to change it when entering and leaving the room. 

#### Method 1: Advantages and Disadvantages
- Advantages
1. Easiest to implement
- Disadvantages
1. No guest is guaranteed to go in when checking

#### Method 1: Advantages and Disadvantages
- Advantages
1. Easy to implement
2. Each guest guaranteed to enter at some point
- Disadvantages
1. There is no order to which the guests enter, quickest to check if available goes in first when trying to enter

#### Method 3: Advantages and Disadvantages
- Advantages
1. Each guest guaranteed to enter at some point
2. Each guest tells the next guest to go in, first come first serve in the order they come, a queue
- Disadvantages
1. Hardest to implement