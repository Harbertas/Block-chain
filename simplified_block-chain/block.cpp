#include "block.h"

//---------------
//  Transaction
//---------------

transaction::transaction(string transactionID, string sender, string receiver, double sum) {
	this->transactionID = transactionID;
	this->sender = sender;
	this->receiver = receiver;
	this->sum = sum;
}

/**Overloading << operator*/
std::ostream& operator << (std::ostream& out, transaction& t)
{
	out << "transactionID: " << t.transactionID << "\n"
		<< "transactionSender: " << t.sender << "\n"
		<< "transactionReceiver: " << t.receiver << "\n"
		<< "transactionSum: " << t.sum << "\n";
	return out;
}

/**DESTRUCTOR*/
transaction::~transaction() {
	//cout << "destructor called " << endl;
}

