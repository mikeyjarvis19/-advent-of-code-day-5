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

int calculate_seat_id(int const& row_number, int const& column_number) {
	return (row_number * 8) + column_number;
}

int main() {
	std::vector <std::string> all_rows;
	std::ifstream file_contents("input.txt");
	std::string row_string;
	while (std::getline(file_contents, row_string)) {
		all_rows.push_back(row_string);
	}
	int highest_seat_id = 0;
	for (const auto& row : all_rows) {
		std::vector<int> row_nums;
		std::vector<int> column_nums;
		for (int i = 0; i < 128; i++) {
			row_nums.push_back(i);
		}
		for (int i = 0; i < 8; i++) {
			column_nums.push_back(i);
		}
		for (const auto& c : row) {
			if (c == 'F') {
				row_nums = take_lower_half(row_nums);
			}
			else if (c == 'B') {
				row_nums = take_upper_half(row_nums);
			}
			else if (c == 'L') {
				column_nums = take_lower_half(column_nums);
			}
			else if (c == 'R') {
				column_nums = take_upper_half(column_nums);
			}
		}
		auto row_number = row_nums[0];
		auto column_number = column_nums[0];
		auto seat_id = calculate_seat_id(row_number, column_number);
		if (seat_id > highest_seat_id) { highest_seat_id = seat_id; }
		std::cout << row_number << " " << column_number << " " << seat_id << "\n";
	}
	std::cout << "Highest seat ID: " << highest_seat_id;
}