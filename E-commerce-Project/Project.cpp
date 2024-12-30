#include <iostream>
#include <string>
#include "Product.h"
#include "Music.h"
#include "Book.h"
#include "Movie.h"
#include "Cart.h"

using namespace std;

template <typename T>						
T updateCartPrice(T& cartTotal, T newPrice) {		//Here I try to calculate total cart peice with trmpalte because of there are 3 different class and this function dont know which fundtion when come. 
														//(Fonkisyon Classlarýn ne zaman hangisinin geleceðini bilemeyeceði için template kullandým)
	cartTotal += newPrice;							// Carttotal value is total price and new price is added product price;
	return cartTotal;								// and then I return totla perice because of get the last total price in main
}


ostream& operator<<(ostream& output, Book& obj) {				//I use operator overloading to change stock information when admin login

	output<<obj.stock;											//I get the value with input>> and I paste to obj.stock. Obj is the product of changed stock information
	return output;												//I use operator overloading to change stock information when admin login

}

ostream& operator<<(ostream& output, Movie& obj) {				//I use operator overloading to change stock information when admin login

	output << obj.stock;													//I get the value with input>> and I paste to obj.stock. Obj is the product of changed stock information
	return output;

}

ostream& operator<<(ostream& output, Music& obj) {			//I use operator overloading to change stock information when admin login

	output << obj.stock;
												//I get the value with input>> and I paste to obj.stock. Obj is the product of changed stock information
	return output;

}


int main() {



	Book  book1[3]{
	Book("ASbook", 1234, "ANNA Karanna1,2,3", "English", "For Adult", "History", 332, 54.00, 6432 ),							//I give the value for products about stock, price, name, codes, etc.
	Book("KASbook", 567, "Sadece Seyma", "Turkish", "For Child", "Real Life", 32, 78.00, 2547 ),
	Book("SASbook", 890, "Ucus345", "Turkish", "For Adult", "Roman", 482, 32.00, 8695) };											//I give the value for products about stock, price, name, codes, etc.

	Music music1[3]{
	Music("Sagopa", "Video", 4, "Karabiber Dugasý", "Turkish", "Rap", "Old School", 145, 35.00, 8787),									//I give the value for products about stock, price, name, codes, etc.
	Music("Tarkan", "Music", 5, "Geccek", "Turkish", "Pop", "Pop", 555, 55.00, 8879),
	Music("Muslum Gurses", "Music", 5, "Adýný Sen Koy", "Turkish", "Arabesc", "Arabesc", 457, 77, 7865) };							//I give the value for products about stock, price, name, codes, etc.

	Movie movie1[3]={
	Movie("Hakan, Okan, Faruk","Furkan, Fatih","Yes", "Yes", "Escape", "Turkish", "Action", "Action", 70, 35.00, 5957 ),
	Movie("Kenan, Mira, Emir","Furkan, Sila","Yes", "Yes", "Million", "Turkish", "Real Life", "Real Life", 77, 45.00, 5857),				//I give the value for products about stock, price, name, codes, etc.
	Movie("Atilla, Meric, Faruk","Fatma, Katip","Yes", "Yes", "WarII", "Turkish", "Action", "Action", 98, 30.00, 4487) };
	
	Book* bookss[3];			//When I send product to cart, fist I try to send directly Music, Book and Movie class array then there was a error then i declare the book music and movie wit like tihs
	Music* musicss[3];			// When I send product to cart, fist I try to send directly Music, Bookand Movie class array then there was a error then i declare the book musicand movie wit like tihs
	Movie* moviess[3];			// When I send product to cart, fist I try to send directly Music, Bookand Movie class array then there was a error then i declare the book musicand movie wit like tihs

	bookss[0] = &book1[0];
	bookss[1] = &book1[1];		// I decalred the  books by a poiner  
	bookss[2] = &book1[2];

	moviess[0] = &movie1[0];
	moviess[1] = &movie1[1];		// I decalred the  movies by a poiner  
	moviess[2] = &movie1[2];

	musicss[0] = &music1[0];
	musicss[1] = &music1[1];	// I decalred the  musics by a poiner  
	musicss[2] = &music1[2];

	Book *bookpvir= new Book;												//for use virtual function I diclare book, movie and muisc to a  pointer 
	Movie *moviepvir= new Movie;											//for use virtual function I diclare book, movie and muisc to a  pointer 
	Music *musicpvir = new Music;											//for use virtual function I diclare book, movie and muisc to a  pointer 

	Book *book= new Book;
	Book bookoo[3];
	Book book2;
	
	Cart cart;
	Cart *cartt=new Cart;
	Cart cart1[5];
	
	Music music;
	Music music2;
	
	Movie movie;
	Movie movie2;


	string login;//This loginfor select admin or costumer login


	int listtime=0;

	///////////////////////////////////////////
	//Product* booksp = new Book();		//			//for use virtual function I diclare book, movie and muisc to a product pointer 
	//Product* moviesp = new Movie();  //
	//Product* musicsp = new Music();//
	//////////////////////////////////////

	
	
	int remove;			//this for take which one wants to remove
	int cartsel;		//for user confirm cart, remove prodcut or exit selection
	int option , secondOption, thirtOption;  //these for sellect the eneterd and pass next point;
	int updatestock;		//I use this for admin give new stock 
	double updateprice;		//I use this for admin give new price 
	int dis=0;				//This for select which product 
	int a ;					//these for use go to
	int i = 0;				// I use i for for loops
	double para;			//I use this for get products price
	int secselpro;			//This for select product or exit selection 

	double dispara;			//this to get discount product price 

	
	double cartTotal = 0;

	int sepet = 0;

	double totpara;

	int checkstk;

	
	e://///e/////
	cout << " Secret Admin Password= admin\n\n\n********Welcome to our online store.********\n*****Enter password for the admin login.****\n******Press * to continue as a customer*****\n ----->";
	cin >> login;
	 
	//BÜÞRA HOCAM MERHABA KOLAY GELSÝN. SÝZ ENTER ÝLE GÝRÝÞ YAPIN DEMÝÞTÝNÝZ GETLÝNE ÝLE ALIN DEMÝÞSÝNÝZ SANIRIM. ÝNTERNETTE ÇOK FAZLA ARAÞTIRDIM, DENEDÝM, KODU BOZDUM FAKAT BÝR TÜRLÜ ENTER ÝLE GÝRÝÞ YAPTIRMAYI BECEREMEDÝM. 
	//ADMÝN GÝRÝÞÝ ÝÇÝN ÞÝFRE KOYDUM KOD AÇILINCA YAZIYOR EN YUKARIDA. TEKRARDAN KOLAY GLESÝN. ÝYÝ GÜNLER DÝLERÝM.

	cout << endl;

		if (login=="*") {

			m:////m////
			cout << "1. View Cart \n2. Select Category\n3. Exit " << endl;

			cin >> option;			// I get the value user what want to do(kullanýcý ne seçeceðini alýyorum)
			cout << endl;

			for (a=0;a < 6&& option != 3;a++) {
				if (option == 1) {

					
					cartt->display();
					
					cout << "1. Confirm the Cart" << endl;
					cout << "2. Remove the Product" << endl;
					cout << "3. Log out" << endl;//It go for admin costumer selection part
					cout << "4. Select new Products" << endl;
					cout << "---->";
					cin >> cartsel;			

					if (cartsel == 1) { //This if else is for costumer wants to confirm cart , remove product or log out

						if (sepet < 1) { //I look at the there is any product in cart
							cout << "You didn't add a Prodcut or You removed product \n Please add a product to confirm card." << endl;
							goto m;//This m for go back to view cart and select category place
						}

						else if (0 < sepet && sepet < 6) {  //I look at the there is any product in cart and are ther more than 5
							cout << "Your order has been successfully confirmed" << endl;

							cart.display();
						}
					}
					else if (cartsel == 2) {
					tryremove: //////tryremove//////
						if (sepet != 0) {

							cout << "Enter which one do you want remove" << endl;    //I want to enter which prodcut remove from user
							cout << "---->";
							cin >> remove;					 //I want to enter which prodcut remove from user

							if (0 < remove && remove < 6) {				 //I control user enter more than posible list number (kullanýcý cart kapasitesinden fazla olan bir üzünü kaldýmamý istmiþmi istememiþmi ona baktým)

								
								cartt->remove(remove);  // I send the value for rmove which list product


							
								sepet--;     //When user remove a product sepet will be decrise sepet is our list, cart size

								int addcard = 5 - sepet;

								cout << "You can add " << addcard << " product to your card" << endl;    //User can know how many product can add
								cout << endl;


								cart.display();
							}
							else {

								cout << "There are not a product like that!!!" << endl;
								cout << "PLEASE TRY NEW PRDOUCT" << endl;
								goto tryremove;         //I put tis beacuse of user if enter a product there is not in product list, I want to enter again
							}
							
						}else {

							
							cout << "Your cart is empty please add products to remove " << endl;
							goto m;//This m for go back to view cart and select category place

							
						}
						
						
					}
					else if (cartsel == 3) {
	
						goto e;		//This e for log out from program and select admin or costumer page

					}
					else if (cartsel == 3) {

						goto m;		//This m for go back to view cart and select category place
					}

				}
				else if (option == 2) {
					k:
					cout << "1. Book\n2. Movie\n3. Music\n4. Exit" << endl;                         //User sellect which category( ullanýcý hangi kategori olacaðýný seçityor)
					cout << "---->";
					cin >> secondOption;

					cout << endl;

					if (secondOption == 1) {

						for (i=0; i < 3; i++) {

							cout << i + 1 << "Book" << endl;
							bookss[i]->display();
						}

						cout << "1. Select Product" << endl;
						cout << "2. Exit" << endl;												//burada ürün seçmeden önce son kez geri gelme opsiyonunu veriyorum
						cout << "---->";
						cin >> secselpro;
						cout << endl;

						if (secselpro == 1) {
							usersellectbook:
							cout << "Enter which one do you want: "<<endl;
							cout << "---->";
							cin >> dis;
							cout << endl;
							if (0 < dis && dis < 4) {

								goto addcontbook;			//If user enter true produt number continue 
							}else{
									
								goto usersellectbook;		//If user didnt enter true produt number turn back
							}

						}
						else if (secselpro == 2) {

							goto k;		// k for go to select the prodct category
						}

						
						addcontbook:
						if (dis == 1) {
							checkstk= book2.checkstock(bookss[dis - 1]->getstock());

							if (checkstk==true) {							//Here I check the stock


								para = bookss[dis - 1]->getprice();				//I get the  product price

								dispara = bookpvir->calculateDiscount(para);		//I sent the price to discount virtual function and I give the value to dispara

								if (sepet < 5) {			//I check list is full or not

									
									totpara= updateCartPrice(cartTotal, dispara);		//I get the totalpara to give the values if costumer add a new product to cart


									cartt->settotalPrice(totpara);				//I sent total price to carts totalprie

									
									(*cartt).setproductList(bookss[0]);			//I sent the produt to cart
									
									sepet++;  //If cosutmer add a product to cart sepet value going to increase

									cout << "Product added to cart" << endl;
									goto m;//This m for go back to view cart and select category place
								}
								else { //If list is full this will gonna output
									cout << "List is Full" << endl;

									goto m;//This m for go back to view cart and select category place
								}
								
							} 

						}else if (dis == 2) {

							checkstk = book2.checkstock(bookss[dis - 1]->getstock());	//I get the product stock for check with if else

							if (checkstk == true) {//Here I check the stock

								para = bookss[dis - 1]->getprice();		//I get the  product price

								dispara = bookpvir->calculateDiscount(para);	//I sent the price to discount virtual function and I give the value to dispara

								


								if (sepet < 5) {	//I check list is full or not


									(*cartt).setproductList(bookss[1]);				//I sent the produt to cart

									totpara = updateCartPrice(cartTotal, dispara);			//I get the total para for give the values if costumer add a new product to cart

									cartt->settotalPrice(totpara);//I sent total price to carts totalprie

									sepet++;		//If cosutmer add a product to cart sepet value going to increase

									cout << "Product added to cart" << endl;
									goto m;//This m for go back to view cart and select category place
								}
								else { //If list is full this will gonna output
									cout << "List is Full" << endl;

									goto m;//This m for go back to view cart and select category place
								}
							}
							goto m;//This m for go back to view cart and select category place

						}
						else if (dis == 3) {

							checkstk = book2.checkstock(bookss[dis - 1]->getstock()); //I get the product stock for check with if else

							if (checkstk == true) {//Here I check the stock

								para = bookss[dis - 1]->getprice();//I get the  product price

								dispara = bookpvir->calculateDiscount(para);//I sent the price to discount virtual function and I give the value to dispara

								if (sepet < 5) {//I check list is full or not

									(*cartt).setproductList(bookss[2]);//I sent the produt to cart

									totpara = updateCartPrice(cartTotal, dispara);//I get the total para for give the values if costumer add a new product to cart

									cartt->settotalPrice(totpara);//I sent total price to carts totalprie


									sepet++;//If cosutmer add a product to cart sepet value going to increase

									cout << "Product added to cart" << endl;
									goto m;//This m for go back to view cart and select category place
								}
								else {//If list is full this will gonna output
									cout << "List is Full" << endl;

									
									goto m;//This m for go back to view cart and select category place
								}

							}

						}
						
						cart.display();  // I output list to secreen
					
						cout << endl;

					}
					else if (secondOption == 2) {

						for (i=0; i < 3; i++) {

							cout << i + 1 << "Movie" << endl;
							moviess[i]->display();
						}

						cout << "1. Select Product" << endl;
						cout << "2. Exit" << endl;
						cout << "---->";
						cin >> secselpro;
						cout << endl;

						if (secselpro == 1) {
							usersellectmovie:
							cout << "Enter which one do you want: "<<endl;
							cout << "---->";
							cin >> dis;

							if (0 < dis && dis < 4) {

								goto addcontmovie;			//If user enter true produt number continue 
							}
							else {

								goto usersellectmovie;		//If user didnt enter true produt number turn back
							}

						}
						else if (secselpro == 2) {//This start when costumer wants to exit

							goto k;
						}

						addcontmovie:
						if (dis == 1) {

							checkstk = movie2.checkstock(moviess[dis - 1]->getstock());  //I get the product stock for check with if else

							if (checkstk == true) {			//Here I check the stock	

								para = moviess[dis - 1]->getprice();		//I get the  product price

								dispara = moviepvir->calculateDiscount(para);//I sent the price to discount virtual function and I give the value to dispara
							

								if (sepet < 5) {//I check list is full or not

									(*cartt).setproductList(moviess[0]);//I sent the produt to cart

									totpara = updateCartPrice(cartTotal, dispara);//I get the total para for give the values if costumer add a new product to cart

									cartt->settotalPrice(totpara); //I sent total price to carts totalprie

									
									sepet++;		//If cosutmer add a product to cart sepet value going to increase

									cout << "Product added to cart" << endl;
									goto m;//This m for go back to view cart and select category place
								}
								else {	//If list is full this will gonna output
									cout << "List is Full" << endl;

									goto m;//This m for go back to view cart and select category place
								}
							}

						}
						else if (dis == 2) {
							checkstk = movie2.checkstock(moviess[dis - 1]->getstock());//I get the product stock for check with if else

							if (checkstk == true) {//Here I check the stock	

								para = moviess[dis - 1]->getprice();//I get the  product price

								dispara = moviepvir->calculateDiscount(para);//I sent the price to discount virtual function and I give the value to dispara
	

								if (sepet < 5) {//I check list is full or not


									(*cartt).setproductList(moviess[1]);//I sent the produt to cart


									sepet++;//If cosutmer add a product to cart sepet value going to increase

									totpara = updateCartPrice(cartTotal, dispara);//I get the total para for give the values if costumer add a new product to cart

									cartt->settotalPrice(totpara);//I sent total price to carts totalprie

									cout << "Product added to cart" << endl;

									goto m;//This m for go back to view cart and select category place

								}
								else {//If list is full this will gonna output
									cout << "List is Full" << endl;

									goto m;//This m for go back to view cart and select category place

								}
							}

						}
						else if (dis == 3) {
							checkstk = movie2.checkstock(moviess[dis - 1]->getstock());//I get the product stock for check with if else

							if (checkstk == true) {//Here I check the stock	

								para = moviess[dis - 1]->getprice();//I get the  product price

								dispara = moviepvir->calculateDiscount(para);//I sent the price to discount virtual function and I give the value to dispara


								if (sepet < 5) {//I check list is full or not

								
									totpara = updateCartPrice(cartTotal, dispara);//I get the total para for give the values if costumer add a new product to cart

									cartt->settotalPrice(totpara);//I sent total price to carts totalprie

									(*cartt).setproductList(moviess[2]);//I sent the produt to cart

									sepet++;//If cosutmer add a product to cart sepet value going to increase
									
									cout << "Product added to cart" << endl;

									goto m;//This m for go back to view cart and select category place
								}
								else {//If list is full this will gonna output
									cout << "List is Full" << endl;

									goto m;//This m for go back to view cart and select category place
								}
							}
						}
						cart.display();
				
						cout << endl;

					}
					else if (secondOption == 3) {

						for (i=0; i < 3; i++) {

							cout << i + 1 << "Music" << endl;				//Here I display musics to secreen
							musicss[i]->display();
						}
						cout << "1. Select Product" << endl;
						cout << "2. Exit" << endl;
						cout << "---->";						//Here users select exit or select produrt
						cin >> secselpro;

						if (secselpro == 1) {
							usersellectmusic:
							cout << "Enter which one do you want: ";
							cout << "---->";								//Users pick a product for add to cart
							cin >> dis;

							if (0 < dis && dis < 4) {

								goto addcontmusic;			//If user enter true produt number continue 
							}
							else {

								goto usersellectmusic;		//If user didnt enter true produt number turn back
							}

						}
						else if (secselpro == 2) {

							goto k;
						}
						addcontmusic:
						if (dis == 1) {

							checkstk = music2.checkstock(musicss[dis - 1]->getstock());	//I get the product stock for check with if else

							if (checkstk == true) {		//Here I check the stock	

								para = musicss[dis - 1]->getprice();		//I get the  product price

								dispara = musicpvir->calculateDiscount(para);	//I sent the price to discount virtual function and I give the value to dispara

								

								if (sepet < 5) {		//I check list is full or not



									(*cartt).setproductList(musicss[0]);		//I sent the produt to cart
								
									totpara = updateCartPrice(cartTotal, dispara);		//I get the total para for give the values if costumer add a new product to cart

									cartt->settotalPrice(totpara);		//I sent total price to carts totalprie
									
									sepet++;		//If cosutmer add a product to cart sepet value going to increase

									cout << "Product added to cart" << endl;
									goto m;//This m for go back to view cart and select category place
								}
								else {		//If list is full this will gonna output
									cout << "List is Full" << endl;

									goto m;//This m for go back to view cart and select category place
								}
							}

						}
						else if (dis == 2) {


							checkstk = music2.checkstock(musicss[dis - 1]->getstock());		//I get the product stock for check with if else

							if (checkstk == true) {		//Here I check the stock	

								para = musicss[dis - 1]->getprice();		//I get the  product price

								dispara = musicpvir->calculateDiscount(para);		//I sent the price to discount virtual function and I give the value to dispara

				

								if (sepet < 5) {		//I check list is full or not

									(*cartt).setproductList(musicss[1]);	//I sent the produt to cart

									totpara = updateCartPrice(cartTotal, dispara);		//I get the total para for give the values if costumer add a new product to cart

									cartt->settotalPrice(totpara);		//I sent total price to carts totalprie

									sepet++;		//If cosutmer add a product to cart sepet value going to increase
				

									cout << "Product added to cart" << endl;
									goto m;//This m for go back to view cart and select category place
								}
								else {		//If list is full this will gonna output
									cout << "List is Full" << endl;

									goto m;//This m for go back to view cart and select category place
								}
							}

						}
						else if (dis == 3) {


							checkstk = music2.checkstock(musicss[dis - 1]->getstock());		//I get the product stock for check with if else

							if (checkstk == true) {		//Here I check the stock	

								para = musicss[dis - 1]->getprice();		//I get the  product price

								dispara = musicpvir->calculateDiscount(para);	//I sent the price to discount virtual function and I give the value to dispara


								if (sepet < 5) {	//I check list is full or not


									(*cartt).setproductList(musicss[2]);	//I sent the produt to cart
									
									totpara = updateCartPrice(cartTotal, dispara);	//I get the total para for give the values if costumer add a new product to cart

									cartt->settotalPrice(totpara);		//I sent total price to carts totalprie

									sepet++;		//If cosutmer add a product to cart sepet value going to increase

							
									
									cout << "Product added to cart" << endl;
									goto m;//This m for go back to view cart and select category place
								}
								else {	//If list is full this will gonna output
									cout << "List is Full" << endl;

									goto m;//This m for go back to view cart and select category place
								}


							}

						}
						cout << endl;
					}
					else if (secondOption == 4) {

						goto m;//This m for go back to view cart and select category place

						
					}

				}else if (option == 3) {

					cout << endl;
					break;
					
				}
			
			}
			goto e; //This e for log out from program and select admin or costumer page
		}
		else if (login == "admin") {

			d:
			cout << "1. Update product information. " << endl;
			cout << "2. Exit" << endl;
			cout << "---->";
			cin >> option;
			cout << endl;

				if (option == 1) {
					bookchangeup:
					cout << "1. Book\n2. Movie\n3. Music\n4. Exit" << endl;
					cout << "---->";
					cin >> secondOption;
					cout << endl;

					for (; secondOption != 4;) {
						for (; option != 2;) {

							///////////BOOK////////////
							if (secondOption == 1) {

								cout << "1. Update stock" << endl;
								cout << "2. Update Price" << endl;
								cout << "3. Exit" << endl;
								cout << "---->";
								cin >> thirtOption;

								cout << endl;

								if (thirtOption == 1) {

									
									for (i = 0; i < 3; i++) {

										cout << i + 1 << ". Book" << endl;
										bookss[i]->display();
									}
								trynewbookstk:
									cout << "Enter which one do you want: "<<endl;
									cout << "---->";
									cin >> dis;
									cout << endl;

									if (0 < dis && dis < 4) {

										cout << "Enter new Stock: "<<endl;
										cout << "---->";
										cin >> updatestock;
										cout << endl;
										bookss[dis - 1]->setupdateStock(updatestock);			//Here sent te new stock to product

										cout << "New stock updated  " << book1[dis - 1] << endl;				//I use operator overlading (ostream)Output for give new stodk is true updated or not
										cout << endl;
									}
									else {

										cout << "There are not a product like that!!!" << endl;
										cout << "PLEASE TRY NEW PRDOUCT" << endl;
										goto trynewbookstk;                                              //I put tis beacuse of admin if enter a product there is not in product list, I want to enter again
									}


								}
								else if (thirtOption == 2) {

									for (i = 0; i < 3; i++) {

										cout << i + 1 << ". Book " << endl;
										bookss[i]->display();
									}
								trynewbookprice:				//I put this for if admin give a prýdcut number not in store, turn again

									cout << "Enter which one do you want: " << endl;
									cout << "---->";
									cin >> dis;
									cout << endl;


									/*double para;
									para = bookss[dis - 1]->getprice();
									product1->calculateDiscount(para);*/


									//product1->calculateDiscount(para);//BURADA DENEDÝM ACABA BUNU YAZSAM ÇALIÞIRMI DÝYE OLDU SONRA GÝTÝM COUTUN ÝÇÝNE YAZDIM

								if(0<dis&& dis<4){

									cout << "Enter new Price: " << endl;
									cout << "---->";
									cin >> updateprice;
									cout << endl;


									bookss[dis - 1]->setupdatePrice(updateprice);    //Here sent te new price to product

									cout << "New updated price: " << bookss[dis - 1]->getprice() << endl; //I output new price for new price cahnged true or not
								}
								else {

									cout << "There are not a product like that!!!" << endl;
									cout << "PLEASE TRY NEW PRDOUCT" << endl;
									goto trynewbookprice;                                              //I put tis beacuse of admin if enter a product there is not in product list, I want to enter again
								}


									//BURADA DÝSCUNTUN ÇALIÞIP ÇALIÞMADIÐINI DENEDÝM VÝRTUAL ÇALIÞIYOR ÞUAN 
									//para = book1[dis - 1].getprice();
									//cout << "yeni para zamlý" << product1->calculateDiscount(para) << endl;

								}
								else if (thirtOption == 3) {
									
									
									cout << "1. Book\n2. Movie\n3. Music\n4. Exit" << endl;
									cin >> secondOption;
									cout << endl;
								}

							}/////////// MOVIE///////////
							else if (secondOption == 2) {
								cout << endl;
								b:
								cout << "1. Update stock" << endl;
								cout << "2. Update Price" << endl;
								cout << "3.Exit" << endl;
								cout << "---->";						//admin pick which want to update price or stock
								cin >> thirtOption;

								cout << endl;

								if (thirtOption == 1) {		//Here admin going to change stock information
									
									for (i = 0; i < 3; i++) {

										cout << i + 1 << ". Movie" << endl;						//Here movies print to secreen
										moviess[i]->display();
									}
								trynemoviestk:
									cout << "Enter which one do you want: "<<endl;					//admin going to pick which product
									cout << "---->";
									cin >> dis;
									cout << endl;

									if(0 < dis && dis < 4){

										cout << "Enter new Stock: "<<endl;
										cout << "---->";
										cin >> updatestock;
										cout << endl;
										moviess[dis - 1]->setupdateStock(updatestock);

									cout << "New stock updated  " << movie1[dis - 1] << endl;   //I use operator overlading (ostream) Output for give new stodk is true updated or not
									}else {

										cout << "There are not a product like that!!!" << endl;
										cout << "PLEASE TRY NEW PRDOUCT" << endl;
										goto trynemoviestk;                                              //I put tis beacuse of admin if enter a product there is not in product list, I want to enter again
									}

									

								}
								else if (thirtOption == 2) {			//here admin going to change price inforamtion
									
									for (i = 0; i < 3; i++) {

										cout << i + 1 << ". Movie" << endl;			//Here movies print to secreen
										moviess[i]->display();
									}

								trynemovieprice:
									cout << "Enter which one do you want: "<<endl;			//admin going to pick which product
									cout << "---->";
									cin >> dis;													//admin going to pick which product
									cout << endl;

									if(0 < dis && dis < 4){

									cout << "Enter new Price: ";			
									cin >> updateprice;												//Here admin write new price for a movie product
									cout << endl;				
									moviess[dis - 1]->setupdatePrice(updateprice);

									cout << "New updated price: " << moviess[dis - 1]->getprice()<<endl; //I output new price for new price cahnged true or not


								}else {

									cout << "There are not a product like that!!!" << endl;
									cout << "PLEASE TRY NEW PRDOUCT" << endl;
									goto trynemovieprice;                                              //I put tis beacuse of admin if enter a product there is not in product list, I want to enter again
								}

								}
								else if (thirtOption == 3) {				//here going to be exit but admin can select here than when select something secondOption will workk
								
									cout << "1. Book\n2. Movie\n3. Music\n4. Exit" << endl;
									cout << "---->";
									cin >> secondOption;
									cout << endl;
								}

							}////////////// MUSÝC//////////////////
							else if (secondOption == 3) {
								cout << endl;
								
								cout << "1. Update stock" << endl;					//admin will update stock info for music
								cout << "2. Update Price" << endl;					//admin will update price info for music
								cout << "3.Exit" << endl;
								cout << "---->";
								cin >> thirtOption;

								cout << endl;

								if (thirtOption == 1) {		//admin will update stock info for music
									
									for (i = 0; i < 3; i++) {

										cout << i + 1 << ". Music" << endl;
										musicss[i]->display();
									}
								trynewmusicstk:
									cout << "Enter which one do you want: ";
									cin >> dis;
									cout << endl;

									if(0 < dis && dis < 4){
									cout << "Enter new Stock: "<<endl;
									cout << "---->";
									cin >> updatestock;
									cout << endl;
								
									musicss[dis - 1]->setupdateStock(updatestock);

									cout << "New stock updated  " << music1[dis - 1] << endl;   //I use operator overlading (ostream) Output for give new stodk is true updated or not

								}
								else {

									cout << "There are not a product like that!!!" << endl;
									cout << "PLEASE TRY NEW PRDOUCT" << endl;
									goto trynewmusicstk;                                              //I put tis beacuse of admin if enter a product there is not in product list, I want to enter again
								}


								}
								else if (thirtOption == 2) {			//admin will update price info for music

									for (i = 0; i < 3; i++) {

										cout << i + 1 << ". Music" << endl;
										musicss[i]->display();
									}
									trynewmusicprice:
									cout << "Enter which one do you want: ";
									cin >> dis;
									cout << endl;

									if(0 < dis && dis < 4){

									cout << "Enter new Price: "<<endl;
									cout << "---->";
									cin >> updateprice;
									cout << endl;
									musicss[dis - 1]->setupdatePrice(updateprice);

									cout << "New updated price: " << musicss[dis - 1]->getprice()<<endl; //I output new price for new price cahnged true or not

								}
								else {

									cout << "There are not a product like that!!!" << endl;
									cout << "PLEASE TRY NEW PRDOUCT" << endl;
									goto trynewmusicprice;                                              //I put tis beacuse of admin if enter a product there is not in product list, I want to enter again
								}
								}
								else if (thirtOption == 3) {				//here going to be exit but admin can select here than when select something secondOption will workk
									
									cout << "1. Book\n2. Movie\n3. Music\n4. Exit" << endl;
									cout << "---->";
									cin >> secondOption;
									cout << endl;

									
									
								}

							}
							else if (secondOption == 4) {

													
								goto d;
							}
						}
					}

				}
				else if (option == 2) {
					

					goto e;
				}


		}else {

			cout << "You entered wrong thing please enter again " << endl;

			goto e;
	
		}

	return 0;
}