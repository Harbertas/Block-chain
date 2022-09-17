#pragma once
#include "header.h"
class Input //class used for storing input data from a file
{
	private:
		vector<string> rows; //vector to store read data by rows
		vector<int> singleRow; //vector to store row's text data converted into integer value
		double timeTaken; // variable to save time taken to read file data
	public:
		inline double getTimeTaken() const { return timeTaken; }; //getter
		inline double setTimeTaken(double time) { this->timeTaken = time; return this->timeTaken; }; //setter
		void showRows(); //function to show read data
		std::ifstream read(); //function to read data from a file
		~Input(); //destructor
};

