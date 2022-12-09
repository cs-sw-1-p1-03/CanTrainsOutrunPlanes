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
    for (int k = 0; k < 50; k++) {
        if (strcmp(cityChoices[k], "") == 0) {
            strcpy(cityChoices[k], "CPHAirport");
            break;
        }
    }

    closeRoutes(routes, totalRoutes);

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

    interFace2();//Printing the second interface that the user will receive about the details they will get

    int flip = 0;
    while (1) {
        scanDepartureCity(departureCity);

        for (int i = 0; i < 50; i++) {
            if (strcmp(departureCity, cityChoices[i]) == 0) {
                flip = 1;
                break;
            }
        }
        if (flip == 1) {
            break;
        }
    }

        char citiesToChoose[20][20];
        for (int k = 0; k < 20; k++) {
            strcpy(citiesToChoose[k], "");
        }

        for (int i = 0; i < totalRoutes; i++) {
            int foundInList = 0;
            for (int j = 0; j < routes[i].length; j++) {

                int alreadyInList = 0;

                for (int k = 0; k < 50; k++) {
                    if (strcmp(departureCity, cityChoices[k]) == 0) {
                        foundInList = 1;
                    }
                }
                for (int k = 0; k < 20; k++) {
                    if (strcmp(arrayOfRoutes[i].list[j].arrivalCity, citiesToChoose[k]) == 0) {
                        alreadyInList = 1;
                    }

                    if (alreadyInList == 0 && strcmp(citiesToChoose[k], "") == 0 && foundInList == 1) {
                        strcpy(citiesToChoose[k], arrayOfRoutes[i].list[j].arrivalCity);
                        break;
                    }
                }
            }
        }

        table = 0;
        for (int k = 0; k < 20; k++) {
            if (strcmp(citiesToChoose[k], "") != 0) {
                printf(" %-13s \t", citiesToChoose[k]);
                table++;
                // int length = sizeof(cityChoices[k]);
                //if(length >= 4)
                if (table >= 3) {
                    printf("\n");
                    table = 0;
                }
            }
        }
    for (int k = 0; k < routes[0].length; k++) {
    if (strcmp(departureCity,arrayOfRoutes[0].list[k].arrivalCity) == 0 && strcmp(cityChoices[k],"") == 0){
            strcpy(cityChoices[k], "CPHAirport");
            break;
        }
    }



        printf("\n");

        flip = 0;
        while (1) {
            scanArrivalCity(arrivalCity);

            for (int i = 0; i < 20; i++) {
                if (strcmp(arrivalCity, citiesToChoose[i]) == 0) {
                    flip = 1;
                    break;
                }
            }
            if (flip == 1) {
                break;
            }
        }

        routesFilesOpen(routes); //Filling it up
        searchRoutes(arrivalCity, departureCity, arrayOfRoutes, totalRoutes); //Reading the list

    co2Multiplier(routes, arrayOfRoutes, totalRoutes);

    //calculate();

    transportToNodes(arrayOfRoutes, totalRoutes, routes, arrivalCity, departureCity);

        advancedDetails(arrayOfRoutes, totalRoutes, routes, arrivalCity, departureCity);//In this section we explain in more details how the calculations went through it.

        closeRoutes(routes, totalRoutes);//Closing the routes
    }
