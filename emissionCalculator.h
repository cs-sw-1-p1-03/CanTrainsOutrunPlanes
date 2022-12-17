#include "stdio.h"

#define ICLem 56 // (grams of Co2/passenger/kilometer) taken from "DSB årsrapport"
#define ICem 47 // (grams of Co2/passenger/kilometer) taken from "DSB årsrapport"
#define Planeem 222 // An average of (grams/Co2/passenger/kilometer) taken from "SAS årsrapport"
/**
 * Simple function that populates the "totalCO2" field of the arrayOfRoutes.
 * @param arrayOfRoutes An array of the struct route_t from getArrayOfRoutes. Includes totalDistance
 */
void co2Multiplier(route_t arrayOfRoutes[]) {

    for (int i = 0; i < numberOfRoutes; ++i)
    {
        if (arrayOfRoutes[i].found == 1)
        {
            if (strcmp(arrayOfRoutes[i].typeOfTransport, "IC") == 0)
            {
                arrayOfRoutes[i].totalCO2 = (arrayOfRoutes[i].totalDistance * ICem);
            }
            else if (strcmp(arrayOfRoutes[i].typeOfTransport, "ICL") == 0)
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
