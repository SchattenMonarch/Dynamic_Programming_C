/*
author: Dennis Folz
github profile : https://github.com/SchattenMonarch
date:   25.08.2022
last update: 27.08.2022
program: Implement a recursive program to calculate the nth fibonacci sequence with O(n) time complexity
*/
#include <stdio.h>
#include <assert.h>
#include <time.h>
#include "fibonacci.h"

int main()
{
	//start clock for time measurement
    clock_t begin = clock();
	
	//initialize fibonacci.c
    init_fib();
	
	//test the recursive fib() function which returns the nth fibonacci sequence
    assert(fib(1) == 1);
    assert(fib(2) == 1);
    assert(fib(3) == 2);
    assert(fib(4) == 3);
    assert(fib(5) == 5);
    assert(fib(6) == 8);
    assert(fib(7) == 13);
    assert(fib(8) == 21);
    assert(fib(9) == 34);
    assert(fib(10) == 55);
    assert(fib(11) == 89);
    assert(fib(12) == 144);
    assert(fib(13) == 233);
    assert(fib(20) == 6765);
    assert(fib(25) == 75025);
    assert(fib(50) == 12586269025);
	
	//free allocated memory
    deinit_fib();

    //stop the clock for time measurement
    clock_t end = clock();
	//calculate the spent time
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	//give feedback to the user
    puts("all tests passed");
    printf("time spent: %lf s", time_spent);
    return 0;
}
