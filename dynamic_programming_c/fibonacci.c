#include "fibonacci.h"
#include <stdbool.h>
#include <assert.h>

KHASH_MAP_INIT_INT(map, unsigned long long)
khash_t(map)* map_ptr;

unsigned long long fib(int n) {
	int ret;
    bool is_missing;
	static bool map_initiated = false;
	khiter_t it;
	if (!map_initiated) {
		map_ptr = kh_init(map);
		map_initiated = true;
	}
	
	printf("Entered fib with n = %d\n", n);
	if (n <= 2) return 1;
	it = kh_get(map, map_ptr, n);
	
	is_missing = (it == kh_end(map_ptr));

	if (is_missing) {
		it = kh_put(map, map_ptr, n, &ret);
		printf("CALCULATING FIB FOR n = %d\n", n);
		kh_value(map_ptr, it) = fib(n - 1) + fib(n - 2);
	}
	else {
		printf("VALUE FOR n = %d already exists: %lld\n", kh_value(map_ptr, it));
		return kh_value(map_ptr, it);
	}
	it = kh_get(map, map_ptr, n);
	is_missing = (it == kh_end(map_ptr));
	assert(is_missing == false);
	return kh_value(map_ptr, it);
}

