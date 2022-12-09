#include "stdio.h"

void transportToNodes(list_t arrayOfRoutes[],int totalRoutes,route_t routes[],char arrivalCity[], char departureCity[]) {
    char luggage[10];
    int distanceFromStation, distanceFromAirport; //Initializing distance to calculate from the different nodes
    printf("Type your distance from the train station in km.\n");
    scanf("%d", &distanceFromStation);
    printf("Type your distance to the airport in km.\n");
    scanf("%d", &distanceFromAirport);
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
            arrayOfRoutes[i].totalTimeBus = arrayOfRoutes[i].totalTime + busResult + boardingTime + luggageTime + checkInTime;
            hours = arrayOfRoutes[i].totalTimeBus / 60;
            minutes = arrayOfRoutes[i].totalTimeBus % 60;
            arrayOfRoutes[i].totalTravelCO2 = (arrayOfRoutes[i].totalCO2 + busCo2) / 1000;
        }

        /*
     * ----------------------------------- converting time --------------------------
    int hours, minutes;

    minutes = seconds / 60; // we define the variables
    hours = minutes / 60;
    days = hours / 60;

    seconds = seconds % 60; // after having calculated the amounts above, we now calculate the remainders
    minutes = minutes % 60;
    hours = hours % 24;

    printf(" timer %d\n minutter %d\n sekunder %d",  hours, minutes, seconds);
    */

        if  (arrayOfRoutes[i].found == 1 && strcmp(routes[i].typeOfTransport, "Airplane") == 0) {
            printf("%s",routes[i].typeOfTransport);
            if (walkResult <= 2) {
                printf(" takes %d hours and %.2d min. including the walk ", hours, minutes);
            }
            printf(" takes %d hours and %.2d min. including the bus time \n\n", hours, minutes);
        }
    }
    printf("                                 Time comparison       \n");
    printf("---------------------------------------------------------------------------------\n");
    for (int i = 0; i < totalRoutes; i++) {
        double comparedTimeResultBus, comparedTimeResultWalk;
        int indexForAirplane;

            if (arrayOfRoutes[i].found == 1 && strcmp(routes[i].typeOfTransport, "Airplane") == 0) {
                indexForAirplane = i;
            }
            if (arrayOfRoutes[i].found == 1 && strcmp(routes[i].typeOfTransport, "Airplane") != 0) {



            comparedTimeResultBus = arrayOfRoutes[indexForAirplane].totalTimeBus - arrayOfRoutes[i].totalTimeBus;

            comparedTimeResultWalk = arrayOfRoutes[indexForAirplane].totalTimeWalk - arrayOfRoutes[i].totalTimeWalk;


            if(arrayOfRoutes[indexForAirplane].totalTimeBus > arrayOfRoutes[i].totalTimeBus)
            {
                printf("The fastest method of transportation is %s which is %.2lf minutes faster than %s\n",
                       routes[i].typeOfTransport, comparedTimeResultBus, routes[indexForAirplane].typeOfTransport);
            }
            else if(arrayOfRoutes[indexForAirplane].totalTimeBus < arrayOfRoutes[i].totalTimeBus)
            {
                comparedTimeResultBus *= (-1);
                printf("The fastest method of transportation is %s which is %.2lf minutes faster than %s\n",
                       routes[indexForAirplane].typeOfTransport, comparedTimeResultBus, routes[i].typeOfTransport);
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
