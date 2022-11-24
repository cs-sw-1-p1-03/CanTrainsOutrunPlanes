#include <stdio.h>
#include <stdlib.h>
#include "distanceFunctionPlane.h"
#include "distanceFunctionTrain.h"
#include "interface.h"
#include "string.h"

// We choose to use a struct as it's suitable for small data structures which won't be modified
typedef struct {
    // The parameters follow the structure of the lists
    char departureCity[20];
    char arrivalCity[20];
    double speed;
    int time;
    double distance;

}routeIntervals;

typedef struct{
    routeIntervals list[100];
}list_t;

typedef struct{
    FILE* file;
    int length;
}route_t;


void readRouteFromFiles(routeIntervals list[], int numberOfRoutes,FILE* routeList) {
    char departureCity[20];
    char arrivalCity[20];
    double speed;
    int time;
    double distance;

    for (int i = 0; i < numberOfRoutes; i++) {
        fscanf(routeList, "%s", departureCity);
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

void routesOpen(route_t routes[]){
    // Important to change working directory every time you run program
    routes[0].file = fopen("FlightDistances.txt", "r");   routes[0].length = 5;
    routes[1].file = fopen("IC CPH SDG.txt", "r");        routes[1].length = 11;
    routes[2].file = fopen("ICL CPH AAL.txt", "r");       routes[2].length = 10;
    routes[3].file = fopen("ICL CPH SDG.txt", "r");       routes[3].length = 7;
    routes[4].file = fopen("InterCity CPH AAL.txt", "r"); routes[4].length = 14;
}

    void createListOfList(list_t listOfList[], int totalRoutes){

        //totalRoutes = 5. our 5 lists of routes
        route_t routes[totalRoutes]; //Creating an empty array of routes
        routesOpen(routes); //opens the files with their length in spots of 0 to totalRoutes-1.

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
            } */
}

int main() {
    //Interface function
    /*
    char departureCity[20]; // Assigning amount of characters, it did want to scan properly otherwise
    char arrivalCity[20];   //                           --||--
    interface(departureCity, arrivalCity); // We have added the interface function to a h file, and then we can call interface
                                           // the same way we would call a strcmp or strlen
           */

    int totalRoutes = 5;
    list_t listOfList[totalRoutes];//Initializing a static array with the size of totalRoutes
                                   //The list is defined as an array of arrays(routeIntervals)

    createListOfList(listOfList,totalRoutes);


    return 0;
}

