#include "Input.h"


std::ifstream Input::read(vector<Input>& data, double& timeTaken)
{
	vector<string> rows;
	string singleRow;

	auto start = std::chrono::high_resolution_clock::now();

	std::ifstream df("input.txt");
	while (df)
	{
		if (!df.eof())
		{
			std::getline(df, singleRow);
			rows.push_back(singleRow);
		}
		else break;
	}
	df.close();

	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff = end - start; // Skirtumas (s)

	timeTaken = diff.count();

	Input temp;
	stringstream ss;
	string word;
	for (auto& singleRow : rows) 
	{
		ss.clear();
		ss.str("");
		ss << singleRow;
		temp.setRow(singleRow);
		while (!ss.eof()) {
			ss >> word;
			temp.setWords(word);
		}
		data.push_back(temp);
		temp.words.clear();
	}
	rows.clear();
	return df;
}

Input::~Input()
{
	words.clear();
	hashedWords.clear();
}

string decToHex(string word)
{
	int dec_num, r;
	string hexdec_num = "";
	for (auto it = word.end()-1; it >= word.begin(); it--) 
	{
		dec_num = (((int)*it)^8);
		char hex[] = { '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f' };
		while (dec_num > 0)
		{
			r = dec_num % 16;
			hexdec_num = hex[r] + hexdec_num;
			dec_num = dec_num / 16;
		}
	}
	return hexdec_num;
}

void Input::hashRow(double& timeTakenToConvert) {
	auto start = std::chrono::high_resolution_clock::now();
	for (auto& w : words)
	{
		//cout << w << endl;
		//cout << decToHex(w) << endl;
		setHashedWords(decToHex(w));
	}
	while (hashedRow.length() < 65) 
	{	
		for (auto& el : hashedWords) 
		{
			hashedRow += el;
		}
	}
	hashedRow.resize(64);
	setHashedRow(hashedRow);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff = end - start; // Skirtumas (s)

	timeTakenToConvert += diff.count();
}