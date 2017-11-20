#include "RecInfo.h"

int main()
{
	RecInfo creditUnion("Alan", "Turning", 1000.00);

	unsigned int response = 0;
	cout << "*** Account Information System ***\n";

	while (response < 6)
	{
		cout << "Select one option below:\n";
		creditUnion.showOption();
		cout << "Enter your choice: ";
		cin >> response;

		if (cin.fail())
		{
			cerr << "Please enter a valid number\n";
			response = 0;
		}
	}


	system("pause");
	return 0;
}