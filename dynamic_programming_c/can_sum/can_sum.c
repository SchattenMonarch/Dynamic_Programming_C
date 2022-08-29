#include "can_sum.h"
#include <stdio.h>
#include <stdlib.h>
#include <khash.h>

#define KEY_BUFFER_SIZE 15

KHASH_MAP_INIT_STR(map, bool)
khash_t(map)* map_ptr;
khiter_t it;

void init_can_sum(void) {
	map_ptr = kh_init(map);
	it = -1;
}

bool can_sum(int target_value, const int numbers[], int length) {
	if (target_value == 0) return true;
	if (target_value < 0) return false;
	char key[KEY_BUFFER_SIZE] = { '\0' };
	int index = 0, sprintf_ret = 0, absent = 0;
	int ret;

	for (int k = 0; k < length; k++) {//build key: all elements in of numbers seperated by ',' and target_value at the end
		index += (sprintf_ret = sprintf_s(&key[index], KEY_BUFFER_SIZE - index, "%d%c", numbers[k], ',')) == -1 ? 0 : sprintf_ret;
		if (k == length - 1) {
			sprintf_s(&key[index], KEY_BUFFER_SIZE - index, "%d", target_value);
		}
	}
//	puts(key);
	it = kh_get(map, map_ptr, key);
	if (it != kh_end(map_ptr)) {//is key in hash map?
		return kh_val(map_ptr, it);
	}

	for (int i = 0; i < length; i++) {
		ret = can_sum(target_value - numbers[i], numbers, length);
		sprintf_s(&key[index], KEY_BUFFER_SIZE - index, "%d", target_value - numbers[i]);
//		puts(key);
		it = kh_put(map, map_ptr, key, &absent);
		if (absent) kh_key(map_ptr, it) = _strdup(key);
		kh_val(map_ptr, it) = ret;
		if (ret) return ret;
	}
	return false;
}

void deinit_can_sum(void){
	free(map_ptr);
}