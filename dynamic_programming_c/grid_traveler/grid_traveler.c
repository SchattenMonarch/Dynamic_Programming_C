#define _CRT_SECURE_NO_WARNINGS
#include "grid_traveler.h"
#include "khash.h"
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
//#define KEY_IN_HASH_MAP (it != kh_end(map_ptr) && kh_str_hash_func(key) == kh_str_hash_func(kh_key(map_ptr, it)))
#define KEY_BUFFER_SIZE 15u

KHASH_MAP_INIT_STR(map, long long)
khash_t(map)* map_ptr; 
khiter_t it;
int ret;
long long val;

void init_grid_traveler(void) {
	map_ptr = kh_init(map);
	it = -1;
	ret = -1;
	val = -1;
}

long long grid_traveler(int row, int column) {
	char key[KEY_BUFFER_SIZE], found_key[KEY_BUFFER_SIZE];
	sprintf(key, "<%d , %d>", row, column);
	printf("ENTERED recursive function with key: %s\n", key);
	if (row == 1 && column == 1) {
		puts("return 1;");
		return 1;
	} 
	if (row == 0 || column == 0) {
		puts("return 0;");
		return 0;
	}
	
	
	it = kh_get(map, map_ptr, key);
	int key_hash, found_key_hash;
	if (it != kh_end(map_ptr)) {
		sprintf(found_key, "%s", kh_key(map_ptr, it));
		key_hash = kh_str_hash_func(key);
		found_key_hash = kh_str_hash_func(found_key);
	}
	
	bool KEY_IN_HASH_MAP = (it != kh_end(map_ptr) && kh_str_hash_func(key) == kh_str_hash_func(kh_key(map_ptr, it)));
	if (KEY_IN_HASH_MAP) {
		printf("Key %s / found key %s found in hash_map with the value %lld\n", key, kh_key(map_ptr, it), kh_val(map_ptr, it));
		return kh_val(map_ptr, it);
	}
	else {
		val = grid_traveler(row - 1, column) + grid_traveler(row, column - 1);
		it = kh_put(map, map_ptr, key, &ret);
		assert(ret != -1);
		kh_val(map_ptr, it) = val;
		printf("Key %s value was CALCULATED: %lld and inserted into the hash_map with the key: %s\n", key, kh_val(map_ptr, it), kh_key(map_ptr, it));
	}
	return kh_val(map_ptr, it);
}

void deinit_grid_traveler(void) {
	free(map_ptr);
}
