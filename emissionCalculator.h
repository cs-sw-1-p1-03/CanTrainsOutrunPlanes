#include "stdio.h"

#define ICLem 56 // (grams of Co2/passenger/kilometer) taken from "DSB årsrapport"
#define ICem 47 // (grams of Co2/passenger/kilometer) taken from "DSB årsrapport"
#define Planeem 222 // An average of (grams/Co2/passenger/kilometer) taken from "SAS årsrapport"

void co2Multiplier(route_t routes[], list_t arrayOfRoutes[],int totalRoutes) {


    for (int i = 0; i < totalRoutes; ++i)
    {

        if (arrayOfRoutes[i].found == 1)
        {
            if (strcmp(routes[i].typeOfTransport, "IC") == 0)
            {
                arrayOfRoutes[i].totalCO2 = (arrayOfRoutes[i].totalDistance * ICem);
                printf("IC -> ");
                printf("TOTAL: %.2lf grams CO2 per passenger \n", arrayOfRoutes[i].totalCO2);
            }
            else if (strcmp(routes[i].typeOfTransport, "ICL") == 0)
            {
                arrayOfRoutes[i].totalCO2 = (arrayOfRoutes[i].totalDistance * ICLem);
                printf("ICL -> ");
                printf("TOTAL: %.2lf grams CO2 per passenger \n", arrayOfRoutes[i].totalCO2);
            }
            else
            {
                arrayOfRoutes[i].totalCO2 = (arrayOfRoutes[i].totalDistance * Planeem);
                printf("FLIGHT -> ");
                printf("TOTAL: %.2lf grams CO2 per passenger \n ", arrayOfRoutes[i].totalCO2);
            }
        }
    }
}
