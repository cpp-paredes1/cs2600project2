#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "FoodHotelRegistrationCalc.h"
//Conference or seminar registration fees 
double calRegCost() {
	double regFees = 0;
	int run = 1;
	while (run == 1) {
		printf("\nEnter the total amount of registration fee:");
		scanf("%f", &regFees);
		if (regFees <= 0) {
			printf("\nPlease enter a valid amount");
		}
		else {
			return regFees;
		}
	}
}

double hotelCost() {
	static double costs[2];
	double cost, totalCost;
	int run = 1;
	while (run == 1) {
		printf("\nEnter hotel cost for one night:");
		scanf("%f", &cost);
		if (cost <= 0)
        {
            printf("\nPlease enter a valid number (>0)!");
        }
        else
        {
            if (cost <= 90)
            {
                costs[0] = cost;
                costs[1] = 0;
            }
            else
            {
                costs[0] = cost;
                totalCost = cost - 90;
                costs[1] = totalCost;
            }
            return costs;
        }
	}
}

//calculate breakfast
double *calBreakfast(double amount)
{
    static double costs[2];
    costs[0] = amount;
    if (amount <= 9)
    {
        costs[1] = 0;
    }
    else
    {
        amount = amount - 9;
        costs[1] = amount;
    }
    return costs;
}
//calculate lunch
double *calLunch(double amount)
{
    static double costs[2];
    costs[0] = amount;
    if (amount <= 12)
    {
        costs[1] = 0;
    }
    else
    {
        amount = amount - 12;
        costs[1] = amount;
    }
    return costs;
}

//calculate dinner
double *calDinner(double amount)
{
    static double costs[2];
    costs[0] = amount;
    if (amount <= 16)
    {
        costs[1] = 0;
    }
    else
    {
        amount = amount - 16;
        costs[1] = amount;
    }
    return costs;
}
