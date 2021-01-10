#include <iostream>
#include <stdio.h>
#include <process.h>
#include <fstream>
#include <stdlib.h>

using namespace std;

class item
{
	int ItmNumber;
	char ItmName[50];
	float Price, Quantity;

public:
	// a class function to get the data
	void insertdata()
	{
		// system("clear");
		cout << "\nEnter The Item ID --> \t";
		cin >> ItmNumber;
		cout << "\nEnter The Name of The Item -->\t";
		cin >> ItmName;
		cout << "\nEnter The Price of The Item -->\t";
		cin >> Price;
		cout << "\nEnter The the Quantity of The Item -->\t";
		cin >> Quantity;
	}

	void restockitem()
	{
		cout << "\nEnter The the Quantity of The Item -->\t";
		cin >> Quantity;
	}

	// this class will show the data
	void displaydata()
	{
		//ofstream stockfile;
		// stockfile.open("stock.txt",std::ios_base::app);
		//system("clear");
		cout << "\n The Item ID : " << ItmNumber;
		cout << "\n The Name of The Item : " << ItmName;
		cout << "\n The Price of The Item : " << Price;
		cout << "\n The Quantity of The Item : " << Quantity;
		//stockfile << ItmNumber;
		// stockfile << ItmName  ;
		//stockfile << Price ;
		//stockfile << Quantity ;
		//stockfile << "\n";
		//stockfile.close();
	}
	
	//a return function to return the private-
	//data members to the calling function

	int RetItmNumber()
	{
		return ItmNumber;
	}

	float RetPrice()
	{
		return Price;
	}

	float RetQuantity()
	{
		return Quantity;
	}

	char *RetItmName()
	{
		return ItmName;
	}

	// the end of the class
};

// declare for stream ojects - global
fstream f;
item i;

void write_file()
{

	f.open("store.txt", ios::app | ios::app);
	i.insertdata();
	f.write((char *)&i, sizeof(i));
	f.close();
	cout << "\n\nThe Iten Has Been Created";
}

// a function to read records from file
void display_all()
{
	//  system("clear")
	cout << "\n\n\n\t\t All Records\n\n";
	f.open("store.txt", ios::in);
	while (f.read((char *)&i, sizeof(i)))
	{
		i.displaydata();
		cout << "\n\n============================\n";
	}

	f.close();
}

// to add more to the stock
void restock()
{
	int no, found = 0;
	cout << "\n\nTo modify";
	cout << "\n\n Please Enter the item id";
	cin >> no;
	f.open("store.txt", ios::in | ios::out);
	while (f.read((char *)&i, sizeof(i)) && found == 0)
	{
		if (i.RetItmNumber() == no)
		{
			i.displaydata();
			cout << "\nPleas Enter the New Detail of the Item" << endl;
			i.restockitem();
			int pos = -1 * ((int)sizeof(i));
			f.seekp(pos, ios::cur);
			f.write((char *)&i, sizeof(i));
			cout << "\n\nRecord Updated";
			found = 1;
		}
	}
	f.close();
	if (found == 0)
		cout << "Record Not Found";
}

void menu()
{
	//system("clear");
	f.open("store.txt", ios::in);
	if (!f)
	{
		cout << "ERROR ! file couldnt be open\n\n\n you need to creat an item ";
		cout << "\n\n\n program is closing";

		exit(0);
	}

	cout << "\n\n\n\t\t Item Menu\n\n";
	cout << "=====================================================\n";
	cout << "Item ID         NAME            Price        Quantity\n";
	cout << "=====================================================\n";

	while (f.read((char *)&i, sizeof(i)))
	{
		cout << i.RetItmNumber() << "\t\t" << i.RetItmName() << "\t\t" << i.RetPrice() << "\t\t" << i.RetQuantity() << endl;
	}
	f.close();
}

//  a function to place an order

void place_order()
{
	//	system("clear");
	int sell[50], quantity[50], c = 0;
	float amt, total = 0;
	char ch = 'Y';
	menu();
	cout << "\n-------------";
	cout << "\n Sell Items ";
	cout << "\n-------------";
	do
	{
		cout << "\n\nEnter Item ID : \n";
		cin >> sell[c];
		cout << "\nEnter Quantity : \n";
		cin >> quantity[c];
		c++;
		cout << "\nPLace Another Item ?  (Y/N) \t";
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	// system("clear");
	cout << "\n\n****************RECIPET***************\n";
	cout << "\nID    Name   Quantity   Price   Amount\n";
	for (int x = 0; x <= c; x++)
	{
		f.open("store.txt", ios::in);
		f.read((char *)&i, sizeof(i));
		while (!f.eof())
		{
			if (i.RetItmNumber() == sell[x])
			{
				amt = i.RetPrice() * quantity[x];

				cout << "\n"
					 << sell[x] << "      " << i.RetItmName() << "\t" << quantity[x] << "\t" << i.RetPrice() << "\t" << amt;
				total += amt;
			}
			f.read((char *)&i, sizeof(i));
		}
		f.close();
	}
	cout << "\n\n\t\t\t\t Total = " << total;
}

// this function is to update the stock 
void modify()
{
	int no, found = 0;
	cout << "\n\nTo modify";
	cout << "\n\n Please Enter the item id";
	cin >> no;
	f.open("store.txt", ios::in | ios::out);
	while (f.read((char *)&i, sizeof(i)) && found == 0)
	{
		if (i.RetItmNumber() == no)
		{
			i.displaydata();
			cout << "\nPleas Enter the New Detail of the Item" << endl;
			i.insertdata();
			int pos = -1 * ((int)sizeof(i));
			f.seekp(pos, ios::cur);
			f.write((char *)&i, sizeof(i));
			cout << "\n\nRecord Updated";
			found = 1;
		}
	}
	f.close();
	if (found == 0)
		cout << "Record Not Found";
}

int main()
{
	char ch;

	do
	{
		//system("clear");
		cout << "\n\n\n======================";
		cout << "\nStock Mangement System";
		cout << "\n======================";
		cout << "\n      Music Shop      ";
		cout << "\n======================";
		cout << "\n\n 1. Sell items";
		cout << "\n\n 2. Create items ";
		cout << "\n\n 3. Restock items";
		cout << "\n\n 4. Update Stock";
		cout << "\n\n 5. Display items";
		cout << "\n\n 6. Items menu ";
		cout << "\n\n 7. Exit";
		cout << "\n\n please select (1-7) = ";
		cin >> ch;
		switch (ch)
		{
		case '1':
			// system("clear");
			place_order();
			break;

		case '2':
			write_file();
			break;

		case '3':
			restock();
			break;

		case '4':
			modify();
			break;

		case '5':
			display_all();
			break;

		case '6':
			menu();
			break;

		case '7':
			int main();
			break;
		}
	} while (ch != '7');
	return 0;
}