#pragma once
#include "header.h"
class Input //class used for storing input data from a file
{
	private:
		vector<string> rows; //vector to store read data by rows
		vector<int> singleRowWordCount; //vector to store count of each row's words
		double timeTaken; // variable to save time taken to read file data
	public:
		inline double getTimeTaken() const { return timeTaken; }; //getter
		inline double setTimeTaken(double time) { this->timeTaken = time; return this->timeTaken; }; //setter
		
		std::ifstream read(); //function to read data from a file
		void showRows(); //function to show read data

		int countRowWords(); //function to count how many words each row have
		void showWordsCount(); //function to show each row's word count


		~Input(); //destructor
};

