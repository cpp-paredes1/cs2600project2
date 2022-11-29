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
	double parkingFees = integerInputPositive("How much will you spend on parking per day?: ", 1);
	double taxiFees = integerInputPositive("How much will you spend on taxis per day?: ", 1);
	return calculateCarExpensesNoPrompt(numDays, rentalFees, milesDriven, parkingFees, taxiFees);
}
double calculateCarExpensesNoPrompt(int numDays, double rentalFees, int miles, double parkingFees, double taxiFees){
	return rentalFees + (miles * pricePerMile) + (parkingFees * numDays) + (taxiFees * numDays);
}