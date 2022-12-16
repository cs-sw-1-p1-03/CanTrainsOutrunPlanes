#include "string.h"
#include <stdio.h>


// We choose to use struct for our underlying datastructure, as it's suitable for small data structures which won't be modified

//The underlying struct for the segments of the routes
typedef struct {
    // The parameters follow the structure of the lists
    char departureCity[20];
    char arrivalCity[20];
    double speed;
    double time;
    double distance;
}routeIntervals_t;

//The struct that represents a number of route segments, and information about the given route
typedef struct{
    routeIntervals_t list[100];
    int found;
    double totalTime;   //RouteTime?
    int totalTimeBus;
    double totalTimeWalk;
    double totalDistance;
    double totalTravelCO2;
    double totalCO2; //change to routeCO2?
    double averageSpeed;
}route_t;

//This struct is used to streamline the reading of route files, and the population of the final array of routes.
typedef struct{
    FILE* file;
    char fileName[30];
    int length;
    char typeOfTransport[100];
}routeFile_t;

void initializeRouteFileList(routeFile_t *routeFile, char *routeFileNames[], int routeFileLengths[]);
void readIntervalsFromFile(routeIntervals_t list[], int numberOfIntervals, FILE* routeList);

int numberOfRoutes;

void initializeArrayOfRoutes(route_t *arrayOfRoutes, routeFile_t *routeFileArray,
                             char *routeFileNames[], int *routeFileLengths, int NoR){
    numberOfRoutes = NoR;



    initializeRouteFileList(routeFileArray, routeFileNames, routeFileLengths);

    for (int i = 0; i < numberOfRoutes; ++i) {
        routeFileArray[i].file = fopen(routeFileArray[i].fileName,"r");
        readIntervalsFromFile(arrayOfRoutes[i].list, routeFileLengths[i], routeFileArray[i].file);
        fclose(routeFileArray[i].file);
    }
    
}

void initializeRouteFileList(routeFile_t routeFile[], char *routeFileNames[], int routeFileLengths[]){
    for (int i = 0; i < numberOfRoutes; ++i) {
        strcpy(routeFile[i].fileName, routeFileNames[i]);
        routeFile[i].length = routeFileLengths[i];

        if(routeFileNames[i][0] == 'I' && routeFileNames[i][1] == 'C' && routeFileNames[i][2] == 'L') {
            strcpy(routeFile[i].typeOfTransport, "ICL");
        }
        else if(routeFileNames[i][0] == 'I' && routeFileNames[i][1] == 'C'){
            strcpy(routeFile[i].typeOfTransport, "IC");
        }
        else{
            strcpy(routeFile[i].typeOfTransport, "Airplane");
        }
    }
}

void readIntervalsFromFile(routeIntervals_t list[], int numberOfIntervals, FILE* routeList) {
    for(int i = 0; i < numberOfIntervals; i++) {

        fscanf(routeList, "%s",   list[i].departureCity);
        //printf("%s -> ", list[i].departureCity);
        fscanf(routeList, " %s",  list[i].arrivalCity);
        //printf("%s |",list[i].arrivalCity);
        fscanf(routeList, " %lf", &list[i].speed);
        //printf("%")
        fscanf(routeList, " %lf", &list[i].time);
        fscanf(routeList, " %lf", &list[i].distance);


        // String Copy because cant assign strings to new variable. strcpy copies element by element of the array
        // Here you can assign the values to new variables
    }
}