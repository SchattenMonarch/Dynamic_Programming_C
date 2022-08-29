/*
author: Dennis Folz
github profile : https://github.com/SchattenMonarch
date:   29.08.2022
last update: 29.08.2022
problem:
Implement a brute-force recursive function bool can_sum(int target_value, const int *numbers);

Return values:
- true: if it is possible to generate the target_value by summing the elements in the array.
- false: if it is not possible.

Samples
Sample 1

can_sum(7, [5, 3, 4, 7]) -> true
because there are three possible solutions: 3+4, 4+3 and 7.

Sample 2

can_sum(7, [2, 4]) -> false
because it's impossible to build a 7 with the numbers in the array.
*/
#include <stdio.h>
#include <assert.h>
#include <time.h>
#include "can_sum.h"

int main()
{
    //start clock for time measurement
    clock_t begin = clock();

    init_can_sum();
    //test can_sum
    assert(can_sum(7, (int[]){2, 3}, 2));
    assert(can_sum(7, (int[]){ 5, 3, 4, 7 }, 4));
    assert(!can_sum(7, (int[]) { 2, 4 }, 2));
    assert(can_sum(8, (int[]) { 2, 3, 5 }, 3));
    assert(!can_sum(30, (int[]) { 8, 17, 27 }, 3));
    assert(!can_sum(300, (int[]) { 7, 14 }, 2));
    assert(can_sum(422, (int[]) { 99, 2 }, 2));

     deinit_can_sum();
    //stop the clock for time measurement
    clock_t end = clock();
    //calculate the spent time
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    //give feedback to the user
    puts("all tests passed");
    printf("time spent: %lf s", time_spent);
    return 0;
}