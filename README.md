# COP4520-HW2
Assignment 2 for COP4520-22 <br/>
Made by Dalton Kajander

# Assignments
Each assignment is in it's own file to be compiled and ran seperately, named HW2-1 and HW2-2 for problem 1 and 2 respectively. <br>

## Problem 1
Compiled using Windows PowerShell with the command "g++ -o HW2-1.exe HW2-1.cpp -lpthread" <br>
The program uses a concrete number of 12 guests (my CPU (Ryzen 5 3600X) has 12 threads) <br>
The way the program works is that one guest (in this case, guest 0) is chosen as The Counter. The Counter has one job, to add up how how many guests there are. Everytime The Counter goes into the maze and does not see a cupcake, that means a guest ate it. The Counter adds 1 to the count and requests a new cupcake. To stop the count from going up infinitely, each guest is only allowed to eat a single cupcake. If there is no cupcake and you are not the counter, do ***not*** request a new cupcake, just leave the maze. If you already ate a cupcake, simply leave the maze without doing anything. <br>
This method ensures that each guest only ever eats one cupcake so The Counter can add up the number of eaten cupcakes correctly. 

## Problem 2
Compiled using Windows PowerShell with the command "g++ -o HW2-2.exe HW2-2.cpp -lpthread" <br>
The program uses a concrete number of 12 guests (my CPU (Ryzen 5 3600X) has 12 threads) <br>