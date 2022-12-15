#include "stdio.h"

#define ICLem 56 // (grams of Co2/passenger/kilometer) taken from "DSB årsrapport"
#define ICem 47 // (grams of Co2/passenger/kilometer) taken from "DSB årsrapport"
#define Planeem 222 // An average of (grams/Co2/passenger/kilometer) taken from "SAS årsrapport"
/**
 * Simple function that populates the "totalCO2" field of the arrayOfRoutes.
 * @param routeFileArray Takes in the list/array of available routeFileArray.
 * @param arrayOfRoutes Takes in a pointer to the array of stops.
 * @param totalRoutes Takes in the total number of Routes.
 */
void co2Multiplier(routeFile_t routeFileArray[], route_t arrayOfRoutes[]) {

    for (int i = 0; i < numberOfRoutes; ++i)
    {
        if (arrayOfRoutes[i].found == 1)
        {
            if (strcmp(routeFileArray[i].typeOfTransport, "IC") == 0)
            {
                arrayOfRoutes[i].totalCO2 = (arrayOfRoutes[i].totalDistance * ICem);
            }
            else if (strcmp(routeFileArray[i].typeOfTransport, "ICL") == 0)
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
