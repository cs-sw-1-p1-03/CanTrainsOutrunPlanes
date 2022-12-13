#include "stdio.h"
#include "ctype.h"
#include "stdbool.h"

/**
 * Function to check if a string is made of numbers only.
 * @param key Takes in the string this is to be checked.
 * @return returns either the boolean true or false value, based on whether the string is a number or not.
 */
bool digitCheck(char key[])
{
    for(int i = 0; i < strlen(key); i++)
    {
        if(isdigit(key[i])==0)
        {
            return false;
        }
    }
    return true;
}

int stringCheck(char scanText[]){
    char temp[20];
    do{
        scanf("%s",temp);
    }while(strcmp(temp,scanText)!=0);
    return 1;
}


/**
 * Contains most logic of the program, including calls to other functions.
 * @param arrayOfRoutes Takes in the array of routes used throughout the program.
 * @param totalRoutes Takes in the total amount of routes available.
 * @param routes Takes in the the array of routes.
 * @param arrivalCity Takes in an arrival city.
 * @param departureCity Takes in an departure city.
 */

int scanNumber(char text[]){
    char input[5];
    do {
        printf("%s",text);
        scanf("%5s", input);
    } while (!digitCheck(input));

    int result = atoi(input);
    return result;
}
void scanChar(char input[],char* matchArray[],int arrayLength,char text[]){
    int flip = 0;
    do{
        scanf("%s",input);
        for (int i = 0; i < arrayLength;i++) {
            if (strcmp(input, matchArray[i]) == 0) {
                flip = 1;
                break;
            }
        }
        if (flip)
            break;

    }while(strcmp(input,"exit")!=0);

}

void transportToNodes(route_t arrayOfRoutes[], int totalRoutes, routeFile_t routes[], char arrivalCity[], char departureCity[]) {
    char luggage[10];
    int distanceFromStation, distanceFromAirport; //Initializing distance to calculate from the different nodes

    // ------------------------ failsafe

    distanceFromStation = scanNumber("\nType your distance to the train station in km.\n");
    distanceFromAirport = scanNumber("\nType your distance to the airport in km.\n");

    char* yesNo[2] = {"yes","no"};
    scanChar(luggage,yesNo,2,"Are you taking luggage(yes/no)?\n");



    double walkResult, averageWalkSpeed = 5, busResult, averageBusSpeed = 30;
    double busCo2, busEmission = 11; //Assuming based on data that bus emission is 11 grams of CO2 per person km

    // set definitions
    walkResult = (distanceFromStation * 1 / averageWalkSpeed) * 60;
    busResult = (distanceFromStation * 1 / averageBusSpeed) * 60;
    busCo2 = (busEmission * distanceFromStation);

    printf("\n                     Total travel time from %s to %s       \n", departureCity, arrivalCity);
    printf("---------------------------------------------------------------------------------\n\n");

    //In this we calculate the different variables
    for (int i = 0; i < totalRoutes; ++i) {
        int hours, minutes;
        if (strcmp(routes[i].typeOfTransport, "Airplane") != 0) {
            if (walkResult <= 2) {
                arrayOfRoutes[i].totalTimeWalk = arrayOfRoutes[i].totalTime + walkResult;
            }

            arrayOfRoutes[i].totalTimeBus = arrayOfRoutes[i].totalTime + busResult;
            arrayOfRoutes[i].totalTravelCO2 = (arrayOfRoutes[i].totalCO2 + busCo2) / 1000;
        }

        if (arrayOfRoutes[i].found == 1 && strcmp(routes[i].typeOfTransport, "Airplane") != 0) {
            printf("Train %s ", routes[i].typeOfTransport);
            hours = arrayOfRoutes[i].totalTimeBus / 60;
            minutes = arrayOfRoutes[i].totalTimeBus % 60;
            if (walkResult <= 2 && distanceFromStation != 0) {
                printf("takes %d hours and %0.2d min including the walk.\n", hours, minutes);
            }
            printf("takes %d hours and %0.2d min including the bus time.\n", hours, minutes);
        }
    }
    // user inputs airplane

    int luggageTime; //Average time spent in the airport to claim luggage
    int checkInTime = 90; //Average time spent in the airport to board and go through security
    int boardingTime = 30; //Average time spent to board to the airplane for domestic flights

    if (strcmp(luggage, "yes") == 0) {
        luggageTime = 22;
    } else if (strcmp(luggage, "no") == 0) {
        luggageTime = 0;
    }

    walkResult = (distanceFromAirport * 1 / averageWalkSpeed) * 60;
    busResult = (distanceFromAirport * 1 / averageBusSpeed) * 60;
    busCo2 = (busEmission * distanceFromStation);

    //In this we calculate the different variables
    for (int i = 0; i < totalRoutes; ++i) {
        int hours, minutes;


        if (strcmp(routes[i].typeOfTransport, "Airplane") == 0) {

            if (walkResult <= 2) {
                arrayOfRoutes[i].totalTimeWalk =
                        arrayOfRoutes[i].totalTime + walkResult + boardingTime + luggageTime + checkInTime;
            }
            arrayOfRoutes[i].totalTimeBus =
                    arrayOfRoutes[i].totalTime + busResult + boardingTime + luggageTime + checkInTime;
            hours = arrayOfRoutes[i].totalTimeBus / 60;
            minutes = arrayOfRoutes[i].totalTimeBus % 60;
            arrayOfRoutes[i].totalTravelCO2 = (arrayOfRoutes[i].totalCO2 + busCo2) / 1000;
        }

        if (arrayOfRoutes[i].found == 1 && strcmp(routes[i].typeOfTransport, "Airplane") == 0) {
            printf("%s", routes[i].typeOfTransport);
            if (walkResult <= 2) {
                printf(" takes %d hours and %.2d min. including the walk ", hours, minutes);
            }
            printf(" takes %d hours and %.2d min. including the bus time \n\n", hours, minutes);
        }
    }

    int airplaneCheck = 0;
    for (int i = 0; i < totalRoutes; i++) {
        if (arrayOfRoutes[i].found == 1 && strcmp(routes[i].typeOfTransport, "Airplane") == 0) {
            airplaneCheck = 1;
        }
    }
    if (airplaneCheck == 1) {

        printf("                                 Time comparison       \n");
        printf("---------------------------------------------------------------------------------\n");
        for (int i = 0; i < totalRoutes; i++) {
            int comparedTimeResultBus, indexForAirplane, hours, minutes;

            if (arrayOfRoutes[i].found == 1 && strcmp(routes[i].typeOfTransport, "Airplane") == 0) {
                indexForAirplane = i;
            }
            if (arrayOfRoutes[i].found == 1 && strcmp(routes[i].typeOfTransport, "Airplane") != 0) {

                comparedTimeResultBus =
                        arrayOfRoutes[indexForAirplane].totalTimeBus - arrayOfRoutes[i].totalTimeBus;

                hours = comparedTimeResultBus / 60;
                minutes = comparedTimeResultBus % 60;

                if (arrayOfRoutes[indexForAirplane].totalTimeBus > arrayOfRoutes[i].totalTimeBus) {
                    printf("The fastest method of transportation is %s which is %d hours and %d minutes faster than %s\n",
                           routes[i].typeOfTransport, hours, minutes, routes[indexForAirplane].typeOfTransport);
                } else if (arrayOfRoutes[indexForAirplane].totalTimeBus < arrayOfRoutes[i].totalTimeBus) {
                    hours *= (-1);
                    minutes *= (-1);
                    printf("The fastest method of transportation is %s which is %d hours and %d minutes faster than %s\n",
                           routes[indexForAirplane].typeOfTransport, hours, minutes, routes[i].typeOfTransport);
                } else {
                    printf("The routes are equal, go travel");
                }
            }
        }
    }
    printf("\n                     Total CO2 from %s to %s       \n", departureCity, arrivalCity);
    printf("---------------------------------------------------------------------------------\n");

    //In this we calculate the different variables
    for (int i = 0; i < totalRoutes; ++i) {
        if (strcmp(routes[i].typeOfTransport, "Airplane") != 0) {
            arrayOfRoutes[i].totalTravelCO2 = (arrayOfRoutes[i].totalCO2 + busCo2) / 1000;
        }

        if (arrayOfRoutes[i].found == 1) {
            printf("%s emits %.2lf kg. CO2.\n", routes[i].typeOfTransport, arrayOfRoutes[i].totalTravelCO2);

        }
    }

    if (airplaneCheck) {
        printf("\n                              CO2 comparison      \n");
        printf("---------------------------------------------------------------------------------\n");

        for (int i = 0; i < totalRoutes; i++) {
            double comparedCO2Result;
            int indexForAirplane;

            if (arrayOfRoutes[i].found == 1 && strcmp(routes[i].typeOfTransport, "Airplane") == 0) {
                indexForAirplane = i;
            }

            if (arrayOfRoutes[i].found == 1 && strcmp(routes[i].typeOfTransport, "Airplane") != 0) {

                comparedCO2Result = arrayOfRoutes[indexForAirplane].totalTravelCO2 - arrayOfRoutes[i].totalTravelCO2;


                if (arrayOfRoutes[indexForAirplane].totalTravelCO2 > arrayOfRoutes[i].totalTravelCO2) {
                    printf("%s emits %.2lf kg. less CO2 than than %s\n",
                           routes[i].typeOfTransport, comparedCO2Result, routes[indexForAirplane].typeOfTransport);
                } else if (arrayOfRoutes[indexForAirplane].totalTravelCO2 < arrayOfRoutes[i].totalTravelCO2) {
                    comparedCO2Result *= (-1);
                    printf("%s emits %.2lf kg. less CO2 than than %s\n",
                           routes[i].typeOfTransport, comparedCO2Result, routes[indexForAirplane].typeOfTransport);
                } else {
                    printf("The CO2 are equal, go travel");
                }
            }
        }
    }else{
        printf("\nNote:\n");
        printf("You can not fly to your destination");
    }
}