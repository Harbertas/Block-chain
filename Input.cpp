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
	for (auto &singleRow : rows) {
		cout << singleRow << endl;
	}
}

int Input::countRowWords() {
	stringstream ss;
	string word = "";
	int count;
	for (auto& singleRow : rows) {
		ss.clear();
		ss.str("");
		ss << singleRow;
		count = 0;
		while (!ss.eof()) {
			ss >> word;
			//cout << word;
			count++;
		}
		singleRowWordCount.push_back(count);
		//cout << count;
		//cout << "\n";
	}
	return 0;
}

void Input::showWordsCount() {
	for (auto& cnt : singleRowWordCount) {
		cout << cnt << endl;
	}
}

Input::~Input() {
	rows.clear();
	singleRowWordCount.clear();
}