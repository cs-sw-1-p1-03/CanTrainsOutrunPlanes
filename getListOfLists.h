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

int countLines(FILE*);

void readRouteFromFiles(routeIntervals_t list[],int size, FILE* routeList) {
    //routeList = fopen("IC CPH SDG.txt", "r");

    for (int i = 0; i < size; i++) {

    fscanf(routeList, " %s", list[i].departureCity);
    fscanf(routeList, " %s", list[i].arrivalCity);
    fscanf(routeList, " %lf", &list[i].speed);
    fscanf(routeList, " %lf", &list[i].time);
    fscanf(routeList, " %lf", &list[i].distance);

}



    // String Copy because cant assign strings to new variable. strcpy copies element by element of the array
    // Here you can assign the values to new variables
}

// allocating file names in array to avoid opening all files at once
char routeFileNames[100][100] = {"FlightDistances.txt","IC CPH SDG.txt","ICL CPH AAL.txt","ICL CPH SDG.txt","InterCity CPH AAL.txt"};



void routesFilesOpen(route_t routes[]){

    // Important to change working directory every time you run program
    // Opens files and copies over to variables in the program
   for (int i = 0; i < 5; ++i) {
        routes[i].file = fopen(routeFileNames[i],"r");
       if (!(routes[i].file)) {
           EXIT_FAILURE;
       }
        routes[i].length = countLines(routes[i].file);
        fclose(routes[i].file);
    }
}

void readFile(char fileName[], routeIntervals_t route[]) {

    // -------------- If file doesnt open, exits the program----------------
    FILE *file = fopen(fileName, "r");

        readRouteFromFiles(route, 16 ,file);

}

int countLines(FILE *file){
    int ch = 0, lines = 0;
    //fopen(file, "r");

    while(!feof(file))
    {
        ch = fgetc(file);
        if(ch == '\n')
        {
            lines++;
        }
    }
    lines++;
    return lines;
}

void createListOfList(list_t listOfList[], int totalRoutes){

    //totalRoutes = 5. our 5 lists of routes
    //route_t routes[totalRoutes]; //Creating an empty array of routes
    //routesFilesOpen(routes); //opens the 5 files and their length in spots of 0 to totalRoutes-1.

    //Each list is read with their own route from 0-4
    /*
    for (int  i = 0;  i < totalRoutes; i++) {
        readRouteFromFiles(listOfList[i].list, routes[i].length, routes[i].file);
        fclose(routes[i].file);
    } */


    for (int i = 0; i < totalRoutes; i++) {

        readFile(routeFileNames[i], listOfList[i].list);
      //  printf("yo %s \n",routeFileNames[i]);
    }


    //prints for testing.
/*
    for(int i = 0; i < totalRoutes; i++)
    {
        for(int j = 0; j < routes[i].length;j++) {
            printf("Line = %d %s %s %.2lf %lf %.2lf\n", j, listOfList[i].list[j].departureCity, listOfList[i].list[j].arrivalCity, listOfList[i].list[j].speed,
                   listOfList[i].list[j].time, listOfList[i].list[j].distance);
        }
        printf("----------------\n");
    }
*/
}
