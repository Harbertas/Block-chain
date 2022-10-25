#pragma once
#include "header.h"
class Input //class used for storing input data from a file
{
	private:
		string row; //string to store read row
		string hashedRow; // string to store hashed row value
		string hashedRowSalt; // string to store hashed row + salt value
		vector<string> words; // vector type string to save row's words
		vector<string> hashedWords; //vector type string to save hashed words
	public:
		Input() {}; //construstor

		std::ifstream read(vector<Input>&, double&); //function to read data from a file

		inline void setRow(string r) { row = r; }; //setter
		inline void setWords(string w) { words.push_back(w); }; //setter
		inline void setHashedWords(string hw) { hashedWords.push_back(hw);}; //setter
		inline void setHashedRow(string hw) { hashedRow = hw; }; //setter
		inline void setHashedRowSalt(string hw) { hashedRowSalt = hw; }; //setter

		inline string getRow() const { return row; }; //getter
		inline string getWord(int& i) const { return words.at(i); }; //getter
		inline string getHashedWord(int& i) const { return hashedWords.at(i); }; //getter
		inline string getHashedRow() const { return hashedRow; }; //getter
		inline string getHashedRowSalt() const { return hashedRowSalt; }; //getter
		inline int getWordCount() const { return words.size();; }; //getter
		void hashRow(double&); //function to hashRow
		void hashRow(string); //function to hashRow
		void hashRowSalt(); //function to hashRow
		void hashRowSalt(string); //function to hashRow
		string decToHex(string); //function to convert row symbols to ASCII

		~Input(); //destructor
		Input(const Input&); //copy constructor
		Input& operator=(const Input& other); // assignment operator
};

string generateSalt();
void generate(int, int);
void generate(int);
double compare(string, string);
void checkCollision(vector<Input>&);
string hexToBin(string hexdec);

