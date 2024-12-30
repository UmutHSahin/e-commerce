#pragma once
#include <iostream>
#include "Product.h"
#include "Cart.h"
using namespace std;
class Book: public Product
{
protected:
	string publisher;
	int ISBN;


public:

	Book(){			//Book's default contructor 
		string publisher=" ";
		int ISBN = 0;
	}//Book's default contructor 

	Book(string publis, int IS , string name, string lang, string gen, string cate, int st, double pri, int code) { //Book's parameter contructor 

		publisher = publis;

		ISBN = IS;

		productName = name;
		language = lang;
		genre = gen;
		category = cate;
		stock = st;
		price = pri;
		productCode = code;

	}//Book's parameter contructor 

	~Book() { cout << "Book dest." << endl; }//Book's destructor 

	void display() {
		

		cout << "Product Name: " << productName << endl;
		cout << "Category:  " << category << endl;
		cout << "Product Code:  " << productCode << endl;
		cout << "Stock: " << stock << endl;
		cout << "Price: " << price << endl;
		cout << endl;

	}
	int getstock() { return stock; }				//I get this because of get the stock value for book class and in main I can get book array members price with this function

	friend ostream& operator<<(ostream& onput, Book& obj);		//This ostream operator overlading is output the stock information 

	double getprice() { return price; }			//I get this because of get the price value for book class and in main I can get book array members price whit this function

	string getproductName() { return productName; }		//I get this because of get the product name value for book class and in main I can get book array members price whit this function


	double calculateDiscount(double para) override {		//This function is continue of virtual function and this calcualte discount for book 

		price = para;
		price = price * 0.88;				//This function is continue of virtual function and this calcualte discount for book this and discount rate is %12

		return price;		//And function is going to equal discount price 

	}
	void setupdateStock(int st) {			//I set this because of set the update the stock value for book class and in main I can set book array members stock with this function

		stock = st;				//stock value goibg to equal st
	}

	int getupdateStock() {					//I get this because of set the updated the stock value for book class and in main I can get book array members stock with this function

		return stock;
	}

	void setupdatePrice(double pri) {			//I set this because of set the update the price value for book class and in main I can set book array members price with this function

		price = pri;						//price value going to equal pri
	}
};

