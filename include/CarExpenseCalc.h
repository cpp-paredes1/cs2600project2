double calculateCarExpenses(int numDays);
double calculateCarExpensesNoPrompt(double rentalFees, int miles, double parkingFees, double taxiFees);
double calculateParkingFees(int numDays);
double calculateTaxiFees(int numDays);
// REQURIES calculateCarExpenses() TO BE CALLED
double calculateCarExpensesCovered();
// DOES NOT REQUIRE calculateCarExpenses() TO BE CALLED
double calculateCarExpensesCoveredWithParams(double rF, double mD, int nDP, int nDT);