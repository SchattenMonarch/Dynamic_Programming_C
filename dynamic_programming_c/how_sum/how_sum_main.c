/*
author: Dennis Folz
github profile : https://github.com/SchattenMonarch
date:   01.09.2022
last update: 01.09.2022
problem:
Implement a brute-force recursive function bool can_sum(int target_value, const int *numbers);

Return values:
- array with values from the input array, that add up to the target_value
- NULL: if it is not possible to generate the target_value by adding up elements from the input array

Samples
Sample 1

how_sum(7, (int[]){3, 2}) -> 3,2,2

Sample 2

can_sum(7, [2, 4]) -> NULL
*/
#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <string.h>
#include "how_sum.h"

int main()
{
    //start clock for time measurement
    clock_t begin = clock();

//    init_how_sum();
    //test can_sum
    assert(!strcmp(how_sum(7, (int[]){2, 3}, 2), "3,2,2");
    assert(strcmp(how_sum(7, (int[]){ 5, 3, 4, 7 }, 4), "3,4");


//     deinit_how_sum();
    //stop the clock for time measurement
    clock_t end = clock();
    //calculate the spent time
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    //give feedback to the user
    puts("all tests passed");
    printf("time spent: %lf s", time_spent);
    return 0;
}
