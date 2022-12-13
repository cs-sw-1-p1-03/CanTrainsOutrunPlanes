#include <stdio.h>

/**
 * Simple function to print a welcome message to the user
 */
void interFace1() {

    printf("                            Hello User\n"
           "---------------------------------------------------------------------------------\n"
           "In this program you enter your departure destination and your arrival destination.\n"
    );
}
/**
 * Simple function to print the info about the functionality of the program.
 */
void interFace2()
{
    printf("\nOnce you have selected your destination the program will return the following: \n"
           "Travel time, CO2 Emission and a comparison between airplanes and trains.\n"
           "---------------------------------------------------------------------------------\n\n");
}

/**
 * Function that scans the desired city
 * @param departureCity this is where we save the variable
 */
void scanDesiredCity(char desiredCity[])
{
    printf("Please enter your desired destination.\n");
    scanf("%s", desiredCity);

}
