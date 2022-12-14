#include <stdio.h>
#include "CarExpenseCalc.h"
#include "test.h"

int coverageTest(int testNum, double args[4], double expected){
	double calc = calculateCarExpensesCoveredWithParams(args[0],args[1],args[2],args[3]);
	printf("\tTest %i: Expected: %.2f | Result: %.2f", testNum+1, calc, expected);
	return printTest("", calc == expected);
}

int expenseTest(int testNum, double args[4], double expected){
	double calc = calculateCarExpensesNoPrompt(args[0], args[1], args[2], args[3]);
	printf("\tTest %i: Expected: %.2f | Result: %.2f", testNum+1, calc, expected);
	return printTest("", calc == expected);
}

int testCarExpenses() {
	printf("CAR EXPENSE TESTS\n");
	printf("---------------\n");
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
	printf("Testing company coverage function...\n");
	double coverageTestResults[sizeof(coverageExpected)/sizeof(double)];
	for(int i = 0; i < sizeof(coverageExpected)/sizeof(double); i++){
		coverageTestResults[i] = coverageTest(i, coverageTestData[i], coverageExpected[i]);
	}
	
	// ---- overall expense TESTS ----
	// rF, mD, pF, tF
	double expenseTestData[][4] = {
		{2500, 0, 150, 5},
		{0, 151, 0, 212},
		{2, 0, 0, 15},
		{0, 55, 152, 0},
		{0, 0, 0, 0}
	};
	// rf + (mD*0.27) + pF + tF
	double expenseExpected[] = {
		2655.0,
		252.77,
		17.0,
		166.85,
		0.0
	};
	printf("Testing expenses incurred function...\n");
	double expenseTestResults[sizeof(expenseExpected)/sizeof(double)];
	for(int i = 0; i < sizeof(expenseExpected)/sizeof(double); i++){
		expenseTestResults[i] = expenseTest(i, expenseTestData[i], expenseExpected[i]);
	}
	int bad = 0;
	for(int i = 0; i < sizeof(coverageExpected)/sizeof(double); i++){
		if(!coverageTestResults[i] || !expenseTestResults[i]){
			bad = 1;
		}
	}
	return !bad;
}
