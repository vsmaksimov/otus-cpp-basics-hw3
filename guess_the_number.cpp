#include "random_value.h"
#include "print_table.h"
#include "update_table.h"

#include <iostream>

int main(int argc, char** argv) {
	const char * file_name = "high_scores.txt";
	int max = 100;
	int current_value = 0;
	int attempts_count = 0;
	std::string username = "";

	if (argc > 1) {
		if (argc > 3) {
			std::cout << "Too many arguments!" << std::endl;
			return -1;
		} 

		std::string arg1_value{ argv[1] };
		
		if (arg1_value == "-max") {
			max = std::stoi(argv[2]);
		}
		else if (arg1_value == "-table") {
			print_table(file_name);
			return 0;
		}
		else if (arg1_value == "-level") {
			int level = std::stoi(argv[2]);
			
			if (level == 1 ) {
				max = 10;
			}
			else if (level == 2) {
				max = 50;
			}
			else if (level == 3) {
				max = 100;
			}
			else {
				std::cout << "Unknown level " << level << std::endl;
				return -1;
			}

		}
		else {
			std::cout << "Unknown parameter " << "\"" << arg1_value << "\"!" << std::endl;
			return -1;
		}
	}

	const int target_value = get_random_value(max);

	std::cout << "Hi! Enter your name, please:" << std::endl;
	std::cin >> username;
	
	std::cout << "Enter your guess:" << std::endl;

	do {
		attempts_count++;

		std::cin >> current_value;

		if (current_value < target_value) {
			std::cout << "greater than " << current_value << std::endl;
		}
		else if (current_value > target_value) {
			std::cout << "less than " << current_value << std::endl;
		}
		else {
			std::cout << "you win! attempts = " << attempts_count <<  std::endl << std::endl;
			break;
		}

	} while(true);

	update_table(file_name, username, attempts_count);

	print_table(file_name);


	return 0;
}