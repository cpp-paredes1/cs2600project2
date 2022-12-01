#include <stdio.h>

extern void testCarExpenses();

int printTest(char* text, int result) {
    printf("%s: %s\n", text, result ? "PASS" : "FAIL");
    return result;
}

// Call this function from main if first argument is "test"
int test() {
    printf("Performing unit tests...\n");
    testCarExpenses();
    printf("---------------\n");
    int trueTest = printTest("This should pass", 1 == 1);
    int falseTest = printTest("This should fail", 1 == 2);

    int result = trueTest && falseTest;
    return printTest("\nOverall test", result);
}