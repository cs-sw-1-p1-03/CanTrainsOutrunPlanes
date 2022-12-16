#include "stdio.h"

/**
 * Contains most logic of the program, including calls to other functions.
 * @param arrayOfRoutes Takes in the array of routes used throughout the program.
 * @param totalRoutes Takes in the total amount of routes available.
 * @param routes Takes in the the array of routes.
 * @param arrivalCity Takes in an arrival city.
 * @param departureCity Takes in an departure city.
 * @param distanceFromStation Takes in distance from station
 * @param typeOfTransport Need a single type char of transport
 * @param luggage Need a luggage char for "yes" or "no"
 * @param checkInTime Need a int type for check in time in minutes
 * @param boardingTime Nees a int type for boarding time in minutes.
 */

void transport(route_t arrayOfRoutes[], int totalRoutes, routeFile_t routes[],int distanceFromStation,char typeOfTransport[],char luggage[],int checkInTime,int boardingTime) {

    double busResult, averageBusSpeed = 30;
    double busCo2, busEmission = 11; //Assuming based on data that bus emission is 11 grams of CO2 per person km

    int luggageTime = 0;

    if (strcmp("Airplane", typeOfTransport) == 0) {
    if (strcmp(luggage, "yes") == 0) {
        luggageTime = 22;
    } else if (strcmp(luggage, "no") == 0) {
        luggageTime = 0;
    }
}

    busResult = (distanceFromStation * 1 / averageBusSpeed) * 60;
    busCo2 = (busEmission * distanceFromStation);


    for (int i = 0; i < totalRoutes; ++i) {
        int hours, minutes;
        if (strcmp(routes[i].typeOfTransport, typeOfTransport) == 0) {

            arrayOfRoutes[i].totalTimeBus = arrayOfRoutes[i].totalTime + busResult+luggageTime+checkInTime+boardingTime;
            arrayOfRoutes[i].totalTravelCO2 = (arrayOfRoutes[i].totalCO2 + busCo2) / 1000;
        }

        if (arrayOfRoutes[i].found == 1 && strcmp(routes[i].typeOfTransport, typeOfTransport) == 0) {
            printf("Route %d - %s ",i, routes[i].typeOfTransport);
            hours = arrayOfRoutes[i].totalTimeBus / 60;
            minutes = arrayOfRoutes[i].totalTimeBus % 60;

            printf("takes %d hours and %0.2d min including the bus time.\n", hours, minutes);
        }
    }
}
void transportCO2print(route_t arrayOfRoutes[],int totalRoutes,routeFile_t routes[]){
    for (int i = 0; i < totalRoutes; ++i) {

        if (arrayOfRoutes[i].found == 1) {
            printf("Route %d %s emits %.2lf kg. CO2.\n",i, routes[i].typeOfTransport, arrayOfRoutes[i].totalTravelCO2);

        }
    }
}

void compareCalculation(int airplane, int train, char typeOfTransportA[], char typeOfTransportB[], int cases);
void comparison(route_t arrayOfRoutes[],int totalRoutes,routeFile_t routes[],char timeORCO2[]){
    int airplaneCheck = 0;
    for (int i = 0; i < totalRoutes; i++) {
        if (arrayOfRoutes[i].found == 1 && strcmp(routes[i].typeOfTransport, "Airplane") == 0) {
            airplaneCheck = 1;
        }
    }
    if (airplaneCheck == 1) {

        printf("                                 %s comparison       \n",timeORCO2);
        printf("---------------------------------------------------------------------------------\n");
        for (int i = 0; i < totalRoutes; i++) {
            int comparedResult, indexForAirplane, hours, minutes;

            if (arrayOfRoutes[i].found == 1 && strcmp(routes[i].typeOfTransport, "Airplane") == 0) {
                indexForAirplane = i;
            }
            if (arrayOfRoutes[i].found == 1 && strcmp(routes[i].typeOfTransport, "Airplane") != 0) {

                if (strcmp(timeORCO2, "Time") == 0 ) {
                    compareCalculation(arrayOfRoutes[indexForAirplane].totalTimeBus, arrayOfRoutes[i].totalTimeBus,
                                       routes[indexForAirplane].typeOfTransport, routes[i].typeOfTransport, 1);


                } else if (strcmp(timeORCO2, "CO2") == 0 ) {

                    compareCalculation(arrayOfRoutes[indexForAirplane].totalTravelCO2, arrayOfRoutes[i].totalTravelCO2,
                                       routes[indexForAirplane].typeOfTransport, routes[i].typeOfTransport, 0);

                } else {
                    printf("something went wrong");
                    break;
                }
            }
        }
    } else{
        printf("\nNote:\n");
        printf("You can not fly to your destination");
    }
}
void compareCalculation(int airplane, int train, char typeOfTransportA[], char typeOfTransportB[], int time) {
    int comparedResult = airplane - train;
    if(train > airplane)
        comparedResult *= -1;

    int hours = comparedResult / 60;
    int minutes = comparedResult % 60;
    if (time)
        printf("The fastest method of transportation is %s which is %d hours and %d minutes faster than %s\n",
               typeOfTransportA, hours, minutes, typeOfTransportB);
    else
    if(train > airplane) {
        comparedResult *= -1;
        printf("%s emits %.2d kg. more CO2 than than %s\n", typeOfTransportB, comparedResult, typeOfTransportA);
    } else
        printf("%s emits %.2d kg. more CO2 than than %s\n", typeOfTransportA, comparedResult, typeOfTransportB);
}



void transportToNodes(route_t arrayOfRoutes[], routeFile_t routes[], char arrivalCity[], char departureCity[]) {
    char luggage[10];
    int distanceFromStation, distanceFromAirport; //Initializing distance to calculate from the different nodes

    // ------------------------ failsafe

    distanceFromStation = scanNumber("\nType your distance to the train station in km.\n");
    distanceFromAirport = scanNumber("\nType your distance to the airport in km.\n");

    arrayOfStrings_t yesNo[] = {"yes","no"};
    scanChar(luggage,yesNo,2,"Are you taking luggage(yes/no)?\n");




    printf("\n                     Total travel time from %s to %s       \n", departureCity, arrivalCity);
    printf("---------------------------------------------------------------------------------\n\n");

    transport(arrayOfRoutes, numberOfRoutes, routes, distanceFromStation, "IC", luggage, 0, 0);
    transport(arrayOfRoutes, numberOfRoutes, routes, distanceFromStation, "ICL", luggage, 0, 0);
    transport(arrayOfRoutes, numberOfRoutes, routes, distanceFromAirport, "Airplane", luggage, 90, 30);

    comparison(arrayOfRoutes, numberOfRoutes, routes, "Time");


    printf("\n                     Total CO2 from %s to %s       \n", departureCity, arrivalCity);
    printf("---------------------------------------------------------------------------------\n");

    transportCO2print(arrayOfRoutes, numberOfRoutes, routes);

    comparison(arrayOfRoutes, numberOfRoutes, routes, "CO2");
}