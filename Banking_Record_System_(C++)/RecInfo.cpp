#include "RecInfo.h"
#include <iomanip>

//Default Constructor
RecInfo::RecInfo()
{
	dataBase[acctNo] = Customer();
}

//Overloaded Constructor
RecInfo::RecInfo(const string& first, const string& last,
	double balance)
{
	dataBase[acctNo] = Customer(first, last, balance);
	acctNo++;
}

void RecInfo::showMenu()
{
	menu[1] = "Add Record to File";
	menu[2] = "Show Record from File";
	menu[3] = "Search Record from File";
	menu[4] = "Update Record";
	menu[5] = "Delete Rercord";
	menu[6] = "Exit";
}

void RecInfo::showOption()
{
	showMenu();
	for (auto option : menu)
		cout << setw(8) << option.first << "-->" << option.second << endl;
}


void RecInfo::showOption(const map <unsigned int, string>& select)
{
	for (auto option : select)
		cout << setw(8) << option.first << "-->" << option.second << endl;
}

/*
For this feature void read_data() function
has been used to add banking record into the file.

It asks for information 
such as account number, first name, last name and balance 
to be entered.
*/
void RecInfo::addRecord(const string& first, const string& last, 
	double balance)
{
	if (reuse.empty())
	{
		dataBase[acctNo] = Customer(first, last, balance);
		acctNo++;
	}
	else
	{
		dataBase[reuse.front()] = Customer(first, last, balance);
		reuse.pop();
	}

}


/*
With the information provided in add record,
the void show_data() function 
in this banking record system project in C++ 

show the record corresponding 
to a particular account number, first name and last name.
Current balance of the account holder is displayed.
*/
void RecInfo::printData()
{
	cout << "Enter record number to display customer: ";

	unsigned int acct;
	cin >> acct;

	if (dataBase.find(acct) != dataBase.cend())
	{
		cout << "Account No. : " << acct << endl;
		cout << "Name: " << dataBase[acct].getLast() << ", "
			<< dataBase[acct].getFirst() << endl;
		cout << "Current Balance: " << dataBase[acct].getBalance() << endl;
	}
	else
		cerr << "Error in opening! File Not Found!!\n";
}

unsigned int RecInfo::displayAndChoose()
{
	cout << "There are " << dataBase.size() << " record(s) in file.\n";

	cout << "Displaying all accounts: \n";
	for (auto accout : dataBase)
		cout << "Accout No. " << accout.first << endl;

	cout << "Enter record number to search: ";

	unsigned int acct;
	cin >> acct;

	return acct;
}

/*
When the function for this feature is first executed, 
it shows the total records in the file,
and the user can then search by record number.

If the record searched for is not found, 
the banking record system project in C++ displays the message 
– “Error in opening! File Not Found!!”
*/
void RecInfo::search()
{
	unsigned int acct = displayAndChoose();

	if (dataBase.find(acct) != dataBase.cend())
		cout << "User exist in our database. " 
		<< "For more information, please choose 2.";
	else
		cerr << "Error in opening! File Not Found!!\n";
}


/*
This works in similar manner to the Search feature.

When the function for Edit Record is first executed,
it shows the total records in the file, 
and the user can edit the information by providing record number.
Then, the C++ project shows all the data in that record, 
and the user can enter any data to modify.

If the record to be edited for is not found, 
it displays the message – “Error in opening! File Not Found!!”
*/
void RecInfo::editRecord()
{
	unsigned int acct = displayAndChoose();

	if (dataBase.find(acct) != dataBase.cend())
	{
		cout << "Please select data that you would like to modify:\n";
		map<unsigned int, string> editMenu;
		editMenu[1] = "First Name";
		editMenu[2] = "Last Name";
		editMenu[3] = "Balance";
		editMenu[4] = "Edit all";
		showOption(editMenu);

		unsigned int input;
		cout << "\nEnter data to modify: \n";
		cin >> input;

		if (input == 1 || input == 2)
			setName(input, acct);
		else if (input == 3)
			setBalance(input, acct);
		else
		{
			setName(input, acct);
			setBalance(input, acct);
		}

	}
	else
		cerr << "Error in opening! File Not Found!!\n";

}

/*
First of all, when the function of this feature is executed, 
it shows all the records in the file, 
and the user can enter the record number to delete. 

If the record was not found,
this banking record system project in C++ displays the message
– “Error in opening! File Not Found!!”
*/
void RecInfo::deleteRecord()
{
	unsigned int acct = displayAndChoose();

	if (dataBase.find(acct) != dataBase.cend())
	{
		cout << "Please select data that you would like to remove: \n";
		unsigned int removeAcct;
		cin >> removeAcct;
		dataBase.erase(removeAcct);
		reuse.push(acct);
	}
	else
		cerr << "Error in opening! File Not Found!!\n";
}

void RecInfo::setName(int input, unsigned int acct)
{
	string newFirst, newLast;


	if (input == 1)
	{
		cout << "Enter new first name: ";
		cin >> newFirst;
		dataBase[acct].setFirst(newFirst);
	}
	else if (input == 2)
	{
		cout << "Enter new last name: ";
		cin >> newLast;
		dataBase[acct].setLast(newLast);
	}
	else
	{
		cout << "Enter both names: ";
		cout << "First Name: ";
		cin >> newFirst;
		cout << "Last Name: ";
		cin >> newLast;

		dataBase[acct].setFirst(newFirst);
		dataBase[acct].setLast(newLast);
	}
}

void RecInfo::setBalance(int input, unsigned int acct)
{
	cout << "Press 1 for deposit, and otherwise for withdrawal: ";
	int depOrWit;
	cin >> depOrWit;
	
	cout << "How much would you like to deposit/withdraw? ";
	double amount;
	cin >> amount;

	if (depOrWit == 1)
	{
		cout << "You deposited $" << amount << endl;
		amount += dataBase[acct].getBalance();
		dataBase[acct].setBalance(amount);
	}
	else
	{
		cout << "You withdrew $" << amount << endl;
		amount -= dataBase[acct].getBalance();
		dataBase[acct].setBalance(amount);
	}

}

RecInfo::~RecInfo()
{
	dataBase.clear();
	menu.clear();
}

