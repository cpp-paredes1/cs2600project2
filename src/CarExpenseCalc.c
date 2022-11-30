#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "input.h"
#include "CarExpenseCalc.h"

const double pricePerMile = 0.27;
int milesDriven;
int numRentals;
double rentalFees;
int numDaysParked;
int numDaysTaxi;


double calculateCarExpenses(int numDays){
	milesDriven = 0;
	int numRentals = integerInputPositive("\nHow many cars will you rent?: ", 1);
	if(numRentals == 0){
		printf("Number of rental cars = 0. Assuming the use of a private car.\n");
		milesDriven = integerInputPositive("How many miles will you drive?: ", 1);
	}
	rentalFees = 0.0f;
	for(int i = 1; i <= numRentals; i++){
		printf("How much does Car #%i cost to rent?: ", i);
		rentalFees += doubleInputPositive("", 1);
	}
	printf("\n");	// space them out for visual clarity
	double totalParkingFees = calculateParkingFees(numDays);
	printf("\n");	// space them out for visual clarity
	double totalTaxiFees = calculateTaxiFees(numDays);
	printf("\n");
	return calculateCarExpensesNoPrompt(rentalFees, milesDriven, totalParkingFees, totalTaxiFees);
}
double calculateCarExpensesNoPrompt(double rentalFees, int miles, double parkingFees, double taxiFees){
	return rentalFees + (miles * pricePerMile) + parkingFees + taxiFees;
}
double calculateParkingFees(int numDays) {
	double parkingFees = 0.0f;
	numDaysParked = 0;
	for (int i = 0; i < numDays; i++) {
		printf("Day %d: ", i+1);
		double tmp = doubleInputPositive("How much will you spend on parking on this day?: ", 1);
		if(tmp != 0){
			numDaysParked++;
		}
		parkingFees += tmp;
	}
	
	return parkingFees;
}
double calculateTaxiFees(int numDays) {
	double taxiFees = 0.0f;
	numDaysTaxi = 0;
	for (int i = 0; i < numDays; i++) {
		printf("Day %d: ", i+1);
		double tmp = doubleInputPositive("How much will you spend on taxis on this day?: ", 1);
		if(tmp != 0){
			numDaysTaxi++;
		}
		taxiFees += tmp;
	}
	
	return taxiFees;
}

double calculateCarExpensesCovered(){
	return rentalFees + (milesDriven * 0.27) + (numDaysParked * 6) + (numDaysTaxi * 10);
}