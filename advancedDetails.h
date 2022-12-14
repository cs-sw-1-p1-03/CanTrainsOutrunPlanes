/**
 * UI function that prints further details to a given route.
 * @param arrayOfRoutes takes in the entire array of destinations.
 * @param totalRoutes takes in the number of available routes.
 * @param routes takes in the list/array of available routes
 */
void advancedDetails(route_t arrayOfRoutes[], int totalRoutes, routeFile_t routes[] /*, char arrivalCity[], char departureCity[]*/){

    int detail;
    printf("\n\nPress 1 for advanced details otherwise exit");
    scanf("%d",&detail);

    if(detail == 1)
    {
        printf("\n\n                             Advanced details:\n"
               "-------------------------------------------------------------------------------------------------------\n"
               "Travel time for airplanes in Denmark is generally 40 minutes to an hour. \n"
               "This program takes into consideration that it is recommended to arrive 1 hour and 30 minutes \n"
               "before boarding domestic flights and an estimate of 30 minutes to board. \n"
               "Most airports are placed outside the city which means extra transport. \n"
               "______________________________________________________________________________________________________ \n"
               "The following estimates have been used for the CO2 calculations:\n"
               "InterCity train: 47 (grams of Co2/passenger/kilometer) via. DSB aarsraport \n"
               "InterCityLyn train: 56 (grams of Co2/passenger/kilometer) via. DSB aarsraport \n"
               "Airplane: 222 (grams/Co2/passenger/kilometer) via. SAS \n"
               "______________________________________________________________________________________________________ \n"
               "\n");

        for (int i = 0; i < totalRoutes; i++) {
            if (arrayOfRoutes[i].found == 1) {

                printf("type: %s.\n totalTime =  %lf.\n totalDistance =  %lf.\n averageSpeed = %lf\n",
                       routes[i].typeOfTransport,
                       arrayOfRoutes[i].totalTime,
                       arrayOfRoutes[i].totalDistance, arrayOfRoutes[i].averageSpeed);

            }
        }
            printf("\n----------------------------CO2----------------------------------\n");
        for (int i = 0; i < totalRoutes; i++) {
            if (arrayOfRoutes[i].found == 1) {
                if (strcmp(routes[i].typeOfTransport, "IC") == 0) {

                    printf("IC -> ");
                    printf("TOTAL: %.2lf grams CO2 per passenger \n", arrayOfRoutes[i].totalCO2);
                } else if (strcmp(routes[i].typeOfTransport, "ICL") == 0) {

                    printf("ICL -> ");
                    printf("TOTAL: %.2lf grams CO2 per passenger \n", arrayOfRoutes[i].totalCO2);
                } else {

                    printf("FLIGHT -> ");
                    printf("TOTAL: %.2lf grams CO2 per passenger \n ", arrayOfRoutes[i].totalCO2);
                }
            }
        }
    }
    else{
        EXIT_SUCCESS;
    }
}
