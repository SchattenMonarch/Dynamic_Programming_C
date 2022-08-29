#pragma once
#ifndef __GRID_TRAVELER__
#define __GRID_TRAVELER__
#include <stdbool.h>

void init_grid_traveler(void);
long long grid_traveler(int row, int column);
bool is_key_in_hashmap(const char* key, const char* alt_key);
void deinit_grid_traveler(void);

#endif // !__GRID_TRAVELER__

#pragma once
