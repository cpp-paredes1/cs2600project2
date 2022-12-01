#include <stdio.h>
#include "FoodHotelRegistrationCalc.h"
#include "test.h"

int testFoodExpenses(int testNum, double testArgs[4]) {
    double *(*calcFunction)(double);
    switch ((int)testArgs[0]) {
        case 0:
            calcFunction = &calBreakfast;
            break;
        case 1:
            calcFunction = &calLunch;
            break;
        case 2:
            calcFunction = &calDinner;
            break;
        default:
            break;
    }

    double *calc = (*calcFunction)(testArgs[1]);
    double expected[] = {testArgs[2], testArgs[3]};
    printf("\tTest %i: Expected: %.2f/%.2f | Result: %.2f/%.2f", expected[0], expected[1], testNum + 1, calc[0], calc[1]);
	return printTest("", calc[0] == expected[0] && calc[1] == expected[1]);
}

int testHotelExpenses(int testNum, double testArgs[3]) {
    double *calc = calHotelCost(testArgs[0]);
    double expected[] = {testArgs[1], testArgs[2]};
    printf("\tTest %i: Expected: %.2f/%.2f | Result: %.2f/%.2f", expected[0], expected[1], testNum + 1, calc[0], calc[1]);
	return printTest("", calc[0] == expected[0] && calc[1] == expected[1]);
}

int testRegistrationExpenses(int testNum, double testArgs[2]) {
    double calc = calRegCost(testArgs[0]);
    double expected = testArgs[1];
    printf("\tTest %i: Expected: %.2f | Result: %.2f", testNum + 1, expected, calc);
	return printTest("", calc == expected);
}

int testFoodHotelRegistrationExpenses() {
	printf("FOOD/HOTEL/REGISTRATION TESTS\n");
	printf("---------------\n");

	// Food tests
	// mealType, amount, expected[0], expected[1]
    double foodTestData[][4] = {
        {0, 3.00, 3.00, 0.00},
        {0, 9.00, 9.00, 0.00},
        {0, 11.00, 11.00, 2.00},
        {1, 3.00, 3.00, 0.00},
        {1, 12.00, 12.00, 0.00},
        {1, 16.00, 16.00, 4.00},
        {2, 3.00, 3.00, 0.00},
        {2, 16.00, 16.00, 0.00},
        {2, 20.00, 20.00, 4.00}
    };
	printf("Testing food expense functions...\n");
    int foodTestSize = sizeof(foodTestData) / ((sizeof(double) * (sizeof(foodTestData[0]) / sizeof(double))));
	double foodTestResults[foodTestSize];
	for(int i = 0; i < foodTestSize; i++){
		foodTestResults[i] = testFoodExpenses(i, foodTestData[i]);
	}

    // Hotel tests
	// amount, expected[0], expected[1]
    double hotelTestData[][3] = {
        {30.00, 30.00, 0.00},
        {90.00, 90.00, 0.00},
        {110.00, 110.00, 20.00}
    };
	printf("Testing hotel expense function...\n");
    int hotelTestSize = sizeof(hotelTestData) / ((sizeof(double) * (sizeof(hotelTestData[0]) / sizeof(double))));
	double hotelTestResults[hotelTestSize];
	for (int i = 0; i < hotelTestSize; i++){
		hotelTestResults[i] = testHotelExpenses(i, hotelTestData[i]);
	}

    // Registration tests
	// amount, expected
    double registrationTestData[][2] = {
        {30.00, 30.00},
        {90.00, 90.00},
        {0.00, 0.00}
    };
	printf("Testing registration expense function...\n");
    int registrationTestSize = sizeof(registrationTestData) / ((sizeof(double) * (sizeof(registrationTestData[0]) / sizeof(double))));
	double registrationTestResults[hotelTestSize];
	for (int i = 0; i < registrationTestSize; i++){
		registrationTestResults[i] = testRegistrationExpenses(i, registrationTestData[i]);
	}

    int success = 1;
    for (int i = 0; i < foodTestSize; i++) {
        if (!foodTestResults[i]) {
            success = 0;
            break;
        }
    }
    for (int i = 0; i < hotelTestSize; i++) {
        if (!hotelTestResults[i]) {
            success = 0;
            break;
        }
    }
    for (int i = 0; i < registrationTestSize; i++) {
        if (!registrationTestResults[i]) {
            success = 0;
            break;
        }
    }
	return success;
}