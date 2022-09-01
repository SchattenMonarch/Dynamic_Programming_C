#pragma once
#ifndef __HOW_SUM_H__
#define __HOW_SUM_H__
#include <stdbool.h>

void init_how_sum(void);
int* how_sum(int target_value, const int numbers[], int length);
void deinit_how_sum(void);

#endif // !__HOW_SUM_H__
