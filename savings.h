/*Sean J Born
* June 9, 2024
* This program is used to add any deposits and calculate interest over several years.
*/
#ifndef SAVINGS_H_
#define SAVINGS_H_

class savings {
public:
	savings(double investment, double monthDeposit, double rate, int years);
	//class member function that you can redefine in a derived class to achieve
		virtual ~savings();
	void reportNoMonthlyDeposits();
	void reportMonthlyDeposits();

private:
	double firstDepo;
	double newMonthlyDepo;
	double annualInterestRate;
	int numOfYears;
};
#endif
