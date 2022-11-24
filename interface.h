#include <stdio.h>

// Functiontype is void since using a char does not allow for multiple returns
void interface(char departureCity[], char arrivalCity[])
{
    printf("Hello User\n"
           "Choose your departure destination and your arrival destination\n"
           "You can choose between: \n"
           "CPHAirport - Aalborg ... WRITE IN SPECIFICS \n"
           "Once you have selected your destinations the program will return the following: \n"
           "Travel time, Distance, CO2 Emission, (Price?), Comparison between planes and trains.\n");

    scanf("%s %s", departureCity, arrivalCity);
}
