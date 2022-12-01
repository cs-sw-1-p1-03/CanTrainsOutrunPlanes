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
}list_t;

typedef struct{
    FILE* file;
    int length;
}route_t;


void readRouteFromFiles(routeIntervals_t list[], int numberOfRoutes, FILE* routeList) {
    char departureCity[20];
    char arrivalCity[20];
    double speed;
    int time;
    double distance;

    for (int i = 0; i < numberOfRoutes; i++) {
        fscanf(routeList, " %s", departureCity);
        fscanf(routeList, " %s", arrivalCity);
        fscanf(routeList, " %lf", &speed);
        fscanf(routeList, " %d", &time);
        fscanf(routeList, " %lf", &distance);

        // String Copy because cant assign strings to new variable. strcpy copies element by element of the array
        strcpy(list[i].departureCity, departureCity);
        strcpy(list[i].arrivalCity, arrivalCity);
        // Here you can assign the values to new variables
        list[i].speed = speed;
        list[i].time = time;
        list[i].distance = distance;
    }
}

void routesFilesOpen(route_t routes[]){
    // Important to change working directory every time you run program
    routes[0].file = fopen("FlightDistances.txt", "r");   routes[0].length = 5;
    routes[1].file = fopen("IC CPH SDG.txt", "r");        routes[1].length = 11;
    routes[2].file = fopen("ICL CPH AAL.txt", "r");       routes[2].length = 12;
    routes[3].file = fopen("ICL CPH SDG.txt", "r");       routes[3].length = 7;
    routes[4].file = fopen("InterCity CPH AAL.txt", "r"); routes[4].length = 14;
}

void createListOfList(list_t listOfList[], int totalRoutes){

    //totalRoutes = 5. our 5 lists of routes
    route_t routes[totalRoutes]; //Creating an empty array of routes
    routesFilesOpen(routes); //opens the 5 files and their length in spots of 0 to totalRoutes-1.

    //Each list is read with their own route from 0-4
    for (int  i = 0;  i < totalRoutes; i++) {
        readRouteFromFiles(listOfList[i].list, routes[i].length, routes[i].file);
        fclose(routes[i].file);
    }

    //prints for testing.
/*
            for(int i = 0; i < totalRoutes; i++)
            {
                for(int j = 0; j < routes[i].length;j++) {
                    printf("Line = %d %s %s %.2lf %d %.2lf\n", j, listOfList[i].list[j].departureCity, listOfList[i].list[j].arrivalCity, listOfList[i].list[j].speed,
                           listOfList[i].list[j].time, listOfList[i].list[j].distance);
                }
                printf("----------------\n");
            }
*/
 }
