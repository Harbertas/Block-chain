#pragma once

#include "Header.h"

class user
{
	protected:
		string name;
		string publicKey;
		double balance = 0;
	public:
		void setName(string n) { this->name = n; };
		void setPublicKey(string k) { this->publicKey = k; };
		void setBalance(double b) { this->balance = b; };
		const string getName() { return this->name; };
		const string getPublicKey() { return this->publicKey; };
		const double getBalance() { return this->balance; };
};

vector<user> generateUsers(int c);
void printUsers(vector<user>& users);
void printUsers(vector<user>& users, int a);

class transaction
{
	protected:
		string transactionID = "";
		string sender = "";
		string receiver = "";
		double sum = 0;
	public:
		transaction(string transactionID, string sender, string receiver, double sum);
		transaction() {};
		void setTransactionID(string id) { this->transactionID = id; };
		void setSender(string sen) { this->sender = sen; };
		void setReceiver(string rec) { this->receiver = rec; };
		void setSum(double amount) { this->sum = amount; };
		const string getTransactionID() { return this->transactionID; };
		const string getSender() { return this->sender; };
		const string getReceiver() { return this->receiver; };
		const double getSum() { return this->sum; };
		friend std::ostream& operator << (std::ostream& out, transaction& t);
};

vector<transaction> generateTransactions(vector<user>& users, int c);
void printTransactions(vector<transaction>& transactions);

class header
{
	protected:
		string hash;
		int height = 0;
		double timeStamp;
		string merkelRootHash;
		string prev_block_hash;
		string version = "0.2.1";
		uint64_t nonce;
		uint64_t diffTarget = 4;
	public:
		virtual void setTimeStamp(double timeStamp_) = 0;
		virtual void setHash(string h) = 0;
		virtual void setNonce(uint64_t n) = 0;
		virtual void setPrevBlockHash(string p) = 0;
		virtual void setMerkelRootHash(string p) = 0;
		virtual void setHeight(int h) = 0;
		virtual void setDiffTarget(int h) = 0;
};

class body
{
	protected:
		vector<transaction> tx;
		virtual void addTransaction(transaction tx_) = 0;
		virtual void setTransaction(vector<transaction> transactions) = 0;
};

class block : public header, public body, public transaction
{
	private:
		//option #1
		//block* previousBlock = NULL;
		//string previousBlockHash;
		//option #2
		//std::unordered_map<block*, string> hashPointer;
	public:
		//block* previous = NULL;
		block(string merkroot);
		block() {};
		~block();
		void addTransaction(transaction tx_) { tx.push_back(tx_); };
		const double getTimeStamp() { return this->timeStamp; };
		const int getHeight() { return this->height; };
		const string getVersion() { return this->version; };
		const string getMerkelRootHash() { return this->merkelRootHash; };
		const uint64_t getNonce() { return this->nonce; };
		const string getHash() { return this->hash; };
		const uint64_t getDiffTarget() { return this->diffTarget; };
		void setTransaction(vector<transaction> transactions) { this->tx = transactions; };
		void setTimeStamp(double timeStamp_) { this->timeStamp = timeStamp_; };
		void setPrevBlockHash(string p) { this->prev_block_hash = p; };
		void setHash(string h) { this->hash = h; };
		void setNonce(uint64_t n) { this->nonce = n; };
		void setMerkelRootHash(string m) { this->merkelRootHash = m; };
		void setHeight(int h) { this->height = h; };
		void setDiffTarget(int t) { this->diffTarget = t; };
		string computeMerkleRoot(vector<transaction> transactions);
		void showTransactions();
		void showBlockInfo();
};
class blockChain : protected block
{
	private:
		vector<block> bc;
		vector<transaction> unspent_transactions;
		vector<user> users;
	public:
		blockChain(vector<user> users, vector<transaction> transactions);
		~blockChain();
		const int getSize() { return bc.size(); };
		void mineGenesis();
		void mineAllBlocks();
		void deleteTransactionsFromPool(vector<transaction>& transactions);
		vector<transaction> chooseTransactionsFromPool();
		void checkTransactions(vector<transaction>& spent_transactions);
		void updateBalance(vector<transaction>& spent_transactions);
		void add(block b) { bc.push_back(b); };
		void showBlockInfo(int i) { if (i < bc.size() && i >= 0) bc.at(i).showBlockInfo(); else cout << "Block '" << i << "' hasn't been found yet. (try running 'mineBlocks')" << endl; };
		void showTransactions(int i) { if (i < bc.size() && i >= 0) bc.at(i).showTransactions(); else cout << "Block '" << i << "' hasn't been found yet. (try running 'mineBlocks')" << endl; };
		const string getBlockHash(int i) { return bc.at(i).getHash(); };
		user* getUser(string public_ip);
};

string merkelHash(vector<transaction>& transacations);

