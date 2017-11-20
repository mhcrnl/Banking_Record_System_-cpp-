#include "RecInfo.h"

//Default Constructor
RecInfo::RecInfo()
{
	acctNo = 0;
}

//Overloaded Constructor
RecInfo::RecInfo(int account, 
	const string& first, const string& last, double balance)
{
	dataBase[account] = Customer(first, last, balance);
}


void RecInfo::addRecord()
{

}

void RecInfo::printData()
{

}

void RecInfo::search()
{

}

void RecInfo::editRecord()
{

}

void RecInfo::deleteRecord()
{

}

RecInfo::~RecInfo()
{

}

