// Standard libraries
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
//  Our libraries
#include "distanceFunctionPlane.h"
#include "distanceFunctionTrain.h"
#include "interface.h"
#include "getListOfLists.h"



int main() {
    //Interface function

    char departureCity[20]; // Assigning amount of characters, it did want to scan properly otherwise
    char arrivalCity[20];   //                           --||--
    interface(departureCity, arrivalCity); // We have added the interface function to a h file, and then we can call interface
                                           // the same way we would call a strcmp or strlen
           */

    int totalRoutes = 5;
    list_t listOfList[totalRoutes];//Initializing a static array with the size of totalRoutes
    //The list is defined as an array of arrays(routeIntervals_t)
    //This list is empty

    createListOfList(listOfList, totalRoutes); //Fulfilling the list with the void function


    route_t routes[totalRoutes]; //Creating an empty array of routes
    routesFilesOpen(routes); //Filling it up

    // starting at -1 because our list elements start at 0. Starting at allows element at line 0 to be included
    int departureIndex = -1;
    int arrivalIndex = -1;
    //Making sure that no list is found before we start searching.
    for (int i = 0; i < totalRoutes; i++) {
        listOfList[i].found = 0;
    }
    for (int i = 0; i < totalRoutes; i++) {
        listOfList[i].totalTime = 0;
        listOfList[i].totalDistance = 0;
        listOfList[i].averageSpeed = 0;
    }


    for (int i = 0; i < totalRoutes; i++) {           //for every list
        for (int j = 0; j < routes[i].length; j++) { //for every line
            if (strcmp(listOfList[i].list[j].departureCity, departureCity) == 0) {
                departureIndex = j;
            }
            if (strcmp(listOfList[i].list[j].arrivalCity, arrivalCity) == 0) {
                arrivalIndex = j;
            }

        printf("index %d and %d: ",departureIndex,arrivalIndex);

        printf("list: %d. totalTime =  %lf totalDistance =  %lf averageSpeed = %lf\n", i, listOfList[i].totalTime,
               listOfList[i].totalDistance, listOfList[i].averageSpeed);
        // resetting so Indexes are no longer equal to j
        departureIndex = -1;
        arrivalIndex = -1;
    }

}