#define _CRT_SECURE_NO_WARNINGS
#include "grid_traveler.h"
#include "khash.h"
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define KEY_BUFFER_SIZE 30u

KHASH_MAP_INIT_STR(map, long long)
khash_t(map)* map_ptr; 
khiter_t it;
int absent;
long long val;

void init_grid_traveler(void) {
	map_ptr = kh_init(map);
	it = -1;
	absent = -1;
	val = -1;
}

long long grid_traveler(int row, int column) {
	char key[KEY_BUFFER_SIZE] = { '\0' }, alt_key[KEY_BUFFER_SIZE] = { '\0' };
	sprintf(key, "<%d,%d>", row, column); //build key
	sprintf(alt_key, "<%d,%d>", column, row); //build alternative key, because value of <row,column> equals value of <column,row>
//	printf("ENTERED recursive function with key: %s\n", key);
	if (row == 1 && column == 1) { //base case #1
//		puts("return 1;");
		return 1;
	} 
	if (row == 0 || column == 0) {//base case #2
//		puts("return 0;");
		return 0;
	}
	
	if (is_key_in_hashmap(key, alt_key)) {//is the key in the hash map?
//		printf("Key %s / found key %s found in hash_map with the value %lld at iterator = %d\n", key, kh_key(map_ptr, it), kh_val(map_ptr, it), it);
		return kh_val(map_ptr, it);//return the corresponding value
	}
	else {//key was not found. 
		val = grid_traveler(row - 1, column) + grid_traveler(row, column - 1); //calculate the value
		//LESSON LEARNED: Don't put the key(pointer) directly into the map, because it can be changed afterwards.
		it = kh_put(map, map_ptr, key, &absent); //insert the key address into hash map
		if(absent) kh_key(map_ptr, it) = _strdup(key);//LESSON LEARNED: Overwrite the key with the string content, otherwise kh_get() fails
		kh_val(map_ptr, it) = val; //adjust the value corresponing to the key
//		printf("Key %s value was CALCULATED: %lld and inserted into the hash_map at iterator = %d\n", key, kh_val(map_ptr, it), it);
	}
	return kh_val(map_ptr, it);//return the calculated value
}

bool is_key_in_hashmap(const char* key, const char* alt_key) {
	it = kh_get(map, map_ptr, key);
	if (it == kh_end(map_ptr)) {
		it = kh_get(map, map_ptr, alt_key);
	}
	return it != kh_end(map_ptr) ? true : false;
}

void deinit_grid_traveler(void) {
	free(map_ptr);
}
