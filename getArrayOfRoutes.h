#include "string.h"
#include <stdio.h>

// We choose to use a struct as it's suitable for small data structures which won't be modified
typedef struct {
    // The parameters follow the structure of the lists
    char departureCity[20];
    char arrivalCity[20];
    double speed;
    double time;
    double distance;

}routeIntervals_t;

typedef struct{
    routeIntervals_t list[100];
    int found;
    double totalTime;
    double totalDistance;
    double averageSpeed;
    double totalCO2;
}list_t;

typedef struct{
    FILE* file;
    int length;
    char typeOfTransport[];
}route_t;

char fileName[5][50] = {"FlightDistances.txt","IC CPH AAL.txt","IC CPH SDG.txt","ICL CPH AAL.txt","ICL CPH SDG.txt"};
int routeLength[5] = {5, 13, 12, 9, 16};
int totalRoutes = 5;


void readRouteFromFiles(routeIntervals_t list[], int numberOfRoutes, FILE* file) {
    for(int i = 0; i < numberOfRoutes; i++) {

        fscanf(file, "%s", list[i].departureCity);
        fscanf(file, " %s", list[i].arrivalCity);
        fscanf(file, " %lf", &list[i].speed);
        fscanf(file, " %lf", &list[i].time);
        fscanf(file, " %lf", &list[i].distance);

        // String Copy because cant assign strings to new variable. strcpy copies element by element of the array
        // Here you can assign the values to new variables
    }
}

void routesFilesOpen(route_t routes[]){
    for (int i = 0; i < totalRoutes;i++){
        routes[i].file = fopen(fileName[i],"r");
        routes[i].length = routeLength[i];
    }
}

void createArrayOfRoutes(list_t listOfList[], int totalRoutes){

    //totalRoutes = 5. our 5 lists of routes
    route_t routes[totalRoutes]; //Creating an empty array of routes
    routesFilesOpen(routes); //opens the 5 files and their length in spots of 0 to totalRoutes-1.

    //Each list is read with their own route from 0-4
    for (int  i = 0;  i < totalRoutes; i++) {
        readRouteFromFiles(listOfList[i].list, routes[i].length, routes[i].file);
        fclose(routes[i].file);
    }
}

void typeOfTransport(arrayOfRoutes_t arrayOfRoutes[], char *fileNameList) {
    for (int i = 0; i < totalRoutes; ++i) {
        strncpy(arrayOfRoutes[i].typeOfTransport, fileNameList[i], 3);

        printf("%s \n", arrayOfRoutes[i].typeOfTransport);
    }
}

