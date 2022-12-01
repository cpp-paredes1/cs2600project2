#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "input.h"
#include "PlaneExpenseCalc.h"

double calculatePlaneExpenses(){
	return doubleInputPositive("How much will you spend total on airfare?: ", 1);
}