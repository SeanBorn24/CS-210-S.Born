/*Sean J Born
* June 9, 2024
* This program is used to add any deposits and calculate interest over several years.
*/
#include <iomanip>
#include <iostream>
#include "savings.h"
using namespace std;
// constructor 
// variables values have been set

savings::savings(double investment, double monthDeposit, double rate, int years) {

	// The 'this' pointer is used to retrieve the object's
	// hidden by the local variable
	this->firstDepo = investment;
	this->newMonthlyDepo = monthDeposit;
	this->annualInterestRate = rate;
	this->numOfYears = years;
}

//Destructor
savings::~savings() {
}

// Monthly deposits are not included in printed reports
void savings::reportNoMonthlyDeposits() {
	//Print heading for balance and interest
	cout << " Balance and Interest without additional Monthly Deposits" << endl;
	cout <<"==========================================================================" << endl;
		// table header printed
		cout << setw(10) << "Year"
		<< setw(20) << "Year End Balance"
		<< setw(35) << "Year End Earned Interest Rate" << endl;
	cout << "--------------------------------------------------------------------------" << endl;

	// calculate interest.
	int presentyear = 1;
	double endofyearBalance = this->firstDepo;
	while (presentyear <= this->numOfYears) {

		//Calculate interest
		double earnedinterest = endofyearBalance * this->annualInterestRate / 100;

		// Add to the year end Balance
		endofyearBalance += earnedinterest;

		// Printing out each year's results
		cout << right << setw(10) << presentyear << fixed << setprecision(2)
			<< setw(20) << endofyearBalance
			<< setw(35) << earnedinterest << endl;

		// Adding one year 
		presentyear++;
	}
}
// while collecting the monthly deposit, print reports
void savings::reportMonthlyDeposits() {
	// Printing the Balance and Interest heading
	cout << " Balance and Interest without additional Monthly Deposits" << endl;
	cout <<
		"==========================================================================" << endl;
		// Print the year and balance table header
		cout << setw(10) << "Year"
		<< setw(20) << "Year End Balance"
		<< setw(35) << "Year End Earned Interest Rate" << endl;
	cout << "--------------------------------------------------------------------------" << endl;
	// Calculate interest 
	int presentyear = 1;
	double endofyearBalance = this->firstDepo;
	while (presentyear <= this->numOfYears) {

		// Calculate monthly interest to determine compound interest.
		int month = 1;
		double earnedinterest = 0.0;
		double endofmonthbalance = endofyearBalance;
		while (month <= 12) {

			// Add a monthly payment.
			endofmonthbalance += this->newMonthlyDepo;

			// Interest is calculated monthly; and multiply the rate by 12
			double monthlyinterest = endofmonthbalance * this->annualInterestRate / (100 * 12);

			// Add the yearly interest  to the  interest
			earnedinterest += monthlyinterest;

			// add the interest to the month's final balance
			endofmonthbalance += monthlyinterest;

			// increse the month by one
			month++;
		}
		// after one year(12)
		endofyearBalance = endofmonthbalance;
		// Print the outcomes
		// 'setprecision'function is used to format floating-point values
		// 'setw' function is a C++ manipulator which stands for set width
		cout << right << setw(10) << presentyear << fixed << setprecision(2)
			<< setw(20) << endofyearBalance
			<< setw(35) << earnedinterest << endl;
		// Add one more year to the count
		presentyear++;
	}
}
