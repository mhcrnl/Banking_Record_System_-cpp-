#ifndef RECINFO_H
#define RECINFO_H

#include <iostream>
#include <string>
#include <map>
#include <queue>

using namespace std;

class Customer
{
public:
	//Constructors
	Customer() : fName(""), lName(""), balance(0.0) {}
	Customer(string first, string last, double newBalance) : 
		fName(first), lName(last), balance(newBalance) {}

	//accessors
	string getFirst() const { return fName; }
	string getLast() const { return lName; }
	double getBalance() const { return balance; }

	//mutators
	void setFirst(string first) { fName = first; }
	void setLast(string last) { lName = last; }
	void setBalance(double newBalance) { balance = newBalance; }

	//Destructor
	~Customer(){}
private:
	string fName;
	string lName;
	double balance;
};

class RecInfo
{
public:
	RecInfo();

	RecInfo(const string& first, const string& last, 
		double balance);

	void showMenu();
	
	void showOption();

	void showOption(const map <unsigned int, string>& select);

	void addRecord(const string& first, const string& last, 
		double balance);

	void printData();

	unsigned int displayAndChoose();

	void search();

	void editRecord();

	void deleteRecord();

	void setName(int input, unsigned int acct);

	void setBalance(int input, unsigned int acct);

	~RecInfo();

private:
	//forward_list<int> data;
	map<unsigned int, Customer> dataBase;
	unsigned int acctNo = 0;
	queue<unsigned int> reuse;
	map<int, string> menu;
};
#endif

