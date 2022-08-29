#pragma once
#ifndef __CAN_SUM_H__
#define __CAN_SUM_H__
#include <stdbool.h>

void init_can_sum(void);
bool can_sum(int target_value, const int numbers[], int length);
void deinit_can_sum(void);

#endif // !__CAN_SUM_H__
