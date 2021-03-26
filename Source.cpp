#include <vector>
#include <fstream>
#include <iostream>
#include <string>

template<typename T>
std::vector<T> slice(std::vector<T> const& v, int m, int n)
{
	auto first = v.cbegin() + m;
	auto last = v.cbegin() + n + 1;

	std::vector<T> vec(first, last);
	return vec;
}

std::vector<int> take_lower_half(std :: vector<int> const& row_numbers) {
	auto vector_size = row_numbers.size();
	std::vector<int> new_numbers = slice(row_numbers, 0, (vector_size / 2) - 1);
	return new_numbers;
}

std::vector<int> take_upper_half(std::vector<int> const& row_numbers) {
	auto vector_size = row_numbers.size();
	std::vector<int> new_numbers = slice(row_numbers, vector_size / 2, vector_size - 1);
	return new_numbers;
}

int main() {
	std::vector <std::string> all_rows;
	std::ifstream file_contents("input.txt");
	std::string row_string;
	while (std::getline(file_contents, row_string)) {
		all_rows.push_back(row_string);
	}
	//auto first_half = take_lower_half(row_nums);
	//auto second_half = take_upper_half(row_nums);
	for (const auto& row : all_rows) {
		std::vector<int> row_nums;
		for (int i = 0; i < 128; i++) {
			row_nums.push_back(i);
		}
		for (const auto& c : row) { //row
			if (c == 'F') {
				row_nums = take_lower_half(row_nums);
			}
			else if (c == 'B') {
				row_nums = take_upper_half(row_nums);
			}
		}
		int row_number = row_nums[0];
		int i = 1;
		std::cout << row_number << "\n";
	}
}