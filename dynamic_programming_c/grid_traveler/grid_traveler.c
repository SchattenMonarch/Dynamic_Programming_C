#include "grid_traveler.h"
#include "khash.h"

#define KEY_IN_HASH (it != kh_end(map_ptr))

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
	if (row == 1 && column == 1) return 1;
	if (row == 0 || column == 0) return 0;
	return grid_traveler(row - 1, column) + grid_traveler(row, column - 1);
}

void deinit_grid_traveler(void) {
	free(map_ptr);
}