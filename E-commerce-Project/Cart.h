#pragma once
#include <iostream>
#include"Product.h"
#include "Music.h"
#include "Book.h"
#include "Movie.h"
using namespace std;


class Cart
{
protected:

	double totalPrice=0.0;		//equal to total prices
	int i;
	int length;
	Product *productList[5];			// I use this because of get the book, movie or music information all of them with I know product is book, movie or music 

	static const int MAX_PRODUCTS = 5;			//using for array's max size 

public:

	Cart() {//Cart's default contructor 
		i = 0;
		totalPrice = 0;
		length = 0;
		
	}//Cart's default contructor 

	template<typename T>	//I use template because of proList that means productList[5] can be equal to Book, Movie ro Music
	Cart(double totPrice, T proList[5], string name[MAX_PRODUCTS]){//Cart's parameter constructor 
		length = 0;
		 totalPrice= totPrice;
		 for (int a = 0; a < 5; a++) {

			 productList[a] = proList[a];

		 }

		

	}//Cart's parameter constructor 

	~Cart(){
		cout << "Cart dest." << endl;
	}//Cart's destructor 

	
	
	double gettotalPrice() { return totalPrice; }									//I use for get total price
	void settotalPrice(double tprice) { totalPrice = tprice; }						//I use for put new price

	int getlength() { return length; }							//I get the total added product number
	void setlength(int len) { len = length; }			//I set the total added product number

	void setproductList(Product*  x) {						//I get the product and attempt to productList array

		productList[length] = x;
		setlength(length++);
	}

	

	
	void remove(int element) {							//my remove functoin for when users want to remove a produt from their cart

		int i = element - 1;
		double sentpricesss = productList[element - 1]->getprice(); //calculate total new price after remove pr�duct
		double disprice = productList[element - 1]->calculateDiscount(sentpricesss);		//calculate total new price after remove pr�duct 

		double lastprice = totalPrice - disprice;

		settotalPrice(lastprice);	//calculate total new price after remove pr�duct 
		
		for (; i < length ; i++) {

				productList[i] = productList[i + 1];			//Burada bizden silmemizi istedigi �r�n�n �zerine yeni �r�n� yazarak silinmesi istenilen �r�n� silmi� oluyoruz 
															//	for dongusu ile array elemanlar� aras�nda bo�luk kalmamas�n� ve yeni gelecek array�n hemen ard�na eklenmesini sa�l�yoruz	

			}
			length--;   //�f remove a product lenght will be decrise;
		
				
	}	

	
	void display() {
	
		int a ;
			if (getlength()==0) {				//I look at list is emty or not

				cout << "List is empty" << endl;
				cout << endl;

			}
			else if(length > 0&& length<6){					//I look at list is less than 1 or more than 5

				for (a = 0; a < length; a++) {
					cout << endl;
					cout << "Product: " << a+1 << endl;						//I write this to understand which produt number for which product
					cout << "Name: " << productList[a]->getproductName() << endl;			//I output product name to added in list	
					
					cout << "Price: " << productList[a]->getprice() << endl;				//I  output product didnt discount price to added in list
					cout << endl;

				}
				cout << endl;
				cout << "You are so luck there are some discount Total Price: " << gettotalPrice() << endl;			//I output total discount price

			}
	
	}
};


