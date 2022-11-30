#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "input.h"
#include "CarExpenseCalc.h"

extern int integerInputPositive(char*, int);
extern double doubleInputPositive(char*, int);

const double pricePerMile = 0.27;

double calculateCarExpenses(int numDays){
	int milesDriven = 0;
	int numRentals = integerInputPositive("How many cars will you rent?: ", 1);
	if(numRentals == 0){
		printf("Number of rental cars = 0. Assuming the use of a private car.\n");
		milesDriven = integerInputPositive("How many miles will you drive?: ", 1);
	}
	double rentalFees = 0.0f;
	for(int i = 1; i <= numRentals; i++){
		printf("How much does Car #%i cost to rent?: ", i);
		rentalFees += doubleInputPositive("", 1);
	}
	
	double totalParkingFees = calculateParkingFees(numDays);
	double totalTaxiFees = calculateTaxiFees(numDays);

	return calculateCarExpensesNoPrompt(rentalFees, milesDriven, totalParkingFees, totalTaxiFees);
}
double calculateCarExpensesNoPrompt(double rentalFees, int miles, double parkingFees, double taxiFees){
	return rentalFees + (miles * pricePerMile) + parkingFees + taxiFees;
}
double calculateParkingFees(int numDays) {
	double parkingFees = 0.0f;

	for (int i = 0; i < numDays; i++) {
		printf("Day %d:\n", i+1);
		parkingFees = parkingFees + doubleInputPositive("How much will you spend on parking on this day?: ", 1);
	}
	
	return parkingFees;
}
double calculateTaxiFees(int numDays) {
	double taxiFees = 0.0f;

	for (int i = 0; i < numDays; i++) {
		printf("Day %d:\n", i+1);
		taxiFees = taxiFees + doubleInputPositive("How much will you spend on taxis on this day?: ", 1);
	}
	
	return taxiFees;
}