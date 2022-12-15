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

    char *routeFileNames[25] = {"FlightDistances.txt", "IC CPH SDG.txt", "ICL CPH AAL.txt",
                                "ICL CPH SDG.txt", "IC CPH AAL.txt", "IC CPH BLL.txt",
                                "ICL CPH BLL.txt", "ICL CPH KRP.txt", "IC CPH KRP.txt"};

    int routeFileLength[] = {5,13,12,9,16,14,10,13,17};


    int NoR = sizeof(routeFileLength) / sizeof(int);

    route_t arrayOfRoutes[sizeof(*routeFileNames) / sizeof(char[25])];
    routeFile_t arrayOfRouteFiles[sizeof(*routeFileNames) / sizeof(char[25])];

    initializeArrayOfRoutes(arrayOfRoutes, arrayOfRouteFiles, routeFileNames, routeFileLength, NoR);

    interFaceWelcome();//Printing the first interface that the user will receive

    arrayOfStrings_t cityChoices[50];
    destinationChoices(arrayOfRouteFiles, arrayOfRoutes,  cityChoices);
    printChoices(cityChoices);


    interFaceFiller();//Printing the second interface that the user will receive about the details they will get


    failsafeCityChoice(departureCity, cityChoices);

    arrayOfStrings_t arrivalChoice[50];
    arrivalChoices(arrayOfRouteFiles, arrayOfRoutes,  departureCity, cityChoices, arrivalChoice);
    printChoices(arrivalChoice);

    failsafeCityChoice(arrivalCity, arrivalChoice);


    searchRoutes(arrivalCity, departureCity, arrayOfRoutes, arrayOfRouteFiles); //Reading the list

    co2Multiplier(arrayOfRouteFiles, arrayOfRoutes);//Finding the CO2 emission for different types of transportation

    transportToNodes(arrayOfRoutes,  arrayOfRouteFiles, arrivalCity, departureCity);
    //Calculating whether the user will be directly at the station/airport or if they are using a bus

    advancedDetails(arrayOfRoutes,arrayOfRouteFiles);//In this section we explain in more details how the calculations went through it.


    return 0;
}
