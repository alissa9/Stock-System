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
	float Price,quantity;

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
	}
	// this class will show the data
	void displaydata()
	{
		//system("clear");
		cout<<"\n The Item ID : " <<ItmNumber;
		cout<<"\n The Name of The Item : " <<ItmName;
		cout<<"\n The Price of The Item : " <<Price;
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

	char* RetItmName()
	{return ItmName;}

	// the end of the class
}; 


// declare for stream ojects - global
fstream f;
item i;

void write_file()
{
	
	   f.open("store.txt",ios::app|ios::app);
	   i.insertdata();
	   f.write((char*)&i,sizeof(i));
	   f.close();
	   cout<<"\n\nThe Iten Has Benn Created";

}

// a function to read records from file
void display_all()
{  
  //  system("clear")
	cout<<"\n\n\n\t\t All Records\n\n";
	f.open("store.txt",ios::in);
	while(f.read((char*)&i,sizeof(i)))
	{
		i.displaydata();
		cout<<"\n\n============================\n";
		
	}
	
	f.close();
	
}

void menu()
{
	//system("clear");
	f.open("store.txt",ios::in);
	if(!f)
	{
		cout<<"ERROR ! file couldnt be open\n\n\n you need to creat an item ";
        cout<<"\n\n\n program is closing";
		
		exit(0);
		
	}
          
	cout<<"\n\n\n\t\t Item Menu\n\n";
	cout<<"=========================================\n";
	cout<<"Item ID         NAME            Price\n";
	cout<<"=========================================\n";

	while (f.read((char*)&i,sizeof(i)))
	{
		cout<<i.RetItmNumber()<<"\t\t"<<i.RetItmName()<<"\t\t"<<i.RetPrice()<<endl;
	}
	f.close();
}


//  a function to place an order

void place_order()
{
//	system("clear");
	int sell[50], quantity[50],c=0;
	float amt,total=0;
	char ch='Y';
	menu();
	cout<<"\n-------------";
	cout<<"\n Sell Items ";
	cout<<"\n-------------";
	do
	{
		cout<<"\n\nEnter Item ID : \n";
		cin>>sell[c];
		cout<<"\nEnter Quantity : \n";
		cin>>quantity[c];
		c++;
		cout<<"\nPLace Another Item ?  (Y/N) \t";
		cin>>ch;
	} while (ch=='y'||ch=='Y');
	  // system("clear");
	cout<<"\n\n****************RECIPET***************\n";
	cout<<"\nID    Name   Quantity   Price   Amount\n";
	for(int x=0;x<=c;x++)
	{
		f.open("store.txt",ios::in);
		f.read((char*)&i,sizeof(i));
		while(!f.eof())
		{
			if(i.RetItmNumber()==sell[x])
			{
				amt=i.RetPrice()*quantity[x];
				
				cout<<"\n"<<sell[x]<<"      "<<i.RetItmName()<<"\t"<<quantity[x]<<"\t"<<i.RetPrice()<<"\t"<<amt;
                total+=amt;
			}
			f.read((char*)&i,sizeof(i));
		}
		f.close();

	}
	cout<<"\n\n\t\t\t\t Total = "<<total;
}


int main()
{
	char ch;
	
	do{
		//system("clear");
		cout << "\n\n\n======================";
		cout << "\nStock Mangement System";
		cout << "\n======================";
		cout << "\n      Music Shop      ";
		cout << "\n======================";
		cout << "\n\n 1. Sell items";
		cout << "\n\n 2. Create items ";
		cout << "\n\n 3. Restock items";
		cout << "\n\n 4. Update Stock quantity ";
		cout << "\n\n 5. Display items";
		cout << "\n\n 6. Items menu ";
		cout << "\n\n 7. Exit";
		cout << "\n\n please select (1-7) = ";
		cin >> ch;
		switch (ch)
		{
		case '1': 
		    // system("clear"); 
	         place_order(); break;

		case '2':
			write_file();  break;

		case '3':  
		     break;

		case '4':         
                   		break;

		case '5': display_all();
                        break;

		case '6':       menu();
	                   break;
	
	    case '7': 	int main();
	                   break;
		
}
	} while(ch!='7');
		return 0;
	 

	}