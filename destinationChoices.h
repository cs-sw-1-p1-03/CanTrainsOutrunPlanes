#include "string.h"
#include "stdio.h"

typedef struct {
    char string[35];
}arrayOfStrings_t;

void destinationChoices(routeFile_t routes[], route_t arrayOfRoutes[], int totalRoutes,arrayOfStrings_t cityChoices[]){
    for (int k = 0; k < 50; k++) {
        strcpy(cityChoices[k].string, "");
    }

    for (int i = 0; i < totalRoutes; i++) {
        for (int j = 0; j < routes[i].length; j++) {
            int foundInList = 0;
            for (int k = 0; k < 50; k++) {

                if (strcmp(arrayOfRoutes[i].list[j].arrivalCity, cityChoices[k].string) == 0) {
                    foundInList = 1;
                }
                if (foundInList == 0 && strcmp(cityChoices[k].string, "") == 0) {
                      strcpy(cityChoices[k].string, arrayOfRoutes[i].list[j].arrivalCity);
                    break;
                }
            }
        }
    }
}
void destinationChoices2(routeFile_t routes[], route_t arrayOfRoutes[], int totalRoutes, char* cityChoices[]){

    for (int k = 0; k < 20; k++) {
        //strcpy(cityChoices[k], "");
    }

    for (int i = 0; i < totalRoutes; i++) {
        for (int j = 0; j < routes[i].length; j++) {
            int foundInList = 0;
            for (int k = 0; k < 20; k++) {

                if (strcmp(arrayOfRoutes[i].list[j].arrivalCity, cityChoices[k]) == 0) {
                    foundInList = 1;
                }
                if (foundInList == 0 && strcmp(cityChoices[k], "") == 0) {
                    strcpy(cityChoices[k], arrayOfRoutes[i].list[j].arrivalCity);
                    break;
                }
            }
        }
    }
}

void arrivalChoices(routeFile_t routes[], route_t arrayOfRoutes[], int totalRoutes,char departureCity[], arrayOfStrings_t cityChoices[],arrayOfStrings_t arrivalChoice[]){
    for (int k = 0; k < 50; k++) {
        strcpy(arrivalChoice[k].string, "");
    }

            for (int i = 0; i < totalRoutes; i++) {
                int foundInList = 0;

                for (int j = 0; j < routes[i].length; j++) {
                    if (strcmp(departureCity, arrayOfRoutes[i].list[j].departureCity) == 0) {
                        foundInList = 1;
                        break;
                    }
                }

                for (int j = 0; j < routes[i].length; j++) {
                    int alreadyInList = 0;

                    for (int k = 0; k < 50; k++) {
                        if (strcmp(arrayOfRoutes[i].list[j].arrivalCity, arrivalChoice[k].string) == 0) {
                            alreadyInList = 1;
                        }

                        if (alreadyInList == 0 && strcmp(arrivalChoice[k].string, "") == 0 && foundInList == 1 && strcmp(arrayOfRoutes[i].list[j].arrivalCity,departureCity)!=0) {
                            strcpy(arrivalChoice[k].string, arrayOfRoutes[i].list[j].arrivalCity);
                            break;
                        }
                    }
                }
            }
            for (int k = 0; k < routes[0].length; k++) {
                if (strcmp(departureCity,arrayOfRoutes[0].list[k].arrivalCity) == 0 && strcmp(cityChoices[k].string,"") == 0){
                    strcpy(cityChoices[k].string, "CPHAirport");
                    break;
                }
            }
        }



void printChoices(arrayOfStrings_t cityChoices[]){
    printf("You can choose between:\n");

    int table = 0;
    for (int k = 0; k < 50; k++) {

        if (strcmp(cityChoices[k].string, "") != 0) {
            printf(" %-13s \t", cityChoices[k].string);
            table++;

            if (table >= 3) {
                printf("\n");
                table = 0;
            }
        }
    }
    printf("\n");
}
void printChoices2(char* cityChoices[]){
    printf("You can choose between:\n");

    int table = 0;
    for (int k = 0; k < 20; k++) {

        if (strcmp(cityChoices[k],"") != 0) {
            printf(" %-13s \t",cityChoices[k]);
            table++;

            if (table >= 3) {
                printf("\n");
                table = 0;
            }
        }
    }
    printf("\n");
}