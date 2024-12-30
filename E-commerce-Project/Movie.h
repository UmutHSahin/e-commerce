#pragma once
#include <iostream>
#include "Product.h"
using namespace std;
class Movie: public Product
{
protected:
	string directors[2];
	string starring[3];
	string subtitles;
	string audioLanguage;


public:
	Movie(){//Movie's default contructor 
		string directors[2];
		string starring[3];
		string subtitles=" ";
		string audioLanguage=" ";
	}//Movie's default contructor 
	
	Movie(string direct[2], string star[3]) {		//Movie's parameter contructor  for directors and stars

		for (int i = 0; i < 2; i++)		//this loop for declare every direcetors to direct array 
		{
			directors[i] = direct[i];
		}
		for (int i = 0; i < 3; i++)
		{
			starring[i] = star[i];		//this loop for declare every starring to star array 
		}

	}//Movie's parameter contructor  for directors and stars

	Movie(string direct0, string star0,string sub, string audio, string name, string lang, string gen, string cate, int st, double pri, int code) { //Movie's parameter contructor 

	
		
		directors[0] = direct0;
		starring[0] = star0;
		subtitles = sub;
		audioLanguage = audio;

		productName = name;
		language = lang;
		genre = gen;
		category = cate;
		stock = st;
		price = pri;
		productCode = code;

	}//Movie's parameter contructor

	~Movie() { cout << "Movie dest." << endl; }//Movie's destructor
	

	
	string getdirectors() {		//this function for get directors


		return directors[2];
	}


	void setdirectors(string direct[2]) { //this function for set directors
		directors[2] = direct[2];
	}

	void display() {
	

		cout <<"Product Name: "<< productName << endl;
		cout << "Category: " << category << endl;
		cout << "ProductCode: " << productCode << endl;
		cout << "Stock: " << stock << endl;
		cout << "Price: " << price << endl;
		cout << endl;

	}
	
	int getstock() { return stock; }			//I get this because of get the stock value for movie class and in main I can get movie array members price with this function

	double getprice() { return price; }			//I get this because of get the price value for movie class and in main I can get movie array members price whit this function


	friend ostream& operator<<(ostream& onput, Movie& obj);		//This ostream operator overlading is output the stock information 

	string getproductName() { return productName; }				//I get this because of get the product name value for movie class and in main I can get movie array members price whit this function

	 double calculateDiscount(double para)override {			//This function is continue of virtual function and this calcualte discount for movie 

		
		 price = para;
		price = price * 0.95;								//This function is continue of virtual function and this calcualte discount for movie this and discount rate is %05

		return price;								//And function is going to equal discount price 
			
	}

	void setupdateStock(int st) {			//I set this because of set the update the stock value for movie class and in main I can set movie array members stock with this function

		stock = st;		//stock value goibg to equal st
	}

	void setupdatePrice(double pri) {			//I set this because of set the update the price value for movie class and in main I can set movie array members price with this function

		price = pri;							//price value going to equal pri
	}
	
	int getupdateStock() {					//I get this because of set the updated the stock value for movie class and in main I can get movie array members stock with this function

		return stock;			
	}

};

