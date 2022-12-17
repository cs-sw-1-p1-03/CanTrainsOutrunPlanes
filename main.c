// Standard libraries
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
//  Our own libraries
#include "interface.h"
#include "getArrayOfRoutes.h"
#include "searchRoutes.h"
#include "emissionCalculator.h"
#include "advancedDetails.h"
#include "destinationChoices.h"
#include "failSafe.h"
#include "transportToNodes.h"

#define maxCharacters 20
#define numberOfStrings 50

int main() {
    //Interface function
    char departureCity[maxCharacters]; // Assigning amount of characters, it does not scan properly otherwise
    char arrivalCity[maxCharacters];   //                           --||--

    char *routeFileNames[numberOfStrings] = {"FlightDistances.txt", "IC CPH SDG.txt", "ICL CPH AAL.txt",
                                "ICL CPH SDG.txt", "IC CPH AAL.txt", "IC CPH BLL.txt",
                                "ICL CPH BLL.txt", "ICL CPH KRP.txt", "IC CPH KRP.txt"};

    int routeFileLength[] = {5,13,12,9,16,14,10,13,17};


    int NoR = sizeof(routeFileLength) / sizeof(int);

    route_t arrayOfRoutes[NoR];
    routeFile_t arrayOfRouteFiles[NoR];

    initializeArrayOfRoutes(arrayOfRoutes, arrayOfRouteFiles, routeFileNames, routeFileLength, NoR);

    displayWelcome();//Printing the first interface that the user will receive

    arrayOfStrings_t cityChoices[numberOfStrings];
    destinationChoices(arrayOfRouteFiles, arrayOfRoutes,  cityChoices);
    printChoices(cityChoices);

    displayInfo();//Printing the second interface that the user will receive about the details they will get


    scanChar(departureCity,cityChoices,numberOfStrings,"Please enter your departure\n");

    arrayOfStrings_t arrivalChoice[numberOfStrings];
    arrivalChoices(arrayOfRouteFiles, arrayOfRoutes,  departureCity, cityChoices, arrivalChoice);
    printChoices(arrivalChoice);

    scanChar(arrivalCity,arrivalChoice,numberOfStrings,"Please enter your arrival city\n");

    searchRoutes(arrivalCity, departureCity, arrayOfRoutes, arrayOfRouteFiles); //Reading the list

    co2Multiplier(arrayOfRoutes);//Finding the CO2 emission for different types of transportation

    transportToNodes(arrayOfRoutes, arrivalCity, departureCity);
    //Calculating whether the user will be directly at the station/airport or if they are using a bus

    advancedDetails(arrayOfRoutes);//In this section we explain in more details how the calculations went through it.

    return 0;
}
