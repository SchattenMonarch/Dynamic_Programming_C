#include "grid_traveler.h"

long long grid_traveler(int row, int column) {
	if (row == 1 && column == 1) return 1;
	if (row == 0 || column == 0) return 0;
	return grid_traveler(row - 1, column) + grid_traveler(row, column - 1);
}