#include "Input.h"

std::ifstream Input::read() {
	string singleRow;
	auto start = std::chrono::high_resolution_clock::now();
	std::ifstream df("input.txt");
	while (df) {
		if (!df.eof()) {
			std::getline(df, singleRow);
			rows.push_back(singleRow);
		}
		else break;
	}
	df.close();
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff = end - start; // Skirtumas (s)
	setTimeTaken(diff.count());
	return df;
}
void Input::showRows() {
	string singleRow;
	for (auto &singleRow : rows) {
		cout << singleRow << endl;
	}
}
Input::~Input() {
	rows.clear();
}