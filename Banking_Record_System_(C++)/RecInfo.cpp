#include "RecInfo.h"
#include <iomanip>

//Default Constructor
RecInfo::RecInfo()
{
	dataBase[acctNo] = Customer();

	menu[1] = "Add Record to File";
	menu[2] = "Show Record from File";
	menu[3] = "Search Record from File";
	menu[4] = "Update Record";
	menu[5] = "Delete Rercord";
	menu[6] = "Exit";
}

//Overloaded Constructor
RecInfo::RecInfo(const string& first, const string& last,
	double balance)
{
	dataBase[acctNo] = Customer(first, last, balance);
	acctNo++;

	menu[1] = "Add Record to File";
	menu[2] = "Show Record from File";
	menu[3] = "Search Record from File";
	menu[4] = "Update Record";
	menu[5] = "Delete Rercord";
	menu[6] = "Exit";
}


void RecInfo::showOption()
{
	for (auto option : menu)
		cout << setw(8) << option.first << "-->" << option.second << endl;
}

void RecInfo::addRecord(const string& first, const string& last, 
	double balance)
{
	dataBase[acctNo] = Customer(first, last, balance);
	acctNo++;
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

