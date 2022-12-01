#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "CarExpenseCalc.h"
#include "PlaneExpenseCalc.h"
extern int test();
int main(int argc, char const *argv[]) {
	// Perform unit tests if first argument is "test"
	if (argc == 2 && strcmp(argv[1], "test") == 0) {
		return test();
	}
	//Ask for:
		//# of days (check)
	int daysNum = integerInputPositive("Input number of days spent on trip: ", 0);
	printf("Number of days: %d\n\n", daysNum);
		//Time of departure (check)
	int *departTime = timeInput("Enter the time of your departure (XX:XX AM/PM): ");
	printf("Departure time: %002d:%002d\n", departTime[0], departTime[1]);
		//Time of arrival (check)
	int *arriveTime = timeInput("Enter the time of your arrival (XX:XX AM/PM): ");
	printf("Departure time: %002d:%002d\n\n", arriveTime[0], arriveTime[1]);
		//Airfare cost (check)
		//Car rental costs (check)
		//Miles driven in private vehicle (check)
	double planeExpenses = calculatePlaneExpenses();
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
	double incurredExpenses = 0;
	incurredExpenses += carExpenses + planeExpenses;
	printf("Total expenses incurred: %f\n", incurredExpenses);
		//Total allowed expenses
	double allowedExpenses = 0;
	allowedExpenses += calculateCarExpensesCovered() + planeExpenses;
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
