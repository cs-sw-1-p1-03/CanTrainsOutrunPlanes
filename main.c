#include <stdio.h>
#include <stdlib.h>
#include "distanceFunctionPlane.h"
#include "distanceFunctionTrain.h"
#include "interface.h"
#include "string.h"
#include "getListOfLists.h"



int main() {
    //Interface function
    /*
    char departureCity[20]; // Assigning amount of characters, it did want to scan properly otherwise
    char arrivalCity[20];   //                           --||--
    interface(departureCity, arrivalCity); // We have added the interface function to a h file, and then we can call interface
                                           // the same way we would call a strcmp or strlen
           */

    int totalRoutes = 5;
    list_t listOfList[totalRoutes];//Initializing a static array with the size of totalRoutes
                                   //The list is defined as an array of arrays(routeIntervals)
                                   //This list is empty

    createListOfList(listOfList,totalRoutes); //Fulfilling the list with the void function


    char city_1[20];
    char city_2[20];
    route_t routes[totalRoutes]; //Creating an empty array of routes
    routesFilesOpen(routes); //Filling it up

    // starting at -1 because our list elements start at 0. Starting at allows element at line 0 to be included
    int departureIndex = -1;
    int arrivalIndex = -1;
    //Making sure that no list is found before we start searching.
    for(int i = 0; i < totalRoutes; i++) {
        listOfList[i].found = 0;
    }

    for(int i = 0; i < totalRoutes; i++) {           //for every list
        for (int j = 0; j < routes[i].length; j++) { //for every line
            if (strcpy(listOfList[i].list[j].departureCity,city_1) == 0){
                departureIndex = j;
            }
            if (strcpy(listOfList[i].list[j].arrivalCity,city_2) == 0){
                arrivalIndex = j;
            }
        }
        if (departureIndex >= 0 && arrivalIndex >= 0){
            listOfList[i].found = 1;
        }
        // resetting so Indexes are no longer equal to j
        departureIndex = -1;
        arrivalIndex = -1;
    }

    for(int i = 0; i < totalRoutes; i++) {
        listOfList[i].totalTime = 0;
        listOfList[i].totalDistance = 0;
        listOfList[i].averageSpeed = 0;
    }
/*
    ((29.5 x 24) + (133.4 x 74)) / ( 2 x 98)

    29.5 / 24 = average pr. min
    133.4 / 74 = average pr. min

    (29.5 + 133.4) / ((24 + 74) /  60) <- average speed
*/

    if (departureIndex > arrivalIndex){
        //then the list is upwards
        for(int i = 0; i < totalRoutes; i++) {           //for every list
            for (int j = departureIndex; j > (departureIndex - arrivalIndex); j--) {
                listOfList[i].totalTime += listOfList[i].list[j].time;
                listOfList[i].totalDistance += listOfList[i].list[j].distance;
                listOfList[i].averageSpeed = 
            }
    }
    else if (departureIndex < arrivalIndex){
        // list is read downwards
    }


    return 0;
}

