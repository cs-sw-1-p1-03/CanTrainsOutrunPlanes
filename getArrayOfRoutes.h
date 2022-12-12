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
}list_t; //!!!This name has to be changed, Brian will notice.

//This struct is used to streamline the reading of route files, and the population of the final array of routes.
typedef struct{
    FILE* file;
    char fileName[30];
    int length;
    char typeOfTransport[100];
}route_t;

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
void defineFiles2(route_t routes[],int totalRoutes){

    char* fileNames[10] = {"FlightDistances.txt","IC CPH SDG.txt","ICL CPH AAL.txt","ICL CPH SDG.txt","IC CPH AAL.txt","IC CPH BLL.txt","ICL CPH BLL.txt","ICL CPH KRP.txt","IC CPH KRP.txt"};
    int fileLengths[10] = {5,13,12,9,16,14,10,13,17};
    char* typeOfTransport[10] = {"Airplane","IC","ICL","ICL","IC","IC","ICL","ICL","IC"};

    for (int i = 0; i < totalRoutes; i++){
        strcpy(routes[i].fileName,fileNames[i]); routes[i].length = fileLengths[i]; strcpy(routes[i].typeOfTransport,typeOfTransport[i]);
    }
}

void defineFiles(route_t routes[]){
    // Important to change working directory every time you run program
    // Add new files if you want them to run, automatic add file function might be written before exam
    strcpy(routes[0].fileName, "FlightDistances.txt");  routes[0].length = 5 ; strcpy(routes[0].typeOfTransport,"Airplane");
    strcpy(routes[1].fileName,"IC CPH SDG.txt");       routes[1].length = 13; strcpy(routes[1].typeOfTransport,"IC");
    strcpy(routes[2].fileName,"ICL CPH AAL.txt");      routes[2].length = 12; strcpy(routes[2].typeOfTransport,"ICL");
    strcpy(routes[3].fileName,"ICL CPH SDG.txt");      routes[3].length = 9 ; strcpy(routes[3].typeOfTransport,"ICL");
    strcpy(routes[4].fileName,"IC CPH AAL.txt");       routes[4].length = 16; strcpy(routes[4].typeOfTransport,"IC");
    strcpy(routes[5].fileName,"IC CPH BLL.txt");        routes[5].length = 14; strcpy(routes[5].typeOfTransport,"IC");
    strcpy(routes[6].fileName,"ICL CPH BLL.txt");       routes[6].length = 10; strcpy(routes[6].typeOfTransport,"ICL");
    strcpy(routes[7].fileName,"ICL CPH KRP.txt");       routes[7].length = 13; strcpy(routes[7].typeOfTransport,"ICL");
    strcpy(routes[8].fileName,"IC CPH KRP.txt");        routes[8].length = 17; strcpy(routes[8].typeOfTransport,"IC");
}

void openFiles(route_t routes[], int totalRoutes){
    for(int i = 0; i < totalRoutes;i++)
        routes[i].file = fopen(routes[i].fileName,"r");
}


/**
 * Creates an array of routes, that will be used in the rest of the program.
 * @param arrayOfRoutes The array of list that will populated.
 * @param totalRoutes The total amount of routes available.
 * @param routes Our open routes. -- more specifit comments is needed
 */
void createArrayOfRoutes(list_t arrayOfRoutes[], int totalRoutes,route_t routes[]){

    //Each list is read with their own route
    for (int  i = 0;  i < totalRoutes; i++) {
        readRouteFromFiles(arrayOfRoutes[i].list, routes[i].length, routes[i].file);
    }

 }
/**
 * Simple function to close all opened routeFiles
 * @param routes Takes in the array of routes
 * @param totalRoutes Takes in the number of routes
 */
void closeRoutes(route_t routes[], int totalRoutes){

 for (int i = 0; i < totalRoutes; i ++){
 fclose(routes[i].file);
    }
 }


