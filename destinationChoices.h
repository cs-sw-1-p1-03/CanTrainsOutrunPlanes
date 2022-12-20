#include "string.h"
#include "stdio.h"

/**
 * A struct to help defining and calling 2D arrays for strings.
 * We tried with "string[][]" this but it didn't work so we used a struct.
 */
typedef struct {
    char string[35];
}arrayOfStrings_t;

/**
 * Function to create a list of choices to choose when choosing departure city
 * @param routeFileArray An array of the struct routeFile_t from getArrayOfRoutes.Includes file length.
 * @param arrayOfRoutes An array of the struct route_t from getArrayOfRoutes. Includes array of struct routeIntervals -> list.departureCity
 * @param cityChoices Returns an array of strings for possible cities to choose from.
 */
void destinationChoices(routeFile_t routeFileArray[], route_t arrayOfRoutes[], arrayOfStrings_t cityChoices[]){

    int numberOfStrings = 50; // arbitrary ceiling.

    for (int k = 0; k < numberOfStrings; k++) { // initialized to being empty
        strcpy(cityChoices[k].string, "");
    }

    for (int i = 0; i < numberOfRoutes; i++) { // global variable = 9. runs 9 times.
        for (int j = 0; j < routeFileArray[i].length; j++) { // length of the lines in the txt files.
            int alreadyInList = 0; // make them not being in the list. making it false
            for (int k = 0; k < numberOfStrings; k++) { // number of arbitrary ceiling

                if (strcmp(arrayOfRoutes[i].list[j].departureCity, cityChoices[k].string) == 0) { // List of cityChoices for the user.
                    alreadyInList = 1; // if the city is found then we do nothing.
                }
                if (alreadyInList == 0 && strcmp(cityChoices[k].string, "") == 0 && strcmp(arrayOfRoutes[i].list[j].departureCity,"empty") != 0) { // condition is made, so if not in the list, and array has empty string "",
                                                                                                                                                    // and "empty" is not shown then we strcpy the departure city to our string. So back to the loop.
                      strcpy(cityChoices[k].string, arrayOfRoutes[i].list[j].departureCity);
                    break;
                }
            }
        }
    }
}
/**
 * Function to create arrivalChoices for possible routes of the input departureCity.
 * @param routeFileArray An array of the struct routeFile_t from getArrayOfRoutes.Includes file length.
 * @param arrayOfRoutes An array of the struct route_t from getArrayOfRoutes. Includes array of struct routeIntervals -> list.departureCity
 * @param departureCity The chosen input string from user.
 * @param cityChoices  An array of strings for all cities.
 * @param arrivalChoice Returns an array of strings for possible arrival cities to choose from.
 */
void arrivalChoices(routeFile_t routeFileArray[], route_t arrayOfRoutes[], char departureCity[],
                    arrayOfStrings_t cityChoices[], arrayOfStrings_t arrivalChoice[]){
    for (int k = 0; k < 50; k++) { // makes the struct of the array empty.  You can only travel in a straight path, 1 city to 1 other.
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
                    alreadyInList = 1; // assign value 1 to avoid duplicates.
                }

                if (alreadyInList == 0 && strcmp(arrivalChoice[k].string, "") == 0 && foundInRoute == 1 && strcmp(arrayOfRoutes[i].list[j].arrivalCity,departureCity)!=0) { // condition is made, so if not in the list, and array has empty string "",
                                                                                                                                                                            // and "empty" is not shown then we strcpy the departure city to our string, and the departureCity is not printed. So back to the loop.
                    strcpy(arrivalChoice[k].string, arrayOfRoutes[i].list[j].arrivalCity);
                    break;
                }
            }
        }
    }

    for (int k = 0; k < routeFileArray[0].length; k++) { // for airplane, checks every line in flightDistances.
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

        if (strcmp(cityChoices[k].string, "") != 0) { //if the string isnt empty, then we print.
            printf(" %-13s \t", cityChoices[k].string); // -13s.  -  left oriented.  13  always print 13 characters incl spaces.
            table++; // adds 1 to table value. New line when 3 columns are printed.

            if (table >= 3) {
                printf("\n");
                table = 0;
            }
        }
    }
    printf("\n");
}