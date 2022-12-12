// Standard libraries
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
//  Our own libraries
#include "interface.h"
#include "getArrayOfRoutes.h"
#include "searchRoutes.h"
#include "emissionCalculator.h"
#include "transportToNodes.h"
#include "advancedDetails.h"
#include "destinationChoices.h"
#include "failSafe.h"

//void searchRoutes(char arrivalCity[], char departureCity[], list_t arrayOfRoutes[], int totalRoutes);

int main() {
    //Interface function
    char departureCity[20]; // Assigning amount of characters, it does not scan properly otherwise
    char arrivalCity[20];   //                           --||--
    int totalRoutes = 9;

    //array for routes
    list_t arrayOfRoutes[totalRoutes];//Initializing a static array with the size of totalRoutes
    //The list is defined as an array of arrays(routeIntervals_t)
    //This list is empty

    route_t routes[totalRoutes]; //Creating an empty array of routes
    defineFiles2(routes,totalRoutes); //Filling it up

    openFiles(routes,totalRoutes);
    createArrayOfRoutes(arrayOfRoutes, totalRoutes,routes); //Fulfilling the list with the void function
    closeRoutes(routes,totalRoutes);


    interFace1();//Printing the first interfae that the user will recieve


    arrayOfStrings_t cityChoices[50];
    destinationChoices(routes, arrayOfRoutes, totalRoutes,  cityChoices);
    printChoices(cityChoices);


    interFace2();//Printing the second interface that the user will receive about the details they will get


    failsafeCityChoice(departureCity, cityChoices);

    arrayOfStrings_t arrivalChoice[50];
    arrivalChoices(routes,arrayOfRoutes,totalRoutes, departureCity, cityChoices, arrivalChoice);
    printChoices( arrivalChoice);

    failsafeCityChoice(arrivalCity,arrivalChoice);


    searchRoutes(arrivalCity, departureCity, arrayOfRoutes, routes, totalRoutes); //Reading the list

    co2Multiplier(routes, arrayOfRoutes, totalRoutes);//Finding the CO2 emission for different types of transportation

    transportToNodes(arrayOfRoutes, totalRoutes, routes, arrivalCity, departureCity);//Calculating whether the user will be directly at the station/airport or if they are using a bus

    advancedDetails(arrayOfRoutes, totalRoutes, routes /*, arrivalCity, departureCity*/);//In this section we explain in more details how the calculations went through it.


        return 0;
    }
