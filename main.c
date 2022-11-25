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

    return 0;
}

