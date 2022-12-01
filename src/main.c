#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "CarExpenseCalc.h"
#include "PlaneExpenseCalc.h"
#include "FoodHotelRegistrationCalc.h"
#include "test.h"

int main(int argc, char const *argv[]) {
	// Perform unit tests if first argument is "test"
	if (argc == 2 && strcmp(argv[1], "test") == 0) {
		return test();
	}
	//constants for meal expenses
	const double BREAKFASTALLOWED = 9.0;
	const double LUNCHALLOWED = 12.0;
	const double DINNERALLOWED = 16.0;
	const double HOTELALLOWED = 90.0;
	//Ask for:
		//# of days (check)
	int daysNum = integerInputPositive("Input number of days spent on trip: ", 0);
	printf("Number of days: %d\n\n", daysNum);
		//Time of departure (check)
	int *departTime = timeInput("Enter the time of your departure (XX:XX AM/PM): ");
	printf("Departure time: %002d:%002d\n", departTime[0], departTime[1]);
		//Time of arrival (check)
	int *arriveTime = timeInput("Enter the time of your arrival (XX:XX AM/PM): ");
	printf("Arrival time: %002d:%002d\n\n", arriveTime[0], arriveTime[1]);
		//Airfare cost (check)
		//Car rental costs (check)
		//Miles driven in private vehicle (check)
	double planeExpenses = calculatePlaneExpenses();
	double carExpenses = calculateCarExpenses(daysNum); //Takes care of rental, private, parking, and taxi
	printf("Total cost of rentals, private vehicles, parking, and taxis: %f\n", carExpenses);
		//Conference/Seminar registration fees
	double regExpenses = regCost();
	printf("Conference and Seminar registration fees: %f\n", regExpenses);
		//Hotel Fees
	double *tempHotelExpenses = hotelCost();
	double hotelExpenses = tempHotelExpenses[0] + tempHotelExpenses[1];
	printf("\nHotel expenses: %f\n", hotelExpenses);
		//For Each Day:
			//Parking fee amount (check, see above)
			//Taxi fees (check, see above)
	int timesForMeals[2];
	timesForMeals[0] = departTime[0];
	timesForMeals[1] = arriveTime[0];
	double *tempMealExpenses = calMealCost(daysNum, timesForMeals);
	double mealExpenses = tempMealExpenses[0] + tempMealExpenses[1];
	printf("Meal expenses: %f\n", mealExpenses);
			//For Each Meal:
				//Meal cost
	
	//Run methods that calculate expenses

	//Output:
		//Total expenses incurred
	double incurredExpenses = 0;
	incurredExpenses += carExpenses + planeExpenses + regExpenses + hotelExpenses + mealExpenses;
	printf("Total expenses incurred: %f\n", incurredExpenses);
		//Total allowed expenses
	double allowedExpenses = 0;
	
	if (departTime[0] < 7) {
		allowedExpenses += BREAKFASTALLOWED;
	}
	else if (departTime[0] < 12) {
		allowedExpenses += BREAKFASTALLOWED + LUNCHALLOWED;
	}
	else if (departTime[0] < 18) {
		allowedExpenses += BREAKFASTALLOWED + LUNCHALLOWED + DINNERALLOWED;
	} //end if
	
	if (arriveTime[0] > 8 && arriveTime[1] > 0) {
		allowedExpenses += BREAKFASTALLOWED;
	}
	else if (arriveTime[0] > 13 && arriveTime[1] > 0) {
		allowedExpenses += BREAKFASTALLOWED + LUNCHALLOWED;
	}
	else if (arriveTime[0] > 19 && arriveTime[1] > 0) {
		allowedExpenses += BREAKFASTALLOWED + LUNCHALLOWED + DINNERALLOWED;
	} //end if
	allowedExpenses += HOTELALLOWED * daysNum;
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
