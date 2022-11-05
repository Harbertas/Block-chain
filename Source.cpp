// sourec.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "header.h"
#include "block.h"


int main()
{
	//block test;
	//vector<transaction> tx;
	//transaction ts;
	//string sender = "hubertas1";
	//string receiver = "hubertas2";
	//double sum = 10;
	//ts.setSender(sender);
	//ts.setReceiver(receiver);
	//ts.setSum(sum);
	//ts.setTransactionID(sha256(sender + receiver + to_string(sum)));
	//tx.push_back(ts);
	//sender = "haroldas1";
	//receiver = "haroldas2";
	//sum = 20;
	//ts.setTransactionID(sha256(sender + receiver + to_string(sum)));
	//tx.push_back(ts);
	//cout << test.computeMerkleRoot(tx) << endl;
	//cout << sha256(tx.at(0).getTransactionID() + tx.at(1).getTransactionID()) << endl;
	//block* node = NULL;
	//node = new block;
	//tx.setTransactionID("16554");
	//node->setTransaction(tx);

	//transaction tx;

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

	blockChain bc{users, transactions};
	block b;
	//bc.mineGenesis();
	//bc.showBlockInfo(0);
	//cout << endl;
	//bc.mineAllBlocks();
	string input;
	cout << "----------------------------------------" << endl;
	cout << "Here are the list of available commands: " << endl;
	cout << "----------------------------------------" << endl;
	cout << std::left << std::setw(21) << "mineGenesis" << " -> To mine GENESIS block" << endl;
	cout << std::left << std::setw(21) << "mineBlocks" << " -> To mine all possible blocks (untill there are unspent transactions)" << endl;
	cout << std::left << std::setw(21) << "showBlockInfo" << " -> To show specific block info" << endl;
	cout << std::left << std::setw(21) << "showBlockTx" << " -> To show all the transactions in the block" << endl;
	cout << std::left << std::setw(21) << "showBlockChainSize" << " -> To show current block-chain size (how many blocks are in the block-chain)" << endl;
	cout << std::left << std::setw(21) << "0" << " -> To finish running the program" << endl;
	cout << "----------------------------------------" << endl;
	cin >> input;
	while (input != "0")
	{
		if (input == "help") 
		{
			cout << "----------------------------------------" << endl;
			cout << "Here are the list of available commands: " << endl;
			cout << "----------------------------------------" << endl;
			cout << std::left << std::setw(21) << "mineGenesis" << " -> To mine GENESIS block" << endl;
			cout << std::left << std::setw(21) << "mineBlocks" << " -> To mine all possible blocks (untill there are unspent transactions)" << endl;
			cout << std::left << std::setw(21) << "showBlockInfo" << " -> To show specific block info" << endl;
			cout << std::left << std::setw(21) << "showBlockTx" << " -> To show all the transactions in the block" << endl;
			cout << std::left << std::setw(21) << "showBlockChainSize" << " -> To show current block-chain size (how many blocks are in the block-chain)" << endl;
			cout << std::left << std::setw(21) << "0" << " -> To finish running the program" << endl;
			cout << "----------------------------------------" << endl;
			cin >> input;
		}
		else if (input == "mineBlocks") 
		{
			cout << '\n';
			bc.mineAllBlocks();
			cout << '\n';
			cin >> input;
		}
		else if(input == "mineGenesis")
		{
			cout << '\n';
			bc.mineGenesis();
			//bc.showBlockInfo(0);
			cout << '\n';
			cin >> input;
		}
		else if (input == "showBlockChainSize")
		{
			cout << '\n';
			cout << "Current block-chain size: " << bc.getSize() << endl;
			cout << '\n';
			cin >> input;
		}
		else if (input == "showBlockInfo")
		{
			cout << '\n';
			int number;
			cout << "Which block info to show? (height)" << endl;
			cin >> number;
			while (cin.fail()) 
			{
				cin.clear();
				cin.ignore();
				cin >> number;
			}
			cout << '\n';
			bc.showBlockInfo(number);
			cout << '\n';
			cin >> input;
		}
		else if (input == "showBlockTx")
		{
			cout << '\n';
			int number;
			cout << "Which block transactions to show? (height)" << endl;
			cin >> number;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore();
				cin >> number;
			}
			cout << '\n';
			bc.showTransactions(number);
			cout << '\n';
			cin >> input;
		}
		else
		{
			cout << '\n';
			cout << "Not a command! try 'help'" << endl;
			cout << '\n';
			cin >> input;
		}
	}

	// FOR TESTING
	//    | 
	//    |
	//   /|\
	//   \|/
	//    . 

		//bc.showTransactions(10);
	
		//string h = "hubertas";
		//string blockHeader;


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