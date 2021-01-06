#include <iostream>
#include <stdio.h>
#include <process.h>
#include <fstream>

#include <stdlib.h>
using namespace std;

class item
{
	int ItmNumber;
	char ItmName[100];
	float Price,quantity;

public:
	// a class function to get the data
	void insertdata()
	{
		 system("clear");
		cout << "\nEnter The Item ID or Name --> \t";
		cin >> ItmNumber;
		cout << "\nEnter The Name of The Item -->\t";
		cin >> ItmName;
		cout << "\nEnter The Price of The Item -->\t";
		cin >> Price;
	}
	// this class will show the data
	void displaydata()
	{
		system("clear");
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

	char *retItmName()
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
	   f.open("stroe.dat",ios::out|ios::app);
	   i.insertdata();
	   f.write((char*)&i,sizeof(i));
	   f.close();
	   cout<<"\n\nThe Iten Has Benn Created";

}
// a function to read records from file
void display_all()
{
	system("clear");
	cout<<"\n\n\n\t\tDisplay All Records\n\n";
	f.open("store.dat",ios::in);
	while(f.read((char*)&i,sizeof(i)));
	{
		i.displaydata();
		cout<<"\n\n============================\n";
	

	}
	f.close();
}
// to read from a specific record from a file
void display_specific(int n)
{
 int flag=0;
 f.open("store.dat",ios::in);
 while(f.read((char*)&i,sizeof(i)));
 {
	if(i.RetItmNumber()==n)
	{
		system("clear");
		i.displaydata();
		flag=1;
	}
 }
 f.close();
 if(flag==0)
 cout<<"\n\nThere is no Record";
 
}


// a function to place an order
void place_order()
{
	 system("clear");

	int sell[100], quantity[100],c=0;
	float amt,damt,total=0;
	char ch='Y';
	cout<<"\n-------------";
	cout<<"\n  Sell Items ";
	cout<<"\n-------------";
	do
	{
		cout<<"\n\n Enter Item ID : \n";
		cin>>sell[c];
		cout<<"\n Enter Quantity : \n";
		cin>>quantity[c];
		c++;
		cout<<"\n PLace Another Item ?  (Y/N) \t";
		cin>>ch;
	} while (ch=='Y'   ||ch=='N');
	//  system("clear");
	cout<<"\n\n *******RECIPET******\n";
	cout<<"\nItem No.\tName\tQuantity \tPrice \tAmount\n";
	for(int x=0;x<=c;x++)
	{
		f.open("store.dat",ios::in);
		f.read((char*)&i,sizeof(i));
		while(!f.eof())
		{
			if(i.RetItmNumber()==sell[x])
			{
				amt=i.RetPrice()*quantity[x];
				cout<<"\n"<<sell[x]<<"\t"<<i.RetItmNumber()<<"\t"<<quantity[x]<<"\t\t"<<i.RetPrice()<<"\t"<<amt<<"\t\t"<<damt;
                total+=damt;
			}
			f.read((char*)&i,sizeof(i));
		}
		f.close();

	}
	cout<<"\n\n\t\t\t\t\t\t Total = " <<total;
}

int main()
{
	
		 system("clear");
		char ch;
		cout << "\n\n\n\t Stock Mangement System";
		cout << "\n\n\t 1. Sell items";
		cout << "\n\n\t 2. Add new items ";
		cout << "\n\n\t 5. Display items";
		cout << "\n\n\t 3. Restock items";
		cout << "\n\n\t 4. Modify items ";
		cout << "\n\n\t 6. Delete items";
		cout << "\n\n\t 7. Exit";
		cout << "\n\n\t please select (1-7) \t";
		cin >> ch;
		switch (ch)
		{
		case '1': 
		 system("clear");
	    place_order();
		break;

		case '2':
			
	    break;

		case '3':
			
	    break;

		case '4':
			
	    break;

		case '5':
			
	    break;

		case '6':
			
	    break;
		
	    case '7':
			exit(0);
	    break;
		
		default:
			cout << "\a";
		}
		return 0;
	} 

