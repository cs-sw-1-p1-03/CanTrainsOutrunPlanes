#include "string.h"
#include <stdio.h>


/**
 * A struct which represent a line from txt files. Line is define
 */
typedef struct {
    char departureCity[20];
    char arrivalCity[20];
    double speed;
    double time;
    double distance;
}routeIntervals_t;


/**
 * A struct represent a file in route format which is determined by line of struct routeIntervals_t.
 * TypeOfTransport is assigned as for trains: IC or ICL. Otherwise Airplane
 * It includes variables such as totalTime and totalCO2 to determined the routes time and CO2.
 * The integer found is used as a boolean. 1 if the route is possible (includes departure and arrival) and 0 for not.
 * The rest variables are used for calculations and prints.
 */
typedef struct{
    routeIntervals_t list[100];
    char typeOfTransport[100];
    int found;
    double totalTime;
    int totalTimeBus;
    double totalDistance;
    double totalTravelCO2;
    double totalCO2;
    double averageSpeed;
}route_t;

/**
 * A struct represent the file, including the file, fileName and Length.
 * Used in opening and closing files.
 */
typedef struct{
    FILE* file;
    char fileName[30];
    int length;
}routeFile_t;

void initializeRouteFileList(routeFile_t *routeFile, char *routeFileNames[], int routeFileLengths[],route_t arrayOfRoutes[]);
void readIntervalsFromFile(routeIntervals_t list[], int numberOfIntervals, FILE* routeList);

int numberOfRoutes;

/**
 * Calls initializeRouteFileList defines the typeofTransport.
 * for every file it: opens a file, reads it with readIntervalsFromFile and close it.
 * @param arrayOfRoutes An array of the struct route_t from getArrayOfRoutes. Includes the array for routeIntervals_t.
 * @param routeFileArray An array of the struct routeFile_t from getArrayOfRoutes.Includes fileName and length.
 * @param routeFileNames A 2D string array for the txt.files
 * @param routeFileLengths An integer array for the length of each files.
 * @param NoR Is determined numberOfRoutes. Also total number of files.
 */
void initializeArrayOfRoutes(route_t *arrayOfRoutes, routeFile_t *routeFileArray,
                             char *routeFileNames[], int *routeFileLengths, int NoR){
    numberOfRoutes = NoR;
    initializeRouteFileList(routeFileArray, routeFileNames, routeFileLengths,arrayOfRoutes);

    for (int i = 0; i < numberOfRoutes; ++i) {
        routeFileArray[i].file = fopen(routeFileArray[i].fileName,"r");
        readIntervalsFromFile(arrayOfRoutes[i].list, routeFileLengths[i], routeFileArray[i].file);
        fclose(routeFileArray[i].file);
    }
}

/**
 * Function that returns the typeOfTransport in routeFile.typeOfTransport by checking the first 3 number from each text filename.
 * @param routeFile A struct representing the file
 * @param routeFileNames A 2D string array for the txt.files
 * @param routeFileLengths An integer array for the length of each files.
 * @param arrayOfRoutes An array of the struct route_t from getArrayOfRoutes. Includes typeOfTransport
 */
void initializeRouteFileList(routeFile_t routeFile[], char *routeFileNames[], int routeFileLengths[],route_t arrayOfRoutes[]){
    for (int i = 0; i < numberOfRoutes; ++i) {
        strcpy(routeFile[i].fileName, routeFileNames[i]);
        routeFile[i].length = routeFileLengths[i];

        if(routeFileNames[i][0] == 'I' && routeFileNames[i][1] == 'C' && routeFileNames[i][2] == 'L') {
            strcpy(arrayOfRoutes[i].typeOfTransport, "ICL");
        }
        else if(routeFileNames[i][0] == 'I' && routeFileNames[i][1] == 'C'){
                strcpy(arrayOfRoutes[i].typeOfTransport, "IC");
        }
        else{
            strcpy(arrayOfRoutes[i].typeOfTransport, "Airplane");
        }
    }
}
/**
 * Function that reads our text file and return is into list[].
 * @param list An array of struct routeIntervals_t which determined each row in the files.
 * @param numberOfIntervals Integer for number of lines
 * @param routeList Needs to be a type FILE and has to be open.
 */
void readIntervalsFromFile(routeIntervals_t list[], int numberOfIntervals, FILE* routeList) {
    for(int i = 0; i < numberOfIntervals; i++) {

        fscanf(routeList, "%s",   list[i].departureCity);
        fscanf(routeList, " %s",  list[i].arrivalCity);
        fscanf(routeList, " %lf", &list[i].speed);
        fscanf(routeList, " %lf", &list[i].time);
        fscanf(routeList, " %lf", &list[i].distance);

    }
}
