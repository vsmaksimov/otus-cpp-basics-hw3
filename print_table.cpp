#include "print_table.h"

#include <iostream>
#include <fstream>

void print_table(const char * file_name) {
	std::ifstream in;

	in.open(file_name, std::ios_base::in);
	if (!in.is_open()) {
		std::cout << "File " << file_name << " is not open!" << std::endl;
		return;
	}


	std::cout << "High scores table:" << std::endl;

	std::string username;
	int high_score = 0;
	while(true) {	
		in >> username;
		in >> high_score;
		in.ignore();

		if (in.fail()) {
			break;
		}

		std::cout << username << "\t" << high_score << std::endl;
	}
}