#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "CarExpenseCalc.h"

int main() {
	// Write program template in here
	
	//Ask for:
		//# of days (check)
	int daysNum = integerInputPositive("Input number of days spent on trip: ", 0);
	printf("Number of days: %d\n", daysNum);
		//Time of departure (check)
	int *departTime = timeInput("Enter the time of your departure (XX:XX AM/PM): ");
	printf("Departure time: %.2d:%.2d\n", departTime[0], departTime[1]);
		//Time of arrival (check)
	int *arriveTime = timeInput("Enter the time of your arrival (XX:XX AM/PM): ");
	printf("Departure time: %.2d:%.2d\n", arriveTime[0], arriveTime[1]);
		//Airfare cost
		//Car rental costs (check)
		//Miles driven in private vehicle (check)
	double carExpenses = calculateCarExpenses(daysNum); //Takes care of rental, private, parking, and taxi
	printf("Total cost of rentals, private vehicles, parking, and taxis: %f\n", carExpenses);
		//Conference/Seminar registration fees
		//For Each Day:
			//Parking fee amount (check, see above)
			//Taxi fees (check, see above)
			//For Each Meal:
				//Meal cost
	
	//Run methods that calculate expenses

	//Output:
		//Total expenses incurred
	double incurredExpenses = carExpenses;
	printf("Total expenses incurred: %f\n", incurredExpenses);
		//Total allowed expenses
	double allowedExpenses = 0;
	allowedExpenses += calculateCarExpensesCovered();
	printf("Total allowed expenses: %f\n", allowedExpenses);
		//If allowed < incurred
			//The excess (incurred - allowed)
		//If allowed > incurred
			//The amount saved (allowed - incurred)
	if (allowedExpenses < incurredExpenses) {
		printf("Excess cost (to be paid by employee): %f", incurredExpenses - allowedExpenses);
	}
	else {
		printf("Amount of money saved: %f", allowedExpenses - incurredExpenses);
	} //end if

		
		

	return EXIT_SUCCESS;
}