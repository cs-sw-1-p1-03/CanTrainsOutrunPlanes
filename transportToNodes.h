#include "stdio.h"
#include "ctype.h"
#include "stdbool.h"

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


void stringCheck(char scanText[]){
    char temp[20];
    do{
        scanf("%s",temp);
    }while(strcmp(temp,scanText)!=0);
    strcpy(scanText,temp);
}

void transportToNodes(list_t arrayOfRoutes[],int totalRoutes,route_t routes[],char arrivalCity[], char departureCity[]) {
    char luggage[10];
    int distanceFromStation, distanceFromAirport; //Initializing distance to calculate from the different nodes

    // ------------------------ failsafe
    char input[5];
    do {
        printf("\nType your distance to the train station in km.\n");
        scanf("%5s", input);
    }
    while(!digitCheck(input));
    distanceFromStation = atoi(input);

    do {
        printf("\nType your distance to the airport in km.\n");
        scanf("%5s", input);
    }
    while (!digitCheck(input));
    distanceFromAirport = atoi(input);

        printf("Are you taking luggage (yes/no)?\n");
        scanf("%s", luggage);
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
        printf("                                 Time comparison       \n");
        printf("---------------------------------------------------------------------------------\n");
        for (int i = 0; i < totalRoutes; i++) {
            int comparedTimeResultBus, indexForAirplane, hours, minutes;

            if (arrayOfRoutes[i].found == 1 && strcmp(routes[i].typeOfTransport, "Airplane") == 0) {
                indexForAirplane = i;
            }
            if (arrayOfRoutes[i].found == 1 && strcmp(routes[i].typeOfTransport, "Airplane") != 0) {

                comparedTimeResultBus = arrayOfRoutes[indexForAirplane].totalTimeBus - arrayOfRoutes[i].totalTimeBus;

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

    }
