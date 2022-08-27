#include "fibonacci.h"
#include <stdbool.h>
#include <assert.h>

KHASH_MAP_INIT_INT(map, long long)
khash_t(map)* map_ptr;
int ret;
long long val;
bool is_missing;
khiter_t it;

void init_fib(void) {
	map_ptr = kh_init(map);
	is_missing = true;
	ret = 0;
	val = 0;
	it = -1;
}

long long fib(int n) {
	it = kh_get(map, map_ptr, n);

	if (it != kh_end(map_ptr)){
		val = kh_value(map_ptr, it);
//		printf("Key #%d exists. Value: %lld\n", n, val);
		return val;
	}
	if (n <= 2) return 1;

	val = fib(n - 1) + fib(n - 2);
	//LESSON LEARNED: Don't call kh_put before a recursive function, or too many same keys will be stored without a value.
	//This leads to an undefined kh_value(map_ptr, it), because kh_get(map, map_ptr, n) will return an iterator to a key without a value!
	it = kh_put(map, map_ptr, n, &ret); 
//	printf("CALCULATED: Key #%d \t Value: %lld\n", n, val);
	kh_value(map_ptr, it) = val;

	return val;
}

void deinit_fib(void) {
	free(map_ptr);
}

