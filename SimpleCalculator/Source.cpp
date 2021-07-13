#include <iostream>
#include <cmath>

using namespace std;

/*
A simple CLI calculator program that currently only calculates compounding interest, but will be expanded on in the future. 
If you are reading this, then how did you get here? I'm just a high school student writing sloppy code. Let me know what you think of this mess here on Github!
*/


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

	double decimalPercent = r / 100; // Converts interest rate to decimal value for ease of use

	double compounded_principal = P * (pow(1 + (decimalPercent / n), (n * t))); // Standard compounding interest formula

	system("CLS");

	cout << "Your ending value will be $" << compounded_principal << " with a Principal amount of $" << P << ", an interest rate of " << r << " percent, a timeframe of " << t << " year(s), and a frequency of " << n << " times per " << t << " year(s)" << endl;;

	// Informs user of final value, along with what they would be putting in for their Principal values, interest rate, timeframe, and frequency
}


int main() {

	compounding_interest();
}
