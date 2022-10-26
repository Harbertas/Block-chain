// sourec.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "header.h"
#include "block.h"
#include "input.h"

int main()
{
	block* node = NULL;
	node = new block;
	transaction tx{"123456","Hubertas","Harbertas", 10};
	tx.setTransactionID("16554");
	node->setTransaction(tx);
	//node->previous = new block;
	//node->previous->setTransaction(tx);
	node->showTransactions();
	return 0;
}