
// -------------Concept that turned out to be difficult, will be solved easier way, this will be explored if enough time ----

#include "stdio.h"
#include "getArrayOfRoutes.h"
#include "searchRoutes.h"

#define ICLem 56 // (grams of Co2/passenger/kilometer) taken from "DSB årsrapport"
#define ICem 47 // (grams of Co2/passenger/kilometer) taken from "DSB årsrapport"
#define Planeem 111 // An average of (grams/Co2/passenger/kilometer) taken from "SAS årsrapport"





void co2Multiplier(route_t routes[], list_t arrayOfRoutes[],int totalRoutes) {

    double emPlane, emIC, emICL;


    int SW;
    for (int i = 0; i < totalRoutes; ++i) {


        if (strcmp(routes[i].typeOfTransport, "IC") == 0) {
            emIC = (arrayOfRoutes[i].totalDistance * ICem);
            printf("IC type of transport\n");
            printf("TOTAL: %lf",emIC);
        } else if (strcmp(routes[i].typeOfTransport, "ICL") == 0) {
            emICL = (arrayOfRoutes[i].totalDistance * ICLem);
            printf("BEN BEN BEN ICL \n");
            printf("TOTAL: %lf",emICL);
        } else {
            emPlane = (arrayOfRoutes[i].totalDistance * Planeem);
            printf("BEN BEN BEN FLIGHT\n");
            printf("TOTAL: %lf",emPlane);
        }
    }
}
