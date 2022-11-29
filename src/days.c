int setDays() {
    int numDays = 0;
    
    printf("Enter the number of days spent on the trip:\n");
    scanf("%d", &numDays);

    printf("Trip length: %d days", numDays);

    return numDays;
}

char setStartTime() {
    char startTime[5];

    printf("Enter the time of arrival on your first day:\n");
    scanf("%s", &startTime);

    printf("Arrival time: %s", startTime);

    return startTime;
}

char setEndTime() {
    char endTime[5];

    printf("Enter the time of departure on your last day:\n");
    scanf("%s", &endTime);

    printf("Departure time: %s", endTime);

    return endTime;
}