/*Sean J Born
* June 9, 2024
* This program is used to add any deposits and calculate interest over several years. 
*/
#include <iostream>
#include "savings.h"
using namespace std;

int main() {
	//infinite loop tht runs until a break statement
	while (1) {
		//print heading
		cout << "*************************************" << endl;
		cout << "*************Data Input**************" << endl;
		cout << "Initial Investment Amount: " << endl;
		cout << "Monthly Deposit: " << endl;
		cout << "Annual Interest: " << endl;
		cout << "Number of years: " << endl;

		//system PAUSE;
		system("read -p 'Press Enter to continue . . .' var");
		cout << endl;

		//Inputs from user
		cout << "*************************************" << endl;
		cout << "*************Data Input**************" << endl;
		cout << "Initial Investment Amount: $";

		double investment, depositmonthly, rateofinterest;
		int years;

		cin >> investment;
		cout << "Monthly Deposit: $";

		cin >> depositmonthly;
		cout << "Annual Interest: %";

		cin >> rateofinterest;
		cout << "Number of years: ";
		cin >> years;

		//system PAUSE;
		system("read -p 'Press Enter to continue . . .' var");

		// using inputs, create a savings object.
		savings mycurrentsavings = savings(investment, depositmonthly, rateofinterest, years);
		cout << endl;

		// Make use of the report 
		mycurrentsavings.reportNoMonthlyDeposits();
		cout << endl;

		//If there is a monthly deposit of at least $1, call monthly deposit report
		if (depositmonthly > 0) {
			mycurrentsavings.reportMonthlyDeposits();
		}

		// Ask the user if they would want to try another option
		cout << endl << "Do you want to try another? (y/n): ";

		string choice;
		cin >> choice;

		// Break the loop 
		if (choice != "y") {
			break;
		}
		cout << endl;
	}
	return 0;
}
	
