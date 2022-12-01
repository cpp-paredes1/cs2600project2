#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "FoodHotelRegistrationCalc.h"
//Conference or seminar registration fees 
double calRegCost() {
	double regFees = 0;
	int run = 1;
	while (run == 1) {
		printf("\nEnter the total amount of registration fee:");
		scanf("%lf", &regFees);
		if (regFees <= 0) {
			printf("\nPlease enter a valid amount");
		}
		else {
			return regFees;
		}
	}
}

double *hotelCost() {
	static double costs[2];
	double cost, totalCost;
	int run = 1;
	while (run == 1) {
		printf("\nEnter hotel cost for one night:");
		scanf("%lf", &cost);
	if (cost <= 0)
        {
            printf("\nPlease enter a valid number (>0)!");
        }
        else
        {
            if (cost <= 90)
            {
                costs[0] = cost;
                costs[1] = 0;
            }
            else
            {
                costs[0] = cost;
                totalCost = cost - 90;
                costs[1] = totalCost;
            }
            return costs;
        }
	}
}

//calculate breakfast
double *calBreakfast(double amount)
{
    static double costs[2];
    costs[0] = amount;
    if (amount <= 9)
    {
        costs[1] = 0;
    }
    else
    {
        amount = amount - 9;
        costs[1] = amount;
    }
    return costs;
}
//calculate lunch
double *calLunch(double amount)
{
    static double costs[2];
    costs[0] = amount;
    if (amount <= 12)
    {
        costs[1] = 0;
    }
    else
    {
        amount = amount - 12;
        costs[1] = amount;
    }
    return costs;
}

//calculate dinner
double *calDinner(double amount)
{
    static double costs[2];
    costs[0] = amount;
    if (amount <= 16)
    {
        costs[1] = 0;
    }
    else
    {
        amount = amount - 16;
        costs[1] = amount;
    }
    return costs;
}

//calculate meals
double *calMealCost(int numOfDays, double time[2])
{
    double breakfast, lunch, dinner;
    static double *breakfastCosts, *lunchCosts, *dinnerCosts, *totalCosts;
    int ans;
    int run = 1;
    printf("\nIs this is a first day,last day or middle day of trip?(1:first/3:last/2:middle):");
    scanf("%d", ans);
    switch (ans)
    {
    case 1:
        if (numOfDays == 1)
        {
            if (time[0] <= 7)
            {
                if (time[1] > 13 && time[1] < 19)
                {
                    run = 1;
                    while (run == 1)
                    {
                        printf("\nEnter amount for breakfast:");
                        scanf("%lf", &breakfast);
                        printf("\nEnter amount for lunch:");
                        scanf("%lf", &lunch);
                        printf("\nEnter amount for Dinner:");
                        scanf("%lf", &dinner);
                        if (breakfast < 0 || lunch < 0 || dinner < 0)
                        {
                            printf("Invalid cost input!Try Again.");
                            continue;
                        }
                        else
                        {
                            dinnerCosts = calDinner(dinner);
                            lunchCosts = calLunch(lunch);
                            breakfastCosts = calBreakfast(breakfast);
                            totalCosts[0] = breakfastCosts[0] + lunchCosts[0] + dinnerCosts[0];
                            totalCosts[1] = breakfastCosts[1] + lunchCosts[1] + dinnerCosts[1];
                            run = 0;
                        }
                    }
                }
                if (time[1] > 19)
                {
                    run = 1;
                    while (run == 1)
                    {
                        printf("\nEnter amount for breakfast:");
                        scanf("%lf", &breakfast);
                        printf("\nEnter amount for lunch:");
                        scanf("%lf", &lunch);
                        if (breakfast < 0 || lunch < 0)
                        {
                            printf("\nInvalid cost input!Try Again.");
                            continue;
                        }
                        else
                        {
                            breakfastCosts = calBreakfast(breakfast);
                            lunchCosts = calLunch(lunch);
                            totalCosts[0] = breakfastCosts[0] + lunchCosts[0];
                            totalCosts[1] = breakfastCosts[1] + lunchCosts[1];
                            run = 0;
                        }
                    }
                }
            }
            if (time[0] > 7 && time[0] < 12)
            {
                if (time[1] > 13 && time[1] < 19)
                {
                    run = 1;
                    while (run == 1)
                    {
                        printf("\nEnter amount for lunch:");
                        scanf("%lf", &lunch);
                        if (lunch < 0)
                        {
                            printf("\nInvalid cost input!Try Again.");
                            continue;
                        }
                        else
                        {
                            lunchCosts = calLunch(lunch);
                            totalCosts[0] = lunchCosts[0];
                            totalCosts[1] = lunchCosts[1];
                            run = 0;
                        }
                    }
                }
                else
                {
                    run = 1;
                    while (run == 1)
                    {
                        printf("\nEnter amount for lunch:");
                        scanf("%lf", &lunch);
                        printf("\nEnter amount for Dinner:");
                        scanf("%lf", &dinner);
                        if (lunch < 0 || dinner < 0)
                        {
                            printf("\nInvalid cost input!Try Again.");
                            continue;
                        }
                        else
                        {
                            dinnerCosts = calDinner(dinner);
                            lunchCosts = calLunch(lunch);
                            totalCosts[0] = dinnerCosts[0] + lunchCosts[0];
                            totalCosts[1] = dinnerCosts[1] + lunchCosts[1];
                            run = 0;
                        }
                    }
                }
            }
            if (time[0] > 12 && time[0] < 18)
            {
                run = 1;
                while (run == 1)
                {
                    printf("\nEnter amount for Dinner:");
                    scanf("%lf", &dinner);
                    if (dinner < 0)
                    {
                        printf("\nInvalid cost input!Try Again.");
                        continue;
                    }
                    else
                    {
                        dinnerCosts = calDinner(dinner);
                        totalCosts[0] = dinnerCosts[0];
                        totalCosts[1] = dinnerCosts[1];
                        run = 0;
                    }
                }
            }
        }
        else
        {
            if (time[0] <= 7)
            {
                run = 1;
                while (run == 1)
                {
                    printf("\nEnter amount for breakfast:");
                    scanf("%lf", &breakfast);
                    printf("\nEnter amount for lunch:");
                    scanf("%lf", &lunch);
                    printf("\nEnter amount for Dinner:");
                    scanf("%lf", &dinner);
                    if (breakfast < 0 || lunch < 0 || dinner < 0)
                    {
                        printf("\nInvalid cost input!Try Again.");
                        continue;
                    }
                    else
                    {
                        dinnerCosts = calDinner(dinner);
                        lunchCosts = calLunch(lunch);
                        breakfastCosts = calBreakfast(breakfast);
                        totalCosts[0] = breakfastCosts[0] + lunchCosts[0] + dinnerCosts[0];
                        totalCosts[1] = breakfastCosts[1] + lunchCosts[1] + dinnerCosts[1];
                        run = 0;
                    }
                }
            }
            if (time[0] > 7 && time[0] <= 12)
            {
                run = 1;
                while (run == 1)
                {
                    printf("\nEnter amount for lunch:");
                    scanf("%lf", &lunch);
                    printf("\nEnter amount for Dinner:");
                    scanf("%lf", &dinner);
                    if (lunch < 0 || dinner < 0)
                    {
                        printf("\nInvalid cost input!Try Again.");
                        continue;
                    }
                    else
                    {
                        dinnerCosts = calDinner(dinner);
                        lunchCosts = calLunch(lunch);
                        totalCosts[0] = dinnerCosts[0] + lunchCosts[0];
                        totalCosts[1] = dinnerCosts[1] + lunchCosts[1];
                        run = 0;
                    }
                }
            }
            if (time[0] > 12 && time[0] <= 18)
            {
                run = 1;
                while (run == 1)
                {
                    printf("\nEnter amount for Dinner:");
                    scanf("%lf", &dinner);
                    if (dinner < 0)
                    {
                        printf("\nInvalid cost input!Try Again.");
                        continue;
                    }
                    else
                    {
                        dinnerCosts = calDinner(dinner);
                        totalCosts[0] = dinnerCosts[0];
                        totalCosts[1] = dinnerCosts[1];
                        run = 0;
                    }
                }
            }
        }
        break;
    case 2:
        run = 1;
        while (run == 1)
        {
            printf("\nEnter amount for breakfast:");
            scanf("%lf", &breakfast);
            printf("\nEnter amount for lunch:");
            scanf("%lf", &lunch);
            printf("\nEnter amount for Dinner:");
            scanf("%lf", &dinner);
            if (breakfast < 0 || lunch < 0 || dinner < 0)
            {
                printf("\nInvalid cost input!Try Again.");
                continue;
            }
            else
            {
                dinnerCosts = calDinner(dinner);
                lunchCosts = calLunch(lunch);
                breakfastCosts = calBreakfast(breakfast);
                totalCosts[0] = breakfastCosts[0] + lunchCosts[0] + dinnerCosts[0];
                totalCosts[1] = breakfastCosts[1] + lunchCosts[1] + dinnerCosts[1];
                run = 0;
            }
        }
        break;
    case 3:
        if (numOfDays > 1)
        {
            if (time[1] > 8 && time[1] <= 13)
            {
                run = 1;
                while (run == 1)
                {
                    printf("\nEnter amount for breakfast:");
                    scanf("%lf", &breakfast);
                    if (breakfast < 0)
                    {
                        printf("\nInvalid cost input!Try Again.");
                        continue;
                    }
                    else
                    {
                        breakfastCosts = calBreakfast(breakfast);
                        totalCosts[0] = breakfastCosts[0];
                        totalCosts[1] = breakfastCosts[1];
                        run = 0;
                    }
                }
            }
            if (time[1] > 13 && time[1] <= 19)
            {
                run = 1;
                while (run == 1)
                {
                    printf("\nEnter amount for breakfast:");
                    scanf("%lf", &breakfast);
                    printf("\nEnter amount for lunch:");
                    scanf("%lf", &lunch);
                    if (breakfast < 0 || lunch < 0)
                    {
                        printf("\nInvalid cost input!Try Again.");
                        continue;
                    }
                    else
                    {
                        lunchCosts = calLunch(lunch);
                        breakfastCosts = calBreakfast(breakfast);
                        totalCosts[0] = breakfastCosts[0] + lunchCosts[0];
                        totalCosts[1] = breakfastCosts[1] + lunchCosts[1];
                        run = 0;
                    }
                }
            }
            if (time[1] > 19)
            {
                run = 1;
                while (run == 1)
                {
                    printf("\nEnter amount for breakfast:");
                    scanf("%lf", &breakfast);
                    printf("\nEnter amount for lunch:");
                    scanf("%lf", &lunch);
                    printf("\nEnter amount for Dinner:");
                    scanf("%lf", &dinner);
                    if (breakfast < 0 || lunch < 0 || dinner < 0)
                    {
                        printf("\nInvalid cost input!Try Again.");
                        continue;
                    }
                    else
                    {
                        dinnerCosts = calDinner(dinner);
                        lunchCosts = calLunch(lunch);
                        breakfastCosts = calBreakfast(breakfast);
                        totalCosts[0] = breakfastCosts[0] + lunchCosts[0] + dinnerCosts[0];
                        totalCosts[1] = breakfastCosts[1] + lunchCosts[1] + dinnerCosts[1];
                        run = 0;
                    }
                }
            }
        }
        break;
    default:
        printf("\nInvalid choice!Try again!");
        break;
    }
    return totalCosts;
}
