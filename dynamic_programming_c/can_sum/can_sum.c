#include "can_sum.h"
#include <khash.h>

KHASH_MAP_INIT_INT(map, int)
khash_t(map)* map_ptr;
khiter_t it;

void init_can_sum(void) {
	map_ptr = kh_init(map);
	it = -1;
}

bool can_sum(int target_value, const int numbers[], int length) {
	if (target_value == 0) return true;
	if (target_value < 0) return false;

	for (int i = 0; i < length; i++) {
		if (can_sum(target_value - numbers[i], numbers, length)) return true;
	}
	return false;
}

void deinit_can_sum(void) {
	free(map_ptr);
}