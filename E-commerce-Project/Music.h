#pragma once
#include <iostream>
#include "Product.h"
using namespace std;

class Music: public Product
{
protected :
	string Artist;
	string format;
	int runtime;


public:
	Music(){
		string Artist=" ";
		string format=" ";
		int runtime=0;
	}//Music's default contructor 
	Music(string art, string form, int run, string name, string lang, string gen, string cate, int st, double pri, int code){//Music's parameter contructor 

		Artist = art;
		format = form;
		runtime = run;

		productName = name;
		language = lang;
		genre = gen;
		category = cate;
		stock = st;
		price = pri;
		productCode = code;

	}
	~Music() { cout << "Music dest." << endl; }//Music's destructor 

	void display() {
		

		cout << "product Name: " << productName << endl;
		cout << "category: " << category << endl;
		cout << "product Code: " << productCode << endl;
		cout << "Stock: " << stock << endl;
		cout << "Price: " << price << endl;
		cout << endl;

	}

	int getstock() { return stock; }		//I get this because of get the stock value for music class and in main I can get music array members price with this function

	string getproductName() { return productName; }			//I get this because of get the product name value for music class and in main I can get music array members price whit this function


	double getprice() { return price; }		//I get this because of get the price value for music class and in main I can get music array members price whit this function


	friend ostream& operator<<(ostream& onput, Music& obj);		//This ostream operator overlading is output the stock information 

	double calculateDiscount(double para)override {		//This function is continue of virtual function and this calcualte discount for music 

		price = para;
		price = price * 0.85;		//This function is continue of virtual function and this calcualte discount for music this and discount rate is %15

		return price;		//And function is going to equal discount price 
			

	}


	void setupdateStock(int st) {		//I set this because of set the update the stock value for music class and in main I can set music array members stock with this function

		stock = st;		//stock value going to equal st

	}

	int getupdateStock() {			//I get this because of set the updated the stock value for music class and in main I can get music array member

		return stock;
	}

	void setupdatePrice(double pri) {			//I set this because of set the update the price value for music and in main I can set music array members price with this function

		price = pri;		//price value going to equal pri
	}

};

