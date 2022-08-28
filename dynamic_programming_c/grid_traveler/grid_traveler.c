#define _CRT_SECURE_NO_WARNINGS
#include "grid_traveler.h"
#include "khash.h"
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

#define KEY_IN_HASH_MAP (it != kh_end(map_ptr))
#define KEY_BUFFER_SIZE 30u

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
	char key[KEY_BUFFER_SIZE];
	sprintf(key, "<%d,%d>", row, column); //build key
	printf("ENTERED recursive function with key: %s\n", key);
	if (row == 1 && column == 1) { //base case #1
		puts("return 1;");
		return 1;
	} 
	if (row == 0 || column == 0) {//base case #2
		puts("return 0;");
		return 0;
	}

	it = kh_get(map, map_ptr, key);//get the iterator of the key. Returns kh_end(map_ptr) if the key is absent
	
	if (KEY_IN_HASH_MAP) {//is the key in the hash map?
		printf("Key %s / found key %s found in hash_map with the value %lld at iterator = %d\n", key, kh_key(map_ptr, it), kh_val(map_ptr, it), it);
		return kh_val(map_ptr, it);//return the corresponding value
	}
	else {//key was not found. 
		val = grid_traveler(row - 1, column) + grid_traveler(row, column - 1); //calculate the value
		it = kh_put(map, map_ptr, key, &ret); //insert key into hash map
		assert(ret != -1); //insertion successfull?
		kh_val(map_ptr, it) = val; // adjust the value corresponing to the key
		printf("Key %s value was CALCULATED: %lld and inserted into the hash_map with the key: %s at iterator = %d\n", key, kh_val(map_ptr, it), kh_key(map_ptr, it), it);
	}
	return kh_val(map_ptr, it);//return the calculated value
}

void deinit_grid_traveler(void) {
	free(map_ptr);
}
