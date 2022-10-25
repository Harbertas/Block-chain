#pragma once

#include "Input.h"

class user 
{
	protected:
		string name;
		string publicKey;
		double balance;
};

class transaction : public user
{
	protected:
		string transactionID;
		string sender;
		string receiver;
		double sum;
};

class header
{
	protected:
		string timeStamp;
		string version;
		string merkelRootHash;
		long long int nonce;
		long long int difficulty;
		virtual void setTimeStamp(string timeStamp_) = 0;
};

class body : public transaction
{
	protected:
		vector<transaction> tx;
		//virtual void setTransaction(transaction tx_) = 0;
};

class block : public header, public body
{
	private:
		//option #1
		block* previousBlock = NULL;
		string previousBlockHash;
		//option #2
		std::unordered_map<block*, string> hashPointer;
	public:
		void setTransaction(transaction tx_) { tx.push_back(tx_); };
		void setTimeStamp(string timeStamp_) { timeStamp = timeStamp_; };
};

