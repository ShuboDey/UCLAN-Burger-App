//Shubo Dey 
//G21008911

#include<iostream>
#include<iomanip>
using namespace std;

double totalPrice = 0;
double currentBalance = 0;
//displays the burger option
//reads the user's input of burger option selected 
//returns the burger selected by the user
string BurgerOptions(string burger)
{
	cout << "ORDER BURGER - Select Size " << endl;
	cout << "         " << endl;
	cout << "Please choose from the following options: " << endl;
	cout << "       " << endl;
	cout << " 1. Small  [3.00 Credits]" << endl;
	cout << " 2. Medium [5.50 Credits]" << endl;
	cout << " 3. Large  [7.25 Credits]" << endl;
	cout << "--------------------" << endl;
	cout << "Please enter a number: ";
	double burgerPrice = 0;
	double burgerOption = 0;
	cin >> burgerOption;
	while (cin.fail() || burgerOption <= 0 || burgerOption > 3) // checks whether the number enetered by the user is within the range of 0 to 3 
	{
		cin.clear();
		cin.ignore(80, '\n');
		cout << "Sorry, Please enter a number from 1 to 3!" << endl;// displays the text if the user input is not valid 
		cin >> burgerOption;	// asks the user to re-enter option until its valid 
	}
	if (burgerOption == 1)
	{
		burger = "You have selected a Small burger";
		burgerPrice += 3.00;
		totalPrice += burgerPrice;// total price is updated with the burger price 
	}
	else if (burgerOption == 2)
	{
		burger = "You have selected a Medium burger";
		burgerPrice += 5.50;
		totalPrice += burgerPrice;
	}
	else if (burgerOption == 3)
	{
		burger = "You have selected a Large burger";
		burgerPrice += 7.25;
		totalPrice += burgerPrice;
	}
	return burger; // returns string to the function based on the burger slected by the user
}
//dispalys the toppings option available to the user
//reads the user's input of toppings option
//returns the topping selected by the user
string ToppingsOption(string toppings)
{
	cout << "Please choose from the following toppings: " << endl;
	cout << "      " << endl;
	cout << " 1. Cheese       [0.80 Credits]" << endl;
	cout << " 2. Salad        [0.50 Credits]" << endl;
	cout << " 3. Bacon        [1.00 Credits]" << endl;
	cout << " 4. Ketchup      [0.30 Credits]" << endl;
	cout << " 5. Mayo         [0.30 Credits]" << endl;
	cout << " 6. Extra burger [1.50 Credits]" << endl;
	cout << "--------------------" << endl;
	cout << "please enter a number: ";
	double toppingPrice = 0;
	double toppingsOption = 0;
	cin >> toppingsOption;
	while (cin.fail() || toppingsOption < 0 || toppingsOption > 6) // checks whether the number enetered by the user is within the range of 0 to 6
	{
		cin.clear();
		cin.ignore(80, '\n');
		cout << "Sorry, Please enter a number from 1 to 6!" << endl;// displays the text if the user input is not valid 
		cin >> toppingsOption;
	}
	if (toppingsOption == 1)
	{
		toppings = "you have selected cheese to your burger";
		toppingPrice = 0.80;
		totalPrice += toppingPrice; // total price is updated with the topping price 
	}
	else if (toppingsOption == 2)
	{
		toppings = "you have selected salad to your burger";
		toppingPrice = 0.50;
		totalPrice += toppingPrice;
	}
	else if (toppingsOption == 3)
	{
		toppings = "you have selected bacon to your burger";
		toppingPrice = 1.00;
		totalPrice += toppingPrice;
	}
	else if (toppingsOption == 4)
	{
		toppings = "you have selected ketchup to your burger";
		toppingPrice = 0.30;
		totalPrice += toppingPrice;
	}
	else if (toppingsOption == 5)
	{
		toppings = "you have selected mayo to your burger";
		toppingPrice = 0.30;
		totalPrice += toppingPrice;
	}
	else if (toppingsOption == 6)
	{
		toppings = "you have selected an extra burger";
		toppingPrice = 1.50;
		totalPrice += toppingPrice;
	}
	return toppings; // returns string to the function based on the toppings slected by the user
}
//reads the amount entered by the user
//checks the validation of the amount whether its positive valure or not
//returns the amount entered by the user 
double AddCredits(double amount)
{
	cout << "Enter the amount you want to credit" << endl;
	cin >> amount;
	while (cin.fail() || (amount < 0 || amount == 0))// checks whether the number enetered by the user is a positve amount
	{
		cin.clear();
		cin.ignore(80, '\n');
		cout << "Please enter a valid amount" << endl;// displays the text if the user input is not valid 
		cin >> amount;
	}
	return amount; // returns amount selected by the user to the function 
}
//displays the main menu 
void MainMenu()
{
	cout << "--------------------" << endl;
	cout << "    UCLAN BURGER" << endl;
	cout << "--------------------" << endl;
	cout << "Main Menu" << endl;
	cout << "   1. Add Credits [Current Balance = " << fixed << setprecision(2) << currentBalance << " Credits]" << endl;
	cout << "   2. Order Burger" << endl;
	cout << "   0. Exit " << endl;
}
//displays the purchase amount of the burger
//returns the remaining credit after purchase
void Transaction()
{
	cout << "-----------------------" << endl;
	cout << "Current balance = " << currentBalance << endl;
	cout << "Total price = " << totalPrice << endl;
	cout << "-----------------------" << endl;
	cout << "Remaining balance = " << currentBalance - totalPrice << endl;
	cout << "-----------------------" << endl;
}
//allows the user to select multiple toppings.
//displays as many times called by the user for additional toppings
void AdditionalToppings()
{
	cout << "Would you like to add more toppings? " << endl;
	cout << "please enter 'y' for yes and 'n' for no: " << endl;
	char userOption;
	cin >> userOption;
	userOption = tolower(userOption); // converts any upper case character entered by the user to a lower case  
	while (cin.fail() || (userOption != 'y' && userOption != 'n'))// checks whether the option selected by the user is yes or no 
	{
		cin.clear();
		cin.ignore(80, '\n');
		cout << "Sorry, invalid input. Enter 'y' for yes and 'n' for no" << endl;// displays the text if the user input is not valid 
		cin >> userOption;
		userOption = tolower(userOption);// converts any upper case character entered by the user to a lower case 
	}
	if (userOption == 'y')
	{
		string userToppings = "";
		userToppings = ToppingsOption(userToppings);// variable userToppings is used as a input to the function 
		cout << userToppings << endl;
		cout << "Would you like to add more toppings?" << endl;
		cout << "please enter 'y' for yes and 'n' for no" << endl;
		cin >> userOption;
		userOption = tolower(userOption);// converts any upper case character entered by the user to a lower case 
		while (cin.fail() || (userOption != 'y' && userOption != 'n'))// checks whether the option selected by the user is yes or no 
		{
			cin.clear();
			cin.ignore(80, '\n');
			cout << "Sorry, invalid input. Enter 'y' for yes and 'n' for no" << endl;// displays the text if the user input is not valid 
			cin >> userOption; //asks the user to re-enter the option again
			userOption = tolower(userOption);// converts any upper case character entered by the user to a lower case 
		}
	}
	else if (userOption == 'n')
	{
		cout << "Thanks for using our service. goodbye! and have a nice burger:)" << endl;
	}
}
int main()
{
	double userCredit = 0;
	currentBalance += userCredit; // current balance is intitalized by credits entered by user
	MainMenu();
	cout << "Please enter a number: ";
	int userOption = 0;
	cin >> userOption;
	while (cin.fail() || userOption < 0 || userOption > 2)// checks whether the option selected by the user is within the valid range of 0 to 2
	{
		cin.clear();
		cin.ignore(80, '\n');
		cout << "Sorry, Please enter a number from 0 to 2!" << endl;// displays the text if the user input is not valid 
		cin >> userOption;// asks the user to re-enter the option 
	}
	if (userOption == 1) //displays the following code if the option selected by the user is 1
	{
		double amount = 0;
		currentBalance += AddCredits(amount);// updates the user balance after user completes adding credits
		cout << "[current Balance = " << fixed << setprecision(2) << currentBalance << " Credits]" << endl; // displays the current balance upto 2 decimal places

		string burger = "";
		string burgerSelected = BurgerOptions(burger); // variable burger is used as a input to the function 
		cout << burgerSelected << endl; // displays the burger selected by the user
		string toppings = "";
		string toppingSelected = ToppingsOption(toppings);// variable toppings is used as a input to the function 
		cout << toppingSelected << endl; // dispalys the toppings selected by the user

		if (totalPrice < currentBalance) // checks whether the total price of burger and topping is less than the credit entered by the user or not 
		{
			AdditionalToppings();// allows the user to select additional toppings 
			Transaction();// displays the total price and the remaining balance of the burger
			cout << "Would you like to purchase another burger" << endl;
			cout << "please enter 'y' for yes and 'n' for no: " << endl;
			char purchaseBurger;
			cin >> purchaseBurger;// users enters char 'y' to purchase another burger or 'n' to exit 
			purchaseBurger = tolower(purchaseBurger);
			while (cin.fail() || (purchaseBurger != 'y' && purchaseBurger != 'n')) // checks whether the character entered by the user is yes or no
			{
				cin.clear();
				cin.ignore(80, '\n');
				cout << "Sorry, invalid input. Enter 'y' for yes and 'n' for no" << endl; // displays the text if the user input is not valid 
				cin >> purchaseBurger;
				purchaseBurger = tolower(purchaseBurger);// converts any upper case character entered by the user to a lower case
			}
			while (purchaseBurger == 'y')
			{
				string burger = "";
				string burgerSelected = BurgerOptions(burger); // variable burger is used as a input to the function
				cout << burgerSelected << endl;

				string toppings = "";
				string toppingSelected = ToppingsOption(toppings); // variable toppings is used as a input to the function
				cout << toppingSelected << endl;
			}
			cout << "Thanks for using our service. goodbye! and have a nice burger:)" << endl;
		}
		else
		{
			cout << "you dont have suffiecient balance" << endl; // displays the text if the total price of the burger selected by the user is less than the credits entered by the user
			currentBalance += AddCredits(amount);
			if (totalPrice < currentBalance)
			{
				cout << "Transaction Accepted." << endl;
				Transaction(); // displays the total price and the remaining balance of the burger
			}
		}
	}
	else if (userOption == 2)
	{
		cout << "you dont have sufficient balance!" << endl; // displays the text if the total price of the burger selected by the user is less than the credits entered by the user 
		cout << "[Current Balance = " << currentBalance << " Credits]" << endl;
	}
	else if (userOption == 0)
	{
		cout << "Thanks for using our service." << endl;
	}
	system("pause");
	return 0;
}