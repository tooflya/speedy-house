#ifndef CONST_UTILS
#define CONST_UTILS

#include "Utils.h"

float Utils::random(float min, float max) {
	return min + (float) rand() / ((float) RAND_MAX / (max - min));
}

#endif