#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;
void heading();
float compute_gross_pay(int, float, char);
float compute_taxes(float);
float compute_federal_tax(float);
float compute_state_tax(float);
float compute_city_tax(float);
float compute_net_pay(float, float);
void print_pay_check(string, int, string, string, string, string, int, string, float, float, float);
void heading()
{
	cout << "**********************************************************\n";
	cout << "Osi Otugo\n";
	cout << "@02662492\n";
	cout << "October 26, 2015\n";
	cout << "Assignment 7\n";
	cout << "**********************************************************\n";
}

int main()
{
	//Declare variables and set it equal to the corresponding data
	string firstName, lastName, name, streetName, streetType, city, state, date; 
	int deductions, id, houseNumber, zip; 
	float rate, taxes, grossPay, netPay; 
	char employmentAvailablility;
	ifstream myFile;
	myFile.open("infile.txt");
	//Ignore first two lines of infile
	myFile.ignore(200, '\n');
	myFile.ignore(1, '\n');
	//Extract data from infile
	myFile >> lastName >> firstName >> deductions >> id >> houseNumber >> streetName
		>> streetType >> city >> state >> zip >> rate >> employmentAvailablility;
	//Concatenate the first and last names
	name = lastName + " " + firstName;
	//Prompts user for a date to use in the print pay check function
	cout << "Please enter a date: ";
	getline(cin, date);
	//Calls the function compute_gross_pay and assigns the variable, grossPay, its return value
	grossPay = compute_gross_pay(deductions, rate, employmentAvailablility);
	//Calls the function compute_taxes and assigns the variable, taxes, its return value
	taxes = compute_taxes(grossPay);
	//Calls the function compute_net_pay and assigns the variable, netPay, its return value
	netPay = compute_net_pay(grossPay, taxes);
	//Calls the print pay check function
	print_pay_check(name, houseNumber, streetName, streetType, city, state, zip, date, grossPay, 
		netPay, taxes);
	//Repeat the above for the remaining people:
	myFile >> lastName >> firstName >> deductions >> id >> houseNumber >> streetName
		>> streetType >> city >> state >> zip >> rate >> employmentAvailablility;
	name = lastName + " " + firstName;
	grossPay = compute_gross_pay(deductions, rate, employmentAvailablility);
	taxes = compute_taxes(grossPay);
	netPay = compute_net_pay(grossPay, taxes);
	print_pay_check(name, houseNumber, streetName, streetType, city, state, zip, date, grossPay,
		netPay, taxes);
	myFile >> lastName >> firstName >> deductions >> id >> houseNumber >> streetName
		>> streetType >> city >> state >> zip >> rate >> employmentAvailablility;
	name = lastName + " " + firstName;
	grossPay = compute_gross_pay(deductions, rate, employmentAvailablility);
	taxes = compute_taxes(grossPay);
	netPay = compute_net_pay(grossPay, taxes);
	print_pay_check(name, houseNumber, streetName, streetType, city, state, zip, date, grossPay,
		netPay, taxes);
	myFile >> lastName >> firstName >> deductions >> id >> houseNumber >> streetName
		>> streetType >> city >> state >> zip >> rate >> employmentAvailablility;
	name = lastName + " " + firstName;
	grossPay = compute_gross_pay(deductions, rate, employmentAvailablility);
	taxes = compute_taxes(grossPay);
	netPay = compute_net_pay(grossPay, taxes);
	print_pay_check(name, houseNumber, streetName, streetType, city, state, zip, date, grossPay,
		netPay, taxes);
	myFile >> lastName >> firstName >> deductions >> id >> houseNumber >> streetName
		>> streetType >> city >> state >> zip >> rate >> employmentAvailablility;
	name = lastName + " " + firstName;
	grossPay = compute_gross_pay(deductions, rate, employmentAvailablility);
	taxes = compute_taxes(grossPay);
	netPay = compute_net_pay(grossPay, taxes);
	print_pay_check(name, houseNumber, streetName, streetType, city, state, zip, date, grossPay,
		netPay, taxes);
	myFile >> lastName >> firstName >> deductions >> id >> houseNumber >> streetName
		>> streetType >> city >> state >> zip >> rate >> employmentAvailablility;
	name = lastName + " " + firstName;
	grossPay = compute_gross_pay(deductions, rate, employmentAvailablility);
	taxes = compute_taxes(grossPay);
	netPay = compute_net_pay(grossPay, taxes);
	print_pay_check(name, houseNumber, streetName, streetType, city, state, zip, date, grossPay,
		netPay, taxes);
	system("pause");
}
//Computes gross pay
float compute_gross_pay(int deductions, float payRate, char employmentAvail)
{
	//If the employee is part-time then there is an increase of $10.50 multiplied by the num
	//of deductions.
	if (employmentAvail == 'P')
	{
		return (40.0 * payRate) + (10.5*deductions);
	}
	else
	{
		//If the employee is full time just multiply the payRate by 40
		return 40.0 * payRate;
	}
}
//Computes the total taxes of the gross pay
float compute_taxes(float grossPay)
{
	//Declare and assign values to the variable respective to thei functions
	float fedTax = compute_federal_tax(grossPay);
	float stateTax = compute_state_tax(fedTax);
	float cityTax = compute_city_tax(stateTax);
	//Return the sum of the federal, state, and city taxes.
	return fedTax + stateTax + cityTax;
}
//Computes the federal tax of the gross pay
float compute_federal_tax(float grossPay)
{
	if (grossPay <= 200)
	{
		//Return 15% of the gross pay if the gross pay is less than or equal to 200
		return 0.15 * grossPay;
	}
	else if ((grossPay > 200) && (grossPay <= 500))
	{
		//Return 25% if the gross pay is greater than 200 but less than or equal to 500
		return 0.25 * grossPay;
	}
	else
	{
		//Return 35% of the gross pay if the pay is greater than 500 
		return 0.35 * grossPay;
	}
}
//Computes state tax based off the federal tax
float compute_state_tax(float federalTax)
{
	if (federalTax < 80)
	{
		//If the federal tax is less than $80, return 0.0
		return 0.0;
	}
	else
	{
		//If the federal tax is greater than or equal to $80, return 10% of the federal tax
		return 0.1 * federalTax;
	}
}
//Computes the city tax
float compute_city_tax(float stateTax)
{
	if (stateTax <= 50)
	{
		//Return 0.0 if the state tax is less than $50
		return 0.0;
	}
	else
	{
		//If the state tax is greater than $50, return 8% of the state tax
		return 0.08 * stateTax;
	}
}
//Computes net pay
float compute_net_pay(float grossPay, float totalTaxes)
{
	return grossPay - totalTaxes;
}
//Prints the pay check
void print_pay_check(string name, int houseNumber, string streetName, string streetType, string city,
	string state, int zip, string date, float grossPay, float netPay, float taxes)
{
	cout << "********************************************************************************"
		<< endl;
	cout << "ABC Flowers" << endl;
	cout << "123 Georgia Ave." << setw(48) << date << endl << "Washington, DC 20059" << endl;
	cout << "Payable to: " << "\t" << name << setw(37) << "Pay this amount: $"
		<< setprecision(2) << fixed << showpoint << netPay << endl;
	cout << "\t\t" << houseNumber << " " + streetName << endl;
	cout << "\t\t" << city + " " + state + " " << zip << endl << endl;
	cout << "Gross Pay $" << setprecision(2) << fixed << showpoint << grossPay << endl;
	cout << "Total Taxes $" << setprecision(2) << fixed << showpoint << taxes << endl << endl;
}
/*
Please enter a date: 10/27/2015
********************************************************************************

ABC Flowers
123 Georgia Ave.                                      10/27/2015
Washington, DC 20059
Payable to:     Herold, Will                   Pay this amount: $170.10
123 Main
Washington, DC 20019

Gross Pay $226.80
Total Taxes $56.70

********************************************************************************

ABC Flowers
123 Georgia Ave.                                      10/27/2015
Washington, DC 20059
Payable to:     Jackson, Stan                   Pay this amount: $320.45
12 Douglas
Baltimore, MD 30229

Gross Pay $442.00
Total Taxes $121.55

********************************************************************************

ABC Flowers
123 Georgia Ave.                                      10/27/2015
Washington, DC 20059
Payable to:     Jerry, Francis                   Pay this amount: $597.47
2345 6th
Woodbridge, VA 44040

Gross Pay $971.50
Total Taxes $374.03

********************************************************************************

ABC Flowers
123 Georgia Ave.                                      10/27/2015
Washington, DC 20059
Payable to:     John, Wilson                   Pay this amount: $301.60
12 Georgia
Washington, DC 20019

Gross Pay $416.00
Total Taxes $114.40

********************************************************************************

ABC Flowers
123 Georgia Ave.                                      10/27/2015
Washington, DC 20059
Payable to:     Smith, Stanley                   Pay this amount: $338.86
56 D
Baltimore, MD 30229

Gross Pay $551.00
Total Taxes $212.14

********************************************************************************

ABC Flowers
123 Georgia Ave.                                      10/27/2015
Washington, DC 20059
Payable to:     Jeffers, Claude                   Pay this amount: $1029.23
66 32nd
Woodbridge, VA 44040

Gross Pay $1681.20
Total Taxes $651.97

Press any key to continue . . .
*/