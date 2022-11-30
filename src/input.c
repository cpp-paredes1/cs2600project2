#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "input.h"

void clearBuffer() {
    while (getchar() != '\n'); // Clears buffer to prevent printf output from looping into scanf
}

int integerInput(char *text) {
    int input = 0;
    int valid = 0;

    do { // Loop until a valid input is entered
        printf(text);
        valid = scanf("%d", &input); // Read option from user
        if (!valid) { 
            printf("Invalid number.\n"); // User entered an invalid number
            clearBuffer();
        }
    } while (!valid);

    return input;
}

int integerInputPositive(char *text, int allowZero) {
    int input = 0;

    do { // Loop until a positive number is entered
        input = integerInput(text); // Read option from user
        if (input < (allowZero ? 0 : 1)) {
            // User's input was not positive
            printf(allowZero ? "Invalid number (must be positive).\n" : "Invalid number (must be positive, nonzero).\n");
            clearBuffer();
        }
    } while (input < (allowZero ? 0 : 1));

    return input;
}

int integerInputRange(char *text, int min, int max) {
    int input = 0;

    do { // Loop until a number between min and max is entered
        input = integerInput(text); // Read option from user
        if (input < min || input > max) {
            // User's input was not in range
            printf("Invalid number (must be between %d and %d).\n", min, max);
            clearBuffer();
        }
    } while (input < min || input > max);

    return input;
}

double doubleInput(char *text) {
    double input = 0;
    int valid = 0;

    do { // Loop until a valid input is entered
        printf(text);
        valid = scanf("%lf", &input); // Read option from user
        if (!valid) { 
            printf("Invalid number.\n"); // User entered an invalid double
            clearBuffer();
        }
    } while (!valid);

    return input;
}

double doubleInputPositive(char *text, int allowZero) {
    double input = 0;

    do { // Loop until a positive number is entered
        input = doubleInput(text); // Read option from user
        if (input < (allowZero ? 0 : 1)) {
            // User's input was not positive
            printf(allowZero ? "Invalid number (must be positive).\n" : "Invalid number (must be positive, nonzero).\n");
            clearBuffer();
        }
    } while (input < (allowZero ? 0 : 1));

    return input;
}

double doubleInputRange(char *text, double min, double max) {
    double input = 0;

    do { // Loop until a number between min and max is entered
        input = doubleInput(text); // Read option from user
        if (input < min || input > max) {
            // User's input was not in range
            printf("Invalid number (must be between %.2f and %.2f).\n", min, max);
            clearBuffer();
        }
    } while (input < min || input > max);

    return input;
}

int *timeInput(char *text) {
    int hour = 0;
    int minute = 0;
    char period[2];
    int valid = 0;

    do { // Loop until a valid time is entered
        puts(text);
        valid = scanf("%d:%d %2s", &hour, &minute, period) == 3; // Read option from user
        if (!valid) { 
            printf("Invalid time format (format: HH:MM AM/PM).\n"); // User entered an invalid double
            clearBuffer();
            continue;
        }

        valid = hour >= 1 && hour <= 12 && minute >= 0 && minute <= 60;
        if (hour < 1 || hour > 12) {
            printf("Hour is not between 1 and 12.\n");
            clearBuffer();
            continue;
        }
        if (minute < 0 || minute > 59) {
            printf("Minute is not between 0 and 59.\n");
            clearBuffer();
            continue;
        }
        if (strcmp(period, "AM") != 0 && strcmp(period, "PM") != 0) {
            printf("Period is not AM or PM.\n");
            valid = 0;
            clearBuffer();
            continue;
        }
    } while (!valid);

    // Create return array
    int *ret = malloc(sizeof(int) * 2);
    if (!ret) {
        return NULL;
    }

    // Convert to 24-hour time
    if (hour == 12) {
        hour = 0;
    }
    if (strcmp(period, "PM") == 0) {
        hour += 12; 
    }

    ret[0] = hour;
    ret[1] = minute;
    return ret;
}
