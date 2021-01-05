#include <iostream>
#include <stdio.h>
#include <process.h>
#include <fstream>

using namespace std;

class item
{
	int ItmNumber;
	char ItmName[50];
	float Price;

public:
	// a class function to get the data
	void insertdata()
	{
		system("cls");
		cout << "\nEnter The Item Number --> \t";
		cin >> ItmNumber;
		cout << "\nEnter The Name of The Item -->\t";
		cin >> ItmName;
		cout << "\nEnter The Price of The Item -->\t";
		cin >> Price;
	}
	// this class will show the data
	void displaydata()
	{
		// system( _Command: "cls" );
		cout << "\n The Item Number : " << ItmNumber;
		cout << "\n The Name of The Item : " << ItmName;
		cout << "\n The Price of The Item : " << Price;
	}
	// a return function to return the private-
	//  data members to the calling function

	int RetItmNumber()
	{
		return ItmNumber;
	}

	float RetPrice()
	{
		return Price;
	}

	char *retItemName()
	{
		return ItmName;
	}
};

int main()
{
	char ch;
	do
	{
		system("cls");
		cout << "\n\n\n\t THE MENU";
		cout << "\n\n\t 1. CUSTOMER";
		cout << "\n\n\t 2. ADMIN";
		cout << "\n\n\t 3. EXIT";
		cout << "\n\n\t please select (1-3) \t";
		cin >> ch;
		switch (ch)
		{
		case '1': system("cls");
		break;
		case '2':
			exit(0);
	    break;

		default:
			cout << "\a";
		}
	} while (ch!= '3');
	return 0;
}