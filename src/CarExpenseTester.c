#include <stdio.h>
#include "CarExpenseCalc.h"
static int coverageTest(int testNum, double args[4], double expected){
	double calc = calculateCarExpensesCoveredWithParams(args[0],args[1],args[2],args[3]);
	printf("Test %i: Expected: %.2f | Result: %.2f | %s\n", testNum, calc, expected, calc == expected ? "PASSED." : "FAILED.");
	return calc == expected;
}
static int expenseTest(int testNum, double args[4], double expected){
	double calc = calculateCarExpensesNoPrompt(args[0],args[1],args[2],args[3]);
	printf("Test %i: Expected: %.2f | Result: %.2f | %s\n", testNum, calc, expected, calc == expected ? "PASSED." : "FAILED.");
	return calc == expected;
}
void testCarExpenses(){
	printf("---- CAR EXPENSE TESTS ----\n");
	// ---- coverage TESTS -----
	// rF, mD, nDP, nDT
	double coverageTestData[][4] = {
		{2500, 0, 11, 5},
		{0, 151, 0, 0},
		{2, 0, 0, 15},
		{0, 55, 152, 0},
		{0, 0, 0, 0}
	};
	// rf + (mD*0.27) + (nDP*6) + (nDT*10)
	double coverageExpected[] = {
		2616.0,
		40.77,
		152.0,
		926.85,
		0.0
	};
	double coverageTestResults[sizeof(coverageExpected)/sizeof(double)];
	for(int i = 0; i < sizeof(coverageExpected)/sizeof(double); i++){
		coverageTestResults[i] = coverageTest(i, coverageTestData[i], coverageExpected[i]);
	}
	
	// ---- overall expense TESTS ----

	double expenseTestData[][4] = {
		{2500, 0, 11, 5},
		{0, 151, 0, 0},
		{2, 0, 0, 15},
		{0, 55, 152, 0},
		{0, 0, 0, 0}
	};
	// rf + (mD*0.27) + (nDP*6) + (nDT*10)
	double expenseExpected[] = {
		2616.0,
		40.77,
		152.0,
		926.85,
		0.0
	};
	double expenseTestResults[sizeof(expenseExpected)/sizeof(double)];
	for(int i = 0; i < sizeof(expenseExpected)/sizeof(double); i++){
		expenseTestResults[i] = expenseTest(i, expenseTestData[i], expenseExpected[i]);
	}

	int bad = 0;
	for(int i = 0; i < sizeof(coverageExpected)/sizeof(double); i++){
		if(!coverageTestResults[i]){
			bad = 1;
		}
	}
	printf("Overall results: %s\n", bad ? "FAILED." : "PASSED.");
}
