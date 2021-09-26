#include <iostream>
#include <cmath>

using namespace std;

/*
A simple CLI calculator program that currently only calculates compounding interest and amortization, but will be expanded on in the future. 

########################################################

Code is broken when using ammortization calculator. 
Something to do with turning interest rates into decimals.

########################################################
*/

void menu();
void compounding_interest();
void amortization();
void return_to_menu();

int main() {

	menu();

	return 0;
}

void menu() {

	int x;

	cout << "1. Amortization Calculator (Recurring debt payments)            2. Compounding Interest Calculator \n\n";
	cout << "Which tool would you like to use? \nEnter '1' or '2', or alternatively type '9' to quit: ";

	cin >> x;

	cout << endl;

	switch (x)
	{
	case 1:
		amortization();
	case 2:
		compounding_interest();
	case 9:
		cout << "Thanks for stopping by! " << endl;
		exit(0);
	default:
		cout << "Invalid option! ";
		menu();
	}
}

double nonZeroInterest(double r) {
	if (r == 0) {
		cout << "Interest rate cannot be zero! \n";
		cout << "What is the interest rate? (Whole numbers - no characters) \n"; // Asks for interest rate in whole numbers
		cin >> r;
		cout << endl;
		return r;
	}
}

double decimalPercent(double r) { // Converts interest rate to decimal value for ease of use
	r = r / 100;
	return r;
}

void compounding_interest() {

	/* Initializing variables
	P - principal amount to be invested (in USD)
	r - interest rate to be used (as a whole number)
	t - period of time money will be invested (in years)
	n - frequency of investment per period
	*/

	double P, r, t, n;

	cout << "What is your starting amount? (USD) \n"; // Asks for the principal amount being invested (in USD)
	cin >> P;
	cout << endl;

	cout << "What is the interest rate? (Whole numbers - no characters) \n"; // Asks for interest rate in whole numbers
	cin >> r;
	cout << endl;

	cout << "How many years will you be investing? \n"; // Asks number of years money will be invested
	cin >> t;
	cout << endl;

	cout << "How frequently will you be investing in " << t << " years?" << endl << "(Enter '1' for annually, '12' for monthly, '52.1429' for weekly, or '365' for daily) \n"; // Asks for frequency of investment per period
	cin >> n;
	cout << endl;

	r = decimalPercent(r); // Converts interest rate to decimal value for ease of use

	double compounded_principal = P * (pow(1 + (r / n), (n * t))); // Standard compounding interest formula

	system("CLS");

	// Informs user of final value, along with what they would be putting in for their Principal values, interest rate, timeframe, and frequency

	cout << "Your ending value will be $" << compounded_principal << " with a Principal amount of $" << P << ", an interest rate of " << r << " percent, a timeframe of " << t << " year(s), and a frequency of " << n << " times every year for " << t << " year(s)." << endl;
	
	return_to_menu();
}

void amortization() {
	
	/* Initializing variables
	P - principal amount to be invested (in USD)
	r - interest rate to be used (as a whole number)
	t - period of time debt will be paid off (in years)
	n - frequency of payment per period
	*/

	double P, r, t, n;

	cout << "What is your starting amount? (USD) \n"; // Asks for the principal amount being invested (in USD)
	cin >> P;
	cout << endl;

	cout << "What is the interest rate? (Whole numbers - no characters) \n"; // Asks for interest rate in whole numbers
	cin >> r;
	cout << endl;

	if (r <= 0) {
		cout << "Interest rate must be greater than zero ... quitting!" << endl;
		exit(1);
	}

	cout << "In how many months will you be paying off this debt? \n"; // Asks number of months until debt is paid
	cin >> t;
	cout << endl;

	cout << "How frequently will you be paying in " << t << " months?" << endl; // Asks for frequency of investment per period
	cin >> n;
	cout << endl;

	r = decimalPercent(r); // Converts interest rate to decimal value for ease of use

	double ammortization = (P * (r / n)) / (1 - (pow((1 + r / n), (-n * t)))); // Standard formula for figuring out recurring payment for a debt

	system("CLS");

	// Describes what user will be paying per period to pay off debt within specified time

	cout << "You will be paying $" << ammortization << " in " << t << " months, with a principal value of $" << P << " and an interest rate of " << r << " percent." << endl;

	return_to_menu();
}

void return_to_menu() {

	int x;

	cout << endl;

	cout << "Type '1' to go back to the menu or '9' to quit: ";
	cin >> x;
	cout << endl;

	switch (x)
	{
	case 1:
		menu();
	case 9:
		cout << "Thanks for stopping by! " << endl;
		exit(0);
	default:
		cout << "Invalid option! ";
		return_to_menu();
	}
}
