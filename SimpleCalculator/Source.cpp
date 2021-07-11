#include <iostream>
#include <cmath>

using namespace std;

int main() {

	double P, r, t, n;

	cout << "What is your starting amount? (USD) \n";
	cin >>  P;
	cout << endl;

	cout << "What is the interest rate? (Whole numbers - no characters) \n";
	cin >>  r;
	cout << endl;

	cout << "How many years will you be investing? \n";
	cin >>  t;
	cout << endl;

	cout << "How frequently will you be investing in " << t << " years?" << endl << "(Enter '1' for annually, '12' for monthly, '52.1429' for weekly, or '365' for daily) \n";
	cin >>  n;
	cout << endl;

	double decimalPercent = r / 100;

	double compounding_interest = P * (pow(1 + (decimalPercent / n), (n * t)));

	system("CLS");

	cout << "Your ending value will be $" << compounding_interest << " with a Principal amount of $" << P << ", an interest rate of " << r << " percent, a timeframe of " << t << " year(s), and a frequency of " << n << " times per " << t << " year(s)" << endl;;
	
}
