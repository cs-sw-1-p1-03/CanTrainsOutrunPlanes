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
 * @param arrayOfRoutes Takes in the array of routeFileArray used throughout the program.
 * @param totalRoutes Takes in the total amount of routeFileArray available.
 * @param routeFileArray Takes in the the array of routeFileArray.
 * @param arrivalCity Takes in an arrival city.
 * @param departureCity Takes in an departure city.
 */
void transportToNodes(route_t arrayOfRoutes[], routeFile_t routeFileArray[], char arrivalCity[], char departureCity[]) {
    char luggage[10];
    int distanceFromStation, distanceFromAirport; //Initializing distance to calculate from the different nodes

    // ------------------------ failsafe
    char input[5];
    do {
        printf("\nType your distance to the train station in km.\n");
        scanf("%5s", input);
    } while (!digitCheck(input));

    distanceFromStation = atoi(input);

    //Failsafe
    do {
        printf("\nType your distance to the airport in km.\n");
        scanf("%5s", input);
    } while (!digitCheck(input));

    distanceFromAirport = atoi(input);

    while (1) {
        printf("Are you taking luggage (yes/no)?\n");
        scanf("%s", luggage);
        if (strcmp(luggage, "no") == 0 || strcmp(luggage, "yes") == 0) {
            break;
        }
    }


    double walkResult, averageWalkSpeed = 5, busResult, averageBusSpeed = 30;
    double busCo2, busEmission = 11; //Assuming based on data that bus emission is 11 grams of CO2 per person km

    // set definitions
    walkResult = (distanceFromStation * 1 / averageWalkSpeed) * 60;
    busResult = (distanceFromStation * 1 / averageBusSpeed) * 60;
    busCo2 = (busEmission * distanceFromStation);

    printf("\n                     Total travel time from %s to %s       \n", departureCity, arrivalCity);
    printf("---------------------------------------------------------------------------------\n\n");

    //In this we calculate the different variables
    for (int i = 0; i < numberOfRoutes; ++i) {
        int hours, minutes;
        if (strcmp(routeFileArray[i].typeOfTransport, "Airplane") != 0) {
            if (walkResult <= 2) {
                arrayOfRoutes[i].totalTimeWalk = arrayOfRoutes[i].totalTime + walkResult;
            }

            arrayOfRoutes[i].totalTimeBus = arrayOfRoutes[i].totalTime + busResult;
            arrayOfRoutes[i].totalTravelCO2 = (arrayOfRoutes[i].totalCO2 + busCo2) / 1000;
        }

        if (arrayOfRoutes[i].found == 1 && strcmp(routeFileArray[i].typeOfTransport, "Airplane") != 0) {
            printf("Train %s ", routeFileArray[i].typeOfTransport);
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
    for (int i = 0; i < numberOfRoutes; ++i) {
        int hours, minutes;


        if (strcmp(routeFileArray[i].typeOfTransport, "Airplane") == 0) {

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

        if (arrayOfRoutes[i].found == 1 && strcmp(routeFileArray[i].typeOfTransport, "Airplane") == 0) {
            printf("%s", routeFileArray[i].typeOfTransport);
            if (walkResult <= 2) {
                printf(" takes %d hours and %.2d min. including the walk ", hours, minutes);
            }
            printf(" takes %d hours and %.2d min. including the bus time \n\n", hours, minutes);
        }
    }

    int airplaneCheck = 0;
    for (int i = 0; i < numberOfRoutes; i++) {
        if (arrayOfRoutes[i].found == 1 && strcmp(routeFileArray[i].typeOfTransport, "Airplane") == 0) {
            airplaneCheck = 1;
        }
    }
    if (airplaneCheck == 1) {

        printf("                                 Time comparison       \n");
        printf("---------------------------------------------------------------------------------\n");
        for (int i = 0; i < numberOfRoutes; i++) {
            int comparedTimeResultBus, indexForAirplane, hours, minutes;

            if (arrayOfRoutes[i].found == 1 && strcmp(routeFileArray[i].typeOfTransport, "Airplane") == 0) {
                indexForAirplane = i;
            }
            if (arrayOfRoutes[i].found == 1 && strcmp(routeFileArray[i].typeOfTransport, "Airplane") != 0) {

                comparedTimeResultBus =
                        arrayOfRoutes[indexForAirplane].totalTimeBus - arrayOfRoutes[i].totalTimeBus;

                hours = comparedTimeResultBus / 60;
                minutes = comparedTimeResultBus % 60;

                if (arrayOfRoutes[indexForAirplane].totalTimeBus > arrayOfRoutes[i].totalTimeBus) {
                    printf("The fastest method of transportation is %s which is %d hours and %d minutes faster than %s\n",
                           routeFileArray[i].typeOfTransport, hours, minutes, routeFileArray[indexForAirplane].typeOfTransport);
                } else if (arrayOfRoutes[indexForAirplane].totalTimeBus < arrayOfRoutes[i].totalTimeBus) {
                    hours *= (-1);
                    minutes *= (-1);
                    printf("The fastest method of transportation is %s which is %d hours and %d minutes faster than %s\n",
                           routeFileArray[indexForAirplane].typeOfTransport, hours, minutes, routeFileArray[i].typeOfTransport);
                } else {
                    printf("The routeFileArray are equal, go travel");
                }
            }
        }
    }
    printf("\n                     Total CO2 from %s to %s       \n", departureCity, arrivalCity);
    printf("---------------------------------------------------------------------------------\n");

    //In this we calculate the different variables
    for (int i = 0; i < numberOfRoutes; ++i) {
        if (strcmp(routeFileArray[i].typeOfTransport, "Airplane") != 0) {
            arrayOfRoutes[i].totalTravelCO2 = (arrayOfRoutes[i].totalCO2 + busCo2) / 1000;
        }

        if (arrayOfRoutes[i].found == 1) {
            printf("%s emits %.2lf kg. CO2.\n", routeFileArray[i].typeOfTransport, arrayOfRoutes[i].totalTravelCO2);

        }
    }

    if (airplaneCheck) {
        printf("\n                              CO2 comparison      \n");
        printf("---------------------------------------------------------------------------------\n");

        for (int i = 0; i < numberOfRoutes; i++) {
            double comparedCO2Result;
            int indexForAirplane;

            if (arrayOfRoutes[i].found == 1 && strcmp(routeFileArray[i].typeOfTransport, "Airplane") == 0) {
                indexForAirplane = i;
            }

            if (arrayOfRoutes[i].found == 1 && strcmp(routeFileArray[i].typeOfTransport, "Airplane") != 0) {

                comparedCO2Result = arrayOfRoutes[indexForAirplane].totalTravelCO2 - arrayOfRoutes[i].totalTravelCO2;


                if (arrayOfRoutes[indexForAirplane].totalTravelCO2 > arrayOfRoutes[i].totalTravelCO2) {
                    printf("%s emits %.2lf kg. less CO2 than than %s\n",
                           routeFileArray[i].typeOfTransport, comparedCO2Result, routeFileArray[indexForAirplane].typeOfTransport);
                } else if (arrayOfRoutes[indexForAirplane].totalTravelCO2 < arrayOfRoutes[i].totalTravelCO2) {
                    comparedCO2Result *= (-1);
                    printf("%s emits %.2lf kg. less CO2 than than %s\n",
                           routeFileArray[i].typeOfTransport, comparedCO2Result, routeFileArray[indexForAirplane].typeOfTransport);
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