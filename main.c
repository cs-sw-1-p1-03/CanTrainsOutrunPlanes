// Standard libraries
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
//  Our libraries
#include "distanceFunctionPlane.h"
#include "distanceFunctionTrain.h"
#include "interface.h"
#include "getListOfLists.h"

void readList(char arrivalCity[], char departureCity[], list_t listOfList[], int totalRoutes);

int main() {
    //Interface function

    char departureCity[20]; // Assigning amount of characters, it does not scan properly otherwise
    char arrivalCity[20];   //                           --||--
    interface(departureCity,
              arrivalCity); // We have added the interface function to a h file, and then we can call interface
    // the same way we would call a strcmp or strlen

    int totalRoutes = 5;
    list_t listOfList[totalRoutes];//Initializing a static array with the size of totalRoutes
    //The list is defined as an array of arrays(routeIntervals_t)
    //This list is empty

    createListOfList(listOfList, totalRoutes); //Fulfilling the list with the void function

    readList(arrivalCity,departureCity,listOfList,totalRoutes); //Reading the list

    route_t routes[totalRoutes]; //Creating an empty array of routes
    routesFilesOpen(routes); //Filling it up

    //CO2 Footprint per person km
    int interCityLyn = 65;
    int interCity = 47;
    int averageFlight = 111;

    for (int i = 0; i < totalRoutes; ++i) {
        for (int j = 0; j < ; ++j) {
            if (strcmp(routes[i].typeOfTransport, "")
        }
    }



    int carbonEmission = listOfList[i].totalDistance * ;
}


