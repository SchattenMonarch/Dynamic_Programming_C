/*
author: Dennis Folz
github profile : https://github.com/SchattenMonarch
date:   28.08.2022
last update: 28.08.2022
problem: 
Implement a grid-traveler using recursion.
The function shall return the number of possible ways to travel through a n x m grid from the top left corner to the bottom right corner.
It is only allowed to move down and right
*/
#include <stdio.h>
#include <assert.h>
#include <time.h>
#include "grid_traveler.h"

int main()
{
    //start clock for time measurement
    clock_t begin = clock();

    //initialize all data structures and vars in grid_traveler.c
 //   init_grid_traveler();

    //test the recursive grid_traveler(n, m) function
    assert(grid_traveler(1, 1) == 1);
    assert(grid_traveler(2, 3) == 3);
    assert(grid_traveler(3, 2) == 3);
    assert(grid_traveler(3, 3) == 6);
//    assert(grid_traveler(18, 18) == 2333606220);
  
    //free allocated memory
//    deinit_grid_traveler();

    //stop the clock for time measurement
    clock_t end = clock();
    //calculate the spent time
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    //give feedback to the user
    puts("all tests passed");
    printf("time spent: %lf s", time_spent);
    return 0;
}
