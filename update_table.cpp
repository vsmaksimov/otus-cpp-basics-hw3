#include "update_table.h"

#include <iostream>
#include <fstream>


void update_table(const char * file_name, const std::string new_username, const int new_high_score) {
	std::ifstream in_file(file_name);
	const char * tmp_file_name = "tmp.txt";	
	std::ofstream tmp_file(tmp_file_name, std::ios_base::app);
	bool highScoreUpdated = false;

	if (in_file.good()) {
		if (!in_file.is_open()) {
			std::cout << "Failed to open file for read: " << file_name << "!" << std::endl;
			return;
		}

		if (!tmp_file.is_open()) {
			std::cout << "Failed to open file for write: " << tmp_file_name << "!" << std::endl;
			return;
		}

		std::string username;
		int high_score = 0;
		while(true) {
			in_file >> username;
			in_file >> high_score;
			in_file.ignore();


			if (in_file.fail()) {
				break;
			}

			if (username == new_username) {
				if (new_high_score < high_score) {
					tmp_file << username << " " << new_high_score << std::endl;
					highScoreUpdated = true;
				}
			} 
			else {
				tmp_file << username << " " << high_score << std::endl;
			}
		}

		if (!highScoreUpdated) {
			tmp_file << new_username << " " << new_high_score << std::endl;
		}

		in_file.close();
		tmp_file.close();

		remove(file_name);
	}
	else {
		if (!tmp_file.is_open()) {
			std::cout << "Failed to open file for write: " << tmp_file_name << "!" << std::endl;
			return;
		}

		tmp_file << new_username << " " << new_high_score << std::endl;
		tmp_file.close();
	}

	rename(tmp_file_name, file_name);
}