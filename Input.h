#pragma once
#include "header.h"
class Input
{
	private:
		vector<string> row;
		double timeTaken;
	public:
		inline double getTimeTaken() const { return timeTaken; };
		inline double setTimeTaken(double time) { this->timeTaken = time; };
		std::istream read(vector<string>& row);
};

