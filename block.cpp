#include "block.h"

//---------------
//    User
//---------------

vector<user> generateUsers(int c)
{
	using hrClock = std::chrono::high_resolution_clock;
	std::mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
	std::uniform_int_distribution<int> rnd(100, 10000);
	vector<user> users;
	user person;
	for (int i = 0; i < c; i++) {
		person.setName("user" + to_string(i+1));
		person.setPublicKey(sha256(person.getName()));
		person.setBalance(rnd(mt));
		users.push_back(person);
	}
	return users;
}

void printUsers(vector<user>& users)
{
	string file = "users" + to_string(users.size()) + ".txt";
	stringstream buffer;
	std::ofstream rf;
	rf.open(file);
	buffer << std::left << std::setw(10) << "Name" << std::left << std::setw(67) << "Public_key" << "Balance" << endl;
	buffer << "------------------------------------------------------------------------------------" << endl;
	for (auto& ux : users)
	{
		buffer << std::left << std::setw(10) << ux.getName() << std::left << std::setw(67) << ux.getPublicKey() << ux.getBalance();
		if (users.at(users.size() - 1).getPublicKey() != ux.getPublicKey())
			buffer << endl;
	}
	rf << buffer.str();
	buffer.clear();
	buffer.str("");
	rf.close();
}

void printUsers(vector<user>& users, int a)
{
	string file = "users" + to_string(users.size()) + "_.txt";
	stringstream buffer;
	std::ofstream rf;
	rf.open(file);
	buffer << std::left << std::setw(10) << "Name" << std::left << std::setw(67) << "Public_key" << "Balance" << endl;
	buffer << "------------------------------------------------------------------------------------" << endl;
	for (auto& ux : users)
	{
		buffer << std::left << std::setw(10) << ux.getName() << std::left << std::setw(67) << ux.getPublicKey() << ux.getBalance();
		if (users.at(users.size() - 1).getPublicKey() != ux.getPublicKey())
			buffer << endl;
	}
	rf << buffer.str();
	buffer.clear();
	buffer.str("");
	rf.close();
}

//---------------
//  Transaction
//---------------

vector<transaction> generateTransactions(vector<user>& users, int c)
{
	using hrClock = std::chrono::high_resolution_clock;
	std::mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
	std::uniform_int_distribution<int> rnd(100, 10000);
	std::uniform_int_distribution<int> ux(1, users.size()-1);
	vector<transaction> transactions;
	transaction tx;
	string id;
	for (int i = 0; i < c; i++) {
		int sender = ux(mt);
		tx.setSender(users.at(sender).getPublicKey());
		int receiver = ux(mt);
		tx.setReceiver(users.at(receiver).getPublicKey());
		std::uniform_int_distribution<int> sn(0, users.at(sender).getBalance());
		tx.setSum(sn(mt));
		tx.setTransactionID(sha256(tx.getSender() + tx.getReceiver() + to_string(tx.getSum())));
		transactions.push_back(tx);
	}
	return transactions;
}

void printTransactions(vector<transaction>& transactions)
{
	string file = "transactions" + to_string(transactions.size()) + ".txt";
	stringstream buffer;
	std::ofstream rf;
	rf.open(file);
	buffer << std::left << std::setw(67) << "transactionID" << std::left << std::setw(67) << "transactionSender" << std::left << std::setw(67) << "transactionReceiver" << "transactionSum" << endl;
	buffer << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	for (auto& tx : transactions)
	{
		buffer << std::left << std::setw(67) << tx.getTransactionID() << std::left << std::setw(67) << tx.getSender() << std::left << std::setw(67) << tx.getReceiver() << tx.getSum();
		if (transactions.at(transactions.size() - 1).getTransactionID() != tx.getTransactionID())
			buffer << endl;
	}
	rf << buffer.str();
	buffer.clear();
	buffer.str("");
	rf.close();
}

transaction::transaction(string transactionID, string sender, string receiver, double sum)
{
	this->transactionID = transactionID;
	this->sender = sender;
	this->receiver = receiver;
	this->sum = sum;
}

/**Overloading << operator*/
std::ostream& operator << (std::ostream& out, transaction& t)
{
	out << "ID: " << t.transactionID << "\n"
		<< "Sender: " << t.sender << "\n"
		<< "Receiver: " << t.receiver << "\n"
		<< "Sum: " << t.sum << "\n";
	return out;
}

//---------------
//     Block
//---------------

block::block(string merkroot) 
{
	this->height = 0;
	this->merkelRootHash = merkroot;
	this->prev_block_hash = "NONE";
	this->version = "0.2.1";
}

void block::showTransactions() 
{
	cout << endl;
	for (auto& transaction : tx) {
		cout << transaction << endl;
	}
};

void block::showBlockInfo()
{
	cout << "Hash: " << header::hash << endl;
	cout << "Height: " << header::height << endl;
	cout << "Time taken to mine: " << header::timeStamp << "s" << endl;
	cout << "Version: " << header::version << endl;
	cout << "Nonce: " << header::nonce << endl;
	cout << "Merkle root: " << header::merkelRootHash << endl;
	cout << "Previous block hash: " << header::prev_block_hash << endl;
	//showTransactions();
}

/**DESTRUCTOR*/
block::~block()
{
	body::tx.clear();
}

//---------------
//   BlockChain
//---------------

blockChain::blockChain(vector<user> users, vector<transaction> transactions) 
{
	this->unspent_transactions = transactions;
	this->users = users;
}

blockChain::~blockChain()
{
	this->bc.clear();
	this->unspent_transactions.clear();
	this->users.clear();
}

vector<transaction> blockChain::chooseTransactions() 
{
	vector<transaction> spent_transactions;
	spent_transactions.reserve(100);
	int count = 0;
	for (auto it = unspent_transactions.end()-1; it >= unspent_transactions.begin(); --it)
	{
		spent_transactions.push_back(*it);
		unspent_transactions.pop_back();
		count++;
		if (count == 100) break;
	}
	return spent_transactions;
}

string merkelHash(vector<transaction>& transacations)
{
	string merkelRootHash;
	for (auto& t : transacations) 
	{
		merkelRootHash += t.getTransactionID();
	}
	return sha256(merkelRootHash);
}

void blockChain::updateBalance(vector<transaction>& spent_transactions)
{
	for (auto& us : users) 
	{
		for (auto& st : spent_transactions)
		{
			if (st.getSum() <= us.getBalance())
			{
				if (us.getPublicKey() == st.getSender())
					us.setBalance(us.getBalance() - st.getSum());
				else if (us.getPublicKey() == st.getReceiver())
					us.setBalance(us.getBalance() + st.getSum());
			}
			
		}
	}
}

void blockChain::mineGenesis()
{
	if (bc.size() == 0)
	{
		transaction tx{ sha256("Coinbasehubertas50"), "Coinbase", "hubertas", 50 };
		block b{ sha256("Coinbasehubertas50") };
		uint64_t nonceG = 0;
		string hash = sha256("GENESIS" + to_string(b.getTimeStamp()) + b.getVersion() + b.getMerkelRootHash() + to_string(nonceG));
		using hrClock = std::chrono::high_resolution_clock;
		auto start = std::chrono::high_resolution_clock::now();
		while (strncmp(hash.c_str(), "00000", 5) != 0)
		{
			hash = sha256("GENESIS" + to_string(b.getTimeStamp()) + b.getVersion() + b.getMerkelRootHash() + to_string(nonceG));
			b.setHash(hash);
			b.setNonce(nonceG);
			nonceG++;
		}
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> diff = end - start; // Skirtumas (s)
		b.setTimeStamp(diff.count());
		b.addTransaction(tx);
		add(b);
	}
}

void blockChain::mineAllBlocks()
{
	if (unspent_transactions.size() == 0)
		cout << "There are no blocks to mine (empty transaction pool)" << endl;
	else 
	{
		if (bc.size() != 0)
		{
			showBlockInfo(0);
			while (this->unspent_transactions.size() > 0)
			{
				//cout << "unspent_transactions.size() " << unspent_transactions.size() << endl;
				int chainSize = bc.size();
				block prevBlock = bc.at(chainSize - 1);
				vector<transaction> spent_transactions = chooseTransactions();
				block newBlock;
				string headerHash = sha256(prevBlock.getHash() + to_string(prevBlock.getTimeStamp()) + prevBlock.getVersion() + prevBlock.getMerkelRootHash() + to_string(prevBlock.getNonce()));;
				uint64_t nonceG = 0;
				using hrClock = std::chrono::high_resolution_clock;
				auto start = std::chrono::high_resolution_clock::now();

				while (true)
				{
					if (strncmp(headerHash.c_str(), "0000", 4) == 0)
					{
						newBlock.setHash(headerHash);
						newBlock.setPrevBlockHash(prevBlock.getHash());
						newBlock.setHeight(chainSize);
						newBlock.setNonce(nonceG);
						newBlock.setMerkelRootHash(merkelHash(spent_transactions));
						break;
					}
					else
					{
						nonceG++;
						headerHash = sha256(prevBlock.getHash() + to_string(prevBlock.getTimeStamp()) + prevBlock.getVersion() + prevBlock.getMerkelRootHash() + to_string(nonceG));
					}
				}
				auto end = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double> diff = end - start; // Skirtumas (s)
				newBlock.setTimeStamp(diff.count());

				updateBalance(spent_transactions);
				newBlock.setTransaction(spent_transactions);

				cout << endl;
				newBlock.showBlockInfo();
				bc.push_back(newBlock);
				newBlock.~block();

			}
			printUsers(users, 1);
		}
		else
			cout << "Mine genesis block first (use mineGenesis)" << endl;
	}
}