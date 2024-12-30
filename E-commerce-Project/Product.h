#pragma once
#include <iostream>

using namespace std;
class Product
{
protected:
	string productName;
	string language;
	string genre;
	string category;
	int stock;
	double price=0;
	int productCode;
	
public:
	
	
	Product(){//Prodcut's default contructor 
		string productName=" ";
		string language=" ";
		string genre=" ";
		string category=" ";
		int stock=0;
		double price = 0.0;
		int productCode=0;
	}//Prodcut's default contructor 

	Product(string name, string lang, string gen, string cate, int st, double pri, int code) {//Prodcut's parameter contructor 

		 productName =name;
		 language =lang;
		 genre = gen;
		 category =cate;
		 stock = st;
		 price = pri;
		 productCode =code;

	} //Prodcut's parameter contructor 

	~Product(){ cout << "Product dest." << endl; }//Prodcut's destructor


	void display(){			//I write this for display poducts (elemanlarýnýn) values

		cout<<productName<<endl;
		cout<<language<<endl;
		cout<<genre <<endl;
		cout<<category<<endl;
		cout<<stock<<endl;
		cout<<price<<endl;
		cout<<productCode<<endl;
							//I write this for display poducts (elemanlarýnýn) values
	}


	virtual double calculateDiscount(double para) = 0;			//I declare calcualteDiscount pure virtual function because of other all child classes have this functyion and all of them do different math operations
	
	double getprice() { return price; }				//I put this because of get price product and members in main code(Project.cpp), cart class, etc.

	string getproductName() { return productName; }		//I put this because of get name product and members in main code(Project.cpp), cart class, etc.
	

	bool checkstock(int stk){						//I write this for check stock is more than 0 
	
		stock = stk;

		if (stock < 1) {		//If stock less than 1 output will be There are no stock for this item. and bool function return false 

			cout << "There are no stock for this item" << endl;

			return false;			//function going to be false
		}
		else {

			return true;				//function going to be true
		}
	
	}

};

