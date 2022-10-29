// sourec.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "header.h"
#include "block.h"
#include "input.h"


int main()
{
	//block* node = NULL;
	//node = new block;
	//tx.setTransactionID("16554");
	//node->setTransaction(tx);

	transaction tx;

	vector<user> users = generateUsers(1000);
	printUsers(users);
	//for (auto& us : users) {
	//	cout << us.getName() << endl;
	//	cout << us.getPublicKey() << endl;
	//	cout << us.getBalance() << endl;
	//}
	vector<transaction> transactions = generateTransactions(users, 10000);
	printTransactions(transactions);
	//for (auto& tx : transactions) {
		//cout << tx << endl;
	//}

	blockChain bc;
	block b;
	bc.mineGenesis();
	bc.showBlockInfo(0);

	string h = "hubertas";
	string blockHeader;


	//using hrClock = std::chrono::high_resolution_clock;
	//auto start = std::chrono::high_resolution_clock::now();
	//for(int i = 0; i < 10; i++)
	//{
	//	for (uint64_t nonce = 0; nonce < UINT64_MAX; ++nonce)
	//	{
	//		h = h + to_string(nonce);
	//		string hash = sha256(h);
	//		if (strncmp(hash.c_str(), "0000", 4) == 0) {
	//			b.setHash(hash);
	//			b.setNonce(nonce);
	//			break;
	//		}
	//		//if (i == 0)
	//			b.setPrevBlockHash("GENESIS");
	//		//else
	//			//b.setPrevBlockHash(bc.getBlockHash(i-1));
	//	}
	//	auto end = std::chrono::high_resolution_clock::now();
	//	std::chrono::duration<double> diff = end - start; // Skirtumas (s)
	//	b.setTimeStamp(diff.count());
	//	//for (int j = 0; j < 100; j++) 
	//		//b.addTransaction(tx);
	//	
	//	//b.showBlockInfo();
	//}
	
	//node->previous = new block;
	//node->previous->setTransaction(tx);
	//node->showTransactions();
	return 0;
}