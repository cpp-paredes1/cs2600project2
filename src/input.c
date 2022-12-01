#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "input.h"

void clearBuffer() {
    int c;
    while ((c = fgetc(stdin)) != EOF && c != '\n'); // Clears buffer to prevent printf output from looping into scanf
}

int integerInput(char *text) {
    int input = 0;
    int valid = 0;

    do { // Loop until a valid input is entered
        printf(text);
        valid = scanf("%d", &input); // Read option from user
        if (!valid) { 
            printf("Invalid number.\n"); // User entered an invalid number
        }
        clearBuffer();
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
        }
        clearBuffer();
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
        }
    } while (input < min || input > max);

    return input;
}

int *timeInput(char *text) {
    int hour = 0;
    int minute = 0;
    char period[2];
    int valid = 0;
    char input[16];
    
    do { // Loop until a valid time is entered
        printf(text);
        fgets(input, 16, stdin); // Read time from user
        valid = sscanf(input, "%d:%d %c%c", &hour, &minute, &period[0], &period[1]) == 4; // Parse and validate time
        if (!valid) {
            printf("Invalid time format (format: HH:MM AM/PM).\n"); // User entered an invalid time
            continue;
        }

        valid = hour >= 1 && hour <= 12 && minute >= 0 && minute <= 59;
        if (hour < 1 || hour > 12) {
            printf("Hour must be between 1 and 12.\n");
        }
        if (minute < 0 || minute > 59) {
            printf("Minute must be between 0 and 59.\n");
        }
        if ((period[0] != 65 && period[0] != 80) || period[1] != 77) { // strcmp doesn't work for some reason :(
            printf("Period must be AM or PM.\n");
            valid = 0;
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
    if (period[0] == 80) { // PM
        hour += 12; 
    }

    ret[0] = hour;
    ret[1] = minute;
    return ret;
}
