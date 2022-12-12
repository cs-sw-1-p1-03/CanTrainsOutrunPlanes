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
}route_t; //!!!This name has to be changed, Brian will notice.

//This struct is used to streamline the reading of route files, and the population of the final array of routes.
typedef struct{
    FILE* file;
    char fileName[30];
    int length;
    char typeOfTransport[100];
}routeFile_t;

/**
 * Function that is called to populate an entry of a routeInterval
 * @param list A list of routeIntervals that will be overriden by the data contained in the routeList argument
 * @param numberOfRoutes Takes in the number of routes available
 * @param routeList Takes in a file, that will be read and used to populate the list parameter
 */
void readRouteFromFiles(routeIntervals_t list[], int numberOfRoutes, FILE* routeList) {
    for(int i = 0; i < numberOfRoutes; i++) {

        fscanf(routeList, "%s",   list[i].departureCity);
        fscanf(routeList, " %s",  list[i].arrivalCity);
        fscanf(routeList, " %lf", &list[i].speed);
        fscanf(routeList, " %lf", &list[i].time);
        fscanf(routeList, " %lf", &list[i].distance);

        // String Copy because cant assign strings to new variable. strcpy copies element by element of the array
        // Here you can assign the values to new variables
    }
}
/**
 * Opens all files into an array
 * @param routes The list that will be populated with the opened files.
 */
void defineFiles2(routeFile_t routes[],int totalRoutes){

    char* fileNames[10] = {"FlightDistances.txt","IC CPH SDG.txt","ICL CPH AAL.txt","ICL CPH SDG.txt","IC CPH AAL.txt","IC CPH BLL.txt","ICL CPH BLL.txt","ICL CPH KRP.txt","IC CPH KRP.txt"};
    int fileLengths[10] = {5,13,12,9,16,14,10,13,17};
    char* typeOfTransport[10] = {"Airplane","IC","ICL","ICL","IC","IC","ICL","ICL","IC"};

    for (int i = 0; i < totalRoutes; i++){
        strcpy(routes[i].fileName,fileNames[i]); routes[i].length = fileLengths[i]; strcpy(routes[i].typeOfTransport,typeOfTransport[i]);
    }
}

 void openFile(routeFile_t route){
    route.file = fopen(route.fileName,"r");
}

void createArrayOfRoute(route_t arrayOfRoute,routeFile_t route){
    readRouteFromFiles(arrayOfRoute.list,route.length,route.file);
}

void closeFile(routeFile_t route){
    fclose(route.file);
}