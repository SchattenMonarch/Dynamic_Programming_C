#include <stdio.h>
#include <assert.h>

#include "hash.h"
#include "fibonacci.h"

int main()
{
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
    puts("all tests passed");
    return 0;
}