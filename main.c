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

    //calculate();

    transportToNodes(arrayOfRoutes, totalRoutes, routes, arrivalCity, departureCity);

    advancedDetails(arrayOfRoutes, totalRoutes, routes, arrivalCity, departureCity);

}

/* char timeConverter[](int aMinutes)
 * {
 * int minutes, hours;
 *
 * minutes = aMinutes % 60;
 * hours = (aMinutes - minutes) / 60;
 *
 *
 * return strcat((strcat(itoa(hours), " hours and"), (strcat(itoa(minutes), " minutes"));
 */