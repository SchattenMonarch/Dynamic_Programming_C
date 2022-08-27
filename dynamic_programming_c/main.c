 #include <stdio.h>
 #include <assert.h>
#include <time.h>

#include "fibonacci.h"
#include "khash.h"

KHASH_MAP_INIT_INT(map, long long)

int main()
{
    clock_t begin = clock();
    init_fib();
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

    deinit_fib();

    
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    puts("all tests passed");
    printf("time spent: %f s", time_spent);
    return 0;
}
