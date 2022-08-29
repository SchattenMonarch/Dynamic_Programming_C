#include "can_sum.h"

bool can_sum(int target_value, const int numbers[], int length) {
	if (target_value == 0) return true;
	if (target_value < 0) return false;

	for (int i = 0; i < length; i++) {
		if (can_sum(target_value - numbers[i], numbers, length)) return true;
	}
	return false;
}