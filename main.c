#include <stdio.h>
#include <stdlib.h>
#include "distanceFunctionPlane.h"
#include "distanceFunctionTrain.h"
#include "interface.h"
#include "string.h"

// void since using a char does not allow for multiple returns

void readRouteFromFiles(routeIntervals list[],int numberOfRoutes,FILE* routelist)
{
    char departureCity[20];
    char arrivalCity[20];
    double speed;
    int time;
    double distance;

    for(int i = 0; i < numberOfRoutes; i++)
    {
        fscanf(routelist,"%s", departureCity);
        fscanf(routelist," %s", arrivalCity);
        fscanf(routelist," %lf", &speed);
        fscanf(routelist," %d", &time);
        fscanf(routelist," %lf", &distance);

        // String Copy because cant assign strings to new variable. strcpy copies element by element of the array
        strcpy(list[i].departureCity,departureCity);
        strcpy(list[i].arrivalCity,arrivalCity);
        // Here you can assign the values to new variables
        list[i].speed = speed;
        list[i].time = time;
        list[i].distance = distance;
    }

   /* for(int i = 0; i < numberOfRoutes; i++)
    {
        printf("linje = %d %s %s %.2lf %d %.2lf\n",i, list[i].departureCity, list[i].arrivalCity, list[i].speed, list[i].time, list[i].distance);

    }
    printf("----------------\n");
    */
    }

int main() {   /*
    char departureCity[20]; // Assigning amount of characters, it did want to scan properly otherwise
    char arrivalCity[20]; //                           --||--
    interface(departureCity, arrivalCity); // We have added the interface function to a h file, and then we can call interface
                                             // the same way we would call a strcmp or strlen
     */
    // Important to change working directory every time you run program
    FILE *flightDistances = fopen("FlightDistances.txt", "r");
    FILE *interCityCPHSDG = fopen("IC CPH SDG.txt", "r");
    FILE *interCityLynCPHAAL = fopen("ICL CPH AAL.txt", "r");
    FILE *interCityLynCPHSDG = fopen("ICL CPH SDG.txt", "r");
    FILE *interCityCPHAAL = fopen("InterCity CPH AAL.txt", "r");

    routeIntervals routeInfo1[100];
    routeIntervals routeInfo2[100];
    routeIntervals routeInfo3[100];
    routeIntervals routeInfo4[100];


    readRouteFromFiles(routeInfo1, 7, interCityLynCPHSDG);
    readRouteFromFiles(routeInfo2, 10, interCityLynCPHAAL);
    readRouteFromFiles(routeInfo3, 14, interCityCPHAAL);
    readRouteFromFiles(routeInfo4, 11, interCityCPHSDG);

    // listOfList[4]={routeIntervals ro
    //uteInfo1[100],routeInfo2,routeInfo3,routeInfo4};

    routeIntervals routeMaster[4][101];
    routeMaster[1][1] = *routeInfo1;
    routeMaster[2][1] = *routeInfo2;
    routeMaster[3][1] = *routeInfo3;

    routeMaster[1][100] = *routeInfo1;
    routeMaster[2][100] = *routeInfo2;
    routeMaster[3][100] = *routeInfo3;

    readRouteFromFiles(&routeMaster[1][1-100], 11, interCityCPHSDG);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 14; ++j) {
            readRouteFromFiles(&routeMaster[i][j], 11, interCityCPHSDG);
        }
    }
    printf("%s", routeMaster[0][5].departureCity);



    //For at kunne bruge flere datatyper i samme array, skal man bruge en void-pointer-Array




    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 1;j++){
            readRouteFromFiles(j, 7, interCityLynCPHSDG);
        }
    }

    fclose(flightDistances);
    fclose(interCityCPHSDG);
    fclose(interCityLynCPHAAL);
    fclose(interCityLynCPHSDG);
    fclose(interCityCPHAAL);
    return 0;
}

