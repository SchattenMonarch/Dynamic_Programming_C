#include "fibonacci.h"

long long fib(int n) {
	return n <= 2 ? 1 : fib(n - 1) + fib(n - 2);
}

