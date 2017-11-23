#include "RecInfo.h"

int main()
{
	//Hast at least one person
	RecInfo creditUnion("Alan", "Turning", 1000.00);

	unsigned int response = 0;
	cout << "*** Account Information System ***\n";

	while (response < 6)
	{
		cout << "Select one option below:\n";
		creditUnion.showOption();
		cout << "Enter your choice: ";
		cin >> response;

		if (response == 1)
		{		
			cout << "Enter First Name: ";
			string first; cin >> first;

			cout << "Enter Last Name: ";
			string last; cin >> last;

			cout << "Enter Balance: ";
			double balance; cin >> balance;

			creditUnion.addRecord(first, last, balance);
			cout << "You are now in our database.\n";
		}
		else if (response == 2)
			creditUnion.printData();
		else if (response == 3)
			creditUnion.search();
		else if (response == 4)
			creditUnion.editRecord();
		else if (response == 5)
			creditUnion.deleteRecord();
		else
			cout << "\nThank you for choosing our bank.\n";
		
		string nextPrompt(40, '-');
		cout << "\n\n" << nextPrompt << "\n\n";
	}


	system("pause");
	return 0;
}