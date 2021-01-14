/*
stock.cpp
Author: M00714688 
Created: 05/01/2021
Updated: 15/01/2021
*/

#include <iostream>
#include <stdio.h>
#include <process.h>
#include <fstream>
#include <stdlib.h>

class item
{
	int ItmNumber;
	char ItmName[30];
	float Price, Quantity;

public:
	// a function to get the data of the product
	void insertdata()
	{
		std::cout << "\nEnter The Item ID --> \t";
		std::cin >> ItmNumber;
		std::cout << "\nEnter The Name of The Item -->\t";
		std::cin >> ItmName;
		std::cout << "\nEnter The Price of The Item -->\t";
		std::cin >> Price;
		std::cout << "\nEnter The the Quantity of The Item -->\t";
		std::cin >> Quantity;
	}

	void restockitem()
	{
		std::cout << "\nEnter The the Quantity of The Item -->\t";
		std::cin >> Quantity;
	}

	// this function will show the data of the product
	void displaydata()
	{
		std::cout << "\n The Item ID : " << ItmNumber;
		std::cout << "\n The Name of The Item : " << ItmName;
		std::cout << "\n The Price of The Item : " << Price;
		std::cout << "\n The Quantity of The Item : " << Quantity;
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
	//string
	char *RetItmName()
	{
		return ItmName;
	}
};

// file handling to create file object
// I used the concept of modularity to write functions
// so that i can use them where ever to write to a file

std::fstream fileObject;
std::ofstream report;
item i;

void write_file()
{

	fileObject.open("store.txt", std::ios::app | std::ios::app);
	i.insertdata();
	fileObject.write((char *)&i, sizeof(i));
	fileObject.close();
	std::cout << "\n\nThe Iten Has Been Created";
}

// a function to read records from file
void display_all()
{

	std::cout << "\n\n\n\t\t All Records\n\n";
	fileObject.open("store.txt", std::ios::in);
	while (fileObject.read((char *)&i, sizeof(i)))
	{
		i.displaydata();
		std::cout << "\n\n============================\n";
	}

	fileObject.close();
}

// to add more to the stock
void restock()
{

	int number, found = 0;
	std::cout << "\n\nTo Restock";
	std::cout << "\n\n Please Enter the item id";
	std::cin >> number;
	fileObject.open("store.txt", std::ios::in | std::ios::out);
	while (fileObject.read((char *)&i, sizeof(i)) && found == 0)
	{
		if (i.RetItmNumber() == number)
		{
			i.displaydata();
			std::cout << "\nPleas Enter the New Detail of the Item" << std::endl;
			i.restockitem();
			int pos = -1 * ((int)sizeof(i));
			fileObject.seekp(pos, std::ios::cur);
			fileObject.write((char *)&i, sizeof(i));
			std::cout << "\n\nRecord Updated";
			found = 1;
		}
	}
	fileObject.close();
	if (found == 0)
		std::cout << "Record Not Found";
}

// this the menu function to diplay the menu of the items
void menu()
{

	fileObject.open("store.txt", std::ios::in);
	if (!fileObject)
	{
		std::cout << "ERROR ! file couldnt be open\n\n\n you need to creat an item ";
		std::cout << "\n\n\n program is closing";
		exit(0);
	}

	std::cout << "\n\n\n\t\t Item Menu\n\n";
	std::cout << "=====================================================\n";
	std::cout << "Item ID         NAME            Price        Quantity\n";
	std::cout << "=====================================================\n";

	while (fileObject.read((char *)&i, sizeof(i)))
	{
		std::cout << i.RetItmNumber() << "\t\t" << i.RetItmName() << "\t\t"
				  << i.RetPrice() << "\t\t" << i.RetQuantity() << std::endl;
	}
	fileObject.close();
}

// this function to sell products with generatig a recipet
void place_order()
{

	int sell[30], quantity[30], c = 0;
	float amt, total = 0;
	char ch = 'Y';
	menu();
	std::cout << "\n-------------";
	std::cout << "\n Sell Items ";
	std::cout << "\n-------------";
	do
	{
		std::cout << "\n\nEnter Item ID : \n";
		std::cin >> sell[c];
		std::cout << "\nEnter Quantity : \n";
		std::cin >> quantity[c];
		c++;
		std::cout << "\nPLace Another Item ?  (Y/N) \t";
		std::cin >> ch;

	} while (ch == 'y' || ch == 'Y');
	std::cout << "\n\n****************RECIPET***************\n";
	std::cout << "\nID    Name   Quantity   Price   Amount\n";
	for (int x = 0; x <= c; x++)
	{
		fileObject.open("store.txt", std::ios::in);
		fileObject.read((char *)&i, sizeof(i));
		while (!fileObject.eof())
		{
			if (i.RetItmNumber() == sell[x])
			{

				report.open("report.txt", std::ios::app | std::ios::app);
				amt = i.RetPrice() * quantity[x];

				std::cout << "\n"
						  << sell[x] << "      " << i.RetItmName() << "\t"
						  << quantity[x] << "\t" << i.RetPrice() << "\t" << amt;

				report << "\n"
					   << sell[x] << "      " << i.RetItmName() << "\t"
					   << quantity[x] << "\t" << i.RetPrice() << "\t" << amt;

				total += amt;
			}
			fileObject.read((char *)&i, sizeof(i));
		}
		fileObject.close();
	}
	std::cout << "\n\n\t\t\t\t Total = " << total;
	report.close();
}

// this function is to update the stock

void modify()
{

	int number, found = 0;
	std::cout << "\n\nTo Update the Stock Level";
	std::cout << "\n\n Please Enter the item id";
	std::cin >> number;
	fileObject.open("store.txt", std::ios::in | std::ios::out);
	while (fileObject.read((char *)&i, sizeof(i)) && found == 0)
	{
		if (i.RetItmNumber() == number)
		{
			i.displaydata();
			std::cout << "\nPleas Enter the New Detail of the Item" << std::endl;
			i.insertdata();
			int pos = -1 * ((int)sizeof(i));
			fileObject.seekp(pos, std::ios::cur);
			fileObject.write((char *)&i, sizeof(i));
			std::cout << "\n\nRecord Updated";
			found = 1;
		}
	}
	fileObject.close();
	if (found == 0)
		std::cout << "Record Not Found";
}
// this function will display the sold products
void viewreport()
{

	std::string items;
	std::ifstream viewreport("report.txt");
	std::cout << "\n\n\n\t\t Sold Items\n\n";
	std::cout << "======================================\n";
	std::cout << "ID    NAME   Quantity  Price  Total \n";
	std::cout << "======================================\n";

	while (getline(viewreport, items))

	{
		std::cout << items;
		std::cout << "\n";
	}
	viewreport.close();
}

int main()
{

	char ch;

	do
	{

		std::cout << "\n\n\n======================";
		std::cout << "\nStock Mangement System";
		std::cout << "\n======================";
		std::cout << "\n      Music Shop      ";
		std::cout << "\n======================";
		std::cout << "\n\n 1. Sell items";
		std::cout << "\n\n 2. Create items ";
		std::cout << "\n\n 3. Restock items";
		std::cout << "\n\n 4. Update Stock";
		std::cout << "\n\n 5. Reprot items";
		std::cout << "\n\n 6. Display items";
		std::cout << "\n\n 7. Exit";
		std::cout << "\n\n please select (1-7) = ";
		std::cin >> ch;
		switch (ch)
		{
		case '1':

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
			viewreport();
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