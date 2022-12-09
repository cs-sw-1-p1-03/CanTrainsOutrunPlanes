#include <stdio.h>

// Function type is void since using a char does not allow for multiple returns
void interFace1() {

    printf("                            Hello User\n"
           "---------------------------------------------------------------------------------\n"
           "         Choose your departure destination and your arrival destination\n"
    );
}

void interFace2()
{
    printf("\nOnce you have selected your destination the program will return the following: \n"
           "Travel time, CO2 Emission and a comparison between airplanes and trains.\n"
           "---------------------------------------------------------------------------------\n\n");
}

/**
 * Function that scans the departure city
 * @param departureCity this is where we save the variable
 */
void scanDepartureCity(char departureCity[])
{
    printf("Please enter your desired departure destination.\n");
    scanf("%s", departureCity);

}
