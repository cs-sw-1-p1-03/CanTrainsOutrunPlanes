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


    int totalRoutes = 9;
    //array for routes
    list_t arrayOfRoutes[totalRoutes];//Initializing a static array with the size of totalRoutes
    //The list is defined as an array of arrays(routeIntervals_t)
    //This list is empty

    createArrayOfRoutes(arrayOfRoutes, totalRoutes); //Fulfilling the list with the void function

    searchRoutes(arrivalCity, departureCity, arrayOfRoutes, totalRoutes); //Reading the list

    route_t routes[totalRoutes]; //Creating an empty array of routes
    routesFilesOpen(routes); //Filling it up

    interface1();

    char cityChoices[50][100];
    for(int k = 0; k < 50; k ++) {
        strcpy(cityChoices[k],"");
    }


    for (int i = 0; i < totalRoutes; i++) {
        for (int j = 0; j < routes[i].length; j++) {
            int foundInList = 0;
           for(int k = 0; k < 50; k ++){



               if (strcmp(arrayOfRoutes[i].list[j].arrivalCity, cityChoices[k]) == 0 ){
                   foundInList = 1;
               }


                if (foundInList == 0 && strcmp(cityChoices[k],"")==0) {
                    strcpy(cityChoices[k], arrayOfRoutes[i].list[j].arrivalCity);
                    break;
                }
           }
        }
    }

    closeRoutes(routes,totalRoutes);

    printf("You can choose between:\n");

    int table = 0;
    for(int k = 0; k < 50; k ++){
        if(strcmp(cityChoices[k],"")!=0) {
            printf(" %-13s \t", cityChoices[k]);
            table++;
           // int length = sizeof(cityChoices[k]);
           //if(length >= 4)
            if(table >= 3) {
                printf("\n");
                table = 0;
            }
        }
    }
    printf("\n");


    interface2(departureCity,
              arrivalCity); // We have added the interface function to a h file, and then we can call interface
    // the same way we would call a strcmp or strlen

    routesFilesOpen(routes); //Filling it up
    searchRoutes(arrivalCity, departureCity, arrayOfRoutes, totalRoutes); //Reading the list

    co2Multiplier(routes, arrayOfRoutes, totalRoutes);

    //calculate();

    transportToNodes(arrayOfRoutes, totalRoutes, routes, arrivalCity, departureCity);

    advancedDetails(arrayOfRoutes, totalRoutes, routes, arrivalCity, departureCity);

}