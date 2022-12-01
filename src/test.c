#include <stdio.h>
#include "test.h"

int printTest(char* text, int result) {
    printf("%s | %s\n", text, result ? "PASSED" : "FAILED");
    return result;
}

int printOverallTest(char* text, int result) {
    printf("---------------\n");
    printf("%s: %s\n\n", text, result ? "PASSED" : "FAILED");
    return result;
}

int testBase() {
    printf("BASE TEST\n");
    printf("---------------\n");
    int trueTest = printTest("This should equal true", 1 == 1);
    int falseTest = printTest("This should equal false", !(1 == 2));

    return trueTest && falseTest;
}

// Call this function from main if first argument is "test"
int test() {
    printf("Performing unit tests...\n\n");
    int baseTest = printOverallTest("BASE TEST", testBase());
    int carExpensesTest = printOverallTest("CAR EXPENSE TESTS", testCarExpenses());

    int result = baseTest && carExpensesTest;
    return printOverallTest("OVERALL TEST", result);
}