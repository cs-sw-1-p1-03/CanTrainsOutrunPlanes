#include "stdio.h"

#define ICLem 56 // (grams of Co2/passenger/kilometer) taken from "DSB årsrapport"
#define ICem 47 // (grams of Co2/passenger/kilometer) taken from "DSB årsrapport"
#define Planeem 222 // An average of (grams/Co2/passenger/kilometer) taken from "SAS årsrapport"
/**
 * Simple function that populates the "totalCO2" field of the arrayOfRoutes.
 * @param routes Takes in the list/array of available routes.
 * @param arrayOfRoutes Takes in a pointer to the array of stops.
 * @param totalRoutes Takes in the total number of Routes.
 */
void co2Multiplier(routeFile_t routes[], route_t arrayOfRoutes[], int totalRoutes) {

    for (int i = 0; i < totalRoutes; ++i)
    {
        if (arrayOfRoutes[i].found == 1)
        {
            if (strcmp(routes[i].typeOfTransport, "IC") == 0)
            {
                arrayOfRoutes[i].totalCO2 = (arrayOfRoutes[i].totalDistance * ICem);
            }
            else if (strcmp(routes[i].typeOfTransport, "ICL") == 0)
            {
                arrayOfRoutes[i].totalCO2 = (arrayOfRoutes[i].totalDistance * ICLem);
            }
            else
            {
                arrayOfRoutes[i].totalCO2 = (arrayOfRoutes[i].totalDistance * Planeem);
            }
        }
    }
}
