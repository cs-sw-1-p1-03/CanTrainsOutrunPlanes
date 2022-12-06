// Standard libraries
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
//  Our own libraries
#include "interface.h"
#include "getArrayOfRoutes.h"
#include "searchRoutes.h"

void searchRoutes(char arrivalCity[], char departureCity[], arrayOfRoutes_t arrayOfRoutes[], int totalRoutes);

int main() {
    //Interface function
    char departureCity[20]; // Assigning amount of characters, it does not scan properly otherwise
    char arrivalCity[20];   //                           --||--
    interface(departureCity,
              arrivalCity); // We have added the interface function to a h file, and then we can call interface
    // the same way we would call a strcmp or strlen

    int totalRoutes = 5;
    //array for routes
    arrayOfRoutes_t arrayOfRoutes[totalRoutes];//Initializing a static array with the size of totalRoutes
    //The list is defined as an array of arrays(routeIntervals_t)
    //This list is empty

    createArrayOfRoutes(arrayOfRoutes); //Fulfilling the list with the void function

    searchRoutes(arrivalCity, departureCity, arrayOfRoutes, totalRoutes); //Reading the list

    route_t routes[totalRoutes]; //Creating an empty array of routes
    routesFilesOpen(routes); //Filling it up

    typeOfTransport(arrayOfRoutes, fileName);
/*
    //CO2 Footprint per person km
    int interCityLyn = 56;
    int interCity = 47;
    int averageFlight = 111;

    for (int i = 0; i < totalRoutes; ++i) {
        for (int j = 0; j < totalRoutes; ++j) {
            if (strcmp(routes[i].typeOfTransport, "Airplane")==0){
                int h;
            }
        }
    }

    int totalTransport = 3;

    char typeOfTransport[3][20] = {"Pla","IC","ICL"};
    int CO2[3] = {53,53,53};

    for (int i = 0; i < totalTransport; i++){
        if (strcpy(type,typeOfTransport[i])){
            result = distance * CO2[i]
        }
    }

*/
   // int carbonEmission = listOfList[i].totalDistance * ;
}


