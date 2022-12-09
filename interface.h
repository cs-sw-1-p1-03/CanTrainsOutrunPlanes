#include <stdio.h>

// Function type is void since using a char does not allow for multiple returns
void interface1() {

    printf("                            Hello User\n"
           "---------------------------------------------------------------------------------\n"
           "         Choose your departure destination and your arrival destination\n"
    );
}

void interface2(char departureCity[], char arrivalCity[]){
    printf("Once you have selected your destination the program will return the following: \n"
    "Travel time, CO2 Emission and a comparison between airplanes and trains.\n"
    "---------------------------------------------------------------------------------\n\n"
    "Please insert your desired departure and arrival destinations.\n");

    scanf("%s %s", departureCity, arrivalCity);

}
