#include "string.h"
#include "stdio.h"

/**
 * A struct to help defining and calling 2D arrays for strings.
 */
typedef struct {
    char string[35];
}arrayOfStrings_t;

/**
 * Function to create a list of choices to choose when choosing departure city
 * @param routeFileArray An array of the struct routeFile_t from getArrayOfRoutes.Includes fileName, length and TypeOfTransport.
 * @param arrayOfRoutes An array of the struct route_t from getArrayOfRoutes. Includes array of struct routeIntervals -> list.departureCity
 * @param cityChoices Returns an array of strings for possible cities to choose from.
 */
void destinationChoices(routeFile_t routeFileArray[], route_t arrayOfRoutes[], arrayOfStrings_t cityChoices[]){

    int numberOfStrings = 50;

    for (int k = 0; k < numberOfStrings; k++) {
        strcpy(cityChoices[k].string, "");
    }

    for (int i = 0; i < numberOfRoutes; i++) {
        for (int j = 0; j < routeFileArray[i].length; j++) {
            int alreadyInList = 0;
            for (int k = 0; k < numberOfStrings; k++) {

                if (strcmp(arrayOfRoutes[i].list[j].departureCity, cityChoices[k].string) == 0) {
                    alreadyInList = 1;
                }
                if (alreadyInList == 0 && strcmp(cityChoices[k].string, "") == 0 && strcmp(arrayOfRoutes[i].list[j].departureCity,"empty") != 0) {
                      strcpy(cityChoices[k].string, arrayOfRoutes[i].list[j].departureCity);
                    break;
                }
            }
        }
    }
}
/**
 * Function to create arrivalChoices for possible routes of the input departureCity.
 * @param routeFileArray An array of the struct routeFile_t from getArrayOfRoutes.Includes fileName, length and TypeOfTransport.
 * @param arrayOfRoutes An array of the struct route_t from getArrayOfRoutes. Includes array of struct routeIntervals -> list.departureCity
 * @param departureCity The chosen input string from user.
 * @param cityChoices  An array of strings for all cities.
 * @param arrivalChoice Returns an array of strings for possible arrival cities to choose from.
 */
void arrivalChoices(routeFile_t routeFileArray[], route_t arrayOfRoutes[], char departureCity[],
                    arrayOfStrings_t cityChoices[], arrayOfStrings_t arrivalChoice[]){
    for (int k = 0; k < 50; k++) {
        strcpy(arrivalChoice[k].string, "");
    }

    for (int i = 0; i < numberOfRoutes; i++) {
        int foundInRoute = 0;

        for (int j = 0; j < routeFileArray[i].length; j++) {
            if (strcmp(departureCity, arrayOfRoutes[i].list[j].departureCity) == 0) {
                foundInRoute = 1;
                break;
            }
        }

        for (int j = 0; j < routeFileArray[i].length; j++) {
            int alreadyInList = 0;

            for (int k = 0; k < 50; k++) {
                if (strcmp(arrayOfRoutes[i].list[j].arrivalCity, arrivalChoice[k].string) == 0) {
                    alreadyInList = 1;
                }

                if (alreadyInList == 0 && strcmp(arrivalChoice[k].string, "") == 0 && foundInRoute == 1 && strcmp(arrayOfRoutes[i].list[j].arrivalCity,departureCity)!=0) {
                    strcpy(arrivalChoice[k].string, arrayOfRoutes[i].list[j].arrivalCity);
                    break;
                }
            }
        }
    }

    for (int k = 0; k < routeFileArray[0].length; k++) {
        if (strcmp(departureCity,arrayOfRoutes[0].list[k].arrivalCity) == 0 && strcmp(cityChoices[k].string,"") == 0){
            strcpy(cityChoices[k].string, "CPHAirport");
            break;
        }
    }
}


/**
 * Function to print possible cities to choose from in table of 3 columns.
 * @param cityChoices An array of strings to be printed.
 */
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