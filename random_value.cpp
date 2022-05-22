#include "random_value.h"
#include <cstdlib>
#include <ctime>


int get_random_value(const int &max) {
	std::srand(std::time(nullptr));
	const int random_value = std::rand() % max;
	return random_value;
}