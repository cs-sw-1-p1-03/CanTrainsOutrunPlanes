// Standard libraries
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
//  Our own libraries
#include "interface.h"
#include "getArrayOfRoutes.h"
#include "searchRoutes.h"
#include "emissionCalculator.h"

#define ICLem 56 // (grams of Co2/passenger/kilometer) taken from "DSB årsrapport"
#define ICem 47 // (grams of Co2/passenger/kilometer) taken from "DSB årsrapport"
#define Planeem 111 // An average of (grams/Co2/passenger/kilometer) taken from "SAS årsrapport"


void searchRoutes(char arrivalCity[], char departureCity[], list_t arrayOfRoutes[], int totalRoutes);

int main() {
    //Interface function
    char departureCity[20]; // Assigning amount of characters, it does not scan properly otherwise
    char arrivalCity[20];   //                           --||--
    interface(departureCity,
              arrivalCity); // We have added the interface function to a h file, and then we can call interface
    // the same way we would call a strcmp or strlen

    int totalRoutes = 5;
    //array for routes
    list_t arrayOfRoutes[totalRoutes];//Initializing a static array with the size of totalRoutes
    //The list is defined as an array of arrays(routeIntervals_t)
    //This list is empty

    createArrayOfRoutes(arrayOfRoutes, totalRoutes); //Fulfilling the list with the void function

    searchRoutes(arrivalCity, departureCity, arrayOfRoutes, totalRoutes); //Reading the list

    route_t routes[totalRoutes]; //Creating an empty array of routes
    routesFilesOpen(routes); //Filling it up

    co2Multiplier(routes, arrayOfRoutes, totalRoutes);

    char transport[10];
    int distanceFromStation, distanceFromAirport;
    printf("Are you taking the airplane or train");
    scanf("%s",transport);
    printf("Type your distance from train station and airport");
    scanf("%d %d", &distanceFromStation,&distanceFromAirport);

   //calculate();
    double walkResult, averageWalkSpeed = 5, busResult, averageBusSpeed = 50;
    double walkCO2 = 0, busCo2;
    double totalTimeBus, totalTimeWalk;
    char typeOfTransport[100];

    if (strcmp(transport,"train") == 0)
    {
        printf("This is how long it will take you to get to the train station:\n");
        printf("Walking ->");
        walkResult = (distanceFromStation * 1 / averageWalkSpeed)*60;
        printf("%lf min.\n", walkResult);
        printf("Bus ->");
        busResult = (distanceFromStation * 1 / averageBusSpeed)*60;
        busCo2 = busCo2 * distanceFromStation;
        printf("%lf min.\n",busResult);

        for (int i = 1; i < totalRoutes; ++i) {
            totalTimeWalk = arrayOfRoutes[i].totalTime + walkResult;
            totalTimeBus = arrayOfRoutes[i].totalTime + busResult;
            strcpy(typeOfTransport, routes[i].typeOfTransport);
            if (arrayOfRoutes[i].found == 1) {
            printf("Train type %s to %s. Total: %lf minutes by walking\n"
                   "                             Total: %lf minutes by bus\n", typeOfTransport, arrivalCity,
                   totalTimeWalk, totalTimeBus);
             }
        }

    } else if  (strcmp(transport,"airplane") == 0)
    {
        printf("This is how long it will take you to get to the Airport:");
        printf("Walking ->");
        walkResult = distanceFromAirport * 1 / averageWalkSpeed;
        printf("%d \n", walkResult);
        printf("Bus ->");
        busResult = distanceFromAirport * 1 / averageBusSpeed;
        busCo2 = busCo2 * distanceFromAirport;
        printf("%d \n",busResult);
    }
}