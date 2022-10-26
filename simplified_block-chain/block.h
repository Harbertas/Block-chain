#pragma once

#include "Input.h"

class user : public Input
{
	protected:
		string name;
		string publicKey;
		double balance;
};

class transaction : public user
{
	protected:
		string transactionID = "";
		string sender = "";
		string receiver = "";
		double sum = 0;
	public:
		transaction(string transactionID, string sender, string receiver, double sum);
		transaction() {};
		~transaction();
		void setTransactionID(string id) { this->transactionID = id; };
		void setSender(string sender) { this->sender = sender; };
		void setReceiver(string receiver) { this->receiver = receiver; };
		void setSum(double sum) { this->sum = sum; };
		friend std::ostream& operator << (std::ostream& out, transaction& t);
};

class header : public Input
{
	protected:
		std::string hash;
		int height;
		string timeStamp;
		string merkelRootHash;
		std::string prev_block_hash;
		std::string version;
		unsigned long long nonce;
		long long difficulty;
	public:
		virtual void setTimeStamp(string timeStamp_) = 0;
};

class body : public transaction
{
	protected:
		vector<transaction> tx;
		virtual void setTransaction(transaction tx_) = 0;
};

class block : public header, public body
{
	private:
		//option #1
		//block* previousBlock = NULL;
		//string previousBlockHash;
		//option #2
		//std::unordered_map<block*, string> hashPointer;
	public:
		block* previous = NULL;
		void setTransaction(transaction tx_) { tx.push_back(tx_); };
		void setTimeStamp(string timeStamp_) { timeStamp = timeStamp_; };
		void showTransactions() {
			for (auto transaction : tx) {
				cout << transaction << endl;
			}
		};
};

