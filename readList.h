void searchRoutes(char arrivalCity[], char departureCity[], list_t listOfList[], int totalRoutes)
{
    route_t routes[totalRoutes]; //Creating an empty array of routes
    routesFilesOpen(routes); //Filling it up

    // starting at -1 because our list elements start at 0. Starting at allows element at line 0 to be included
    int departureIndex = -1;
    int arrivalIndex = -1;

    //Making sure that no list is found before we start searching.
    for (int i = 0; i < totalRoutes; i++) {
        listOfList[i].found = 0;
    }

    for (int i = 0; i < totalRoutes; i++) {
        listOfList[i].totalTime = 0;
        listOfList[i].totalDistance = 0;
        listOfList[i].averageSpeed = 0;
    }

    for (int i = 0; i < 1; i++) {
        for (int j = 0; j < routes[i].length; j++) { //for every line
            if (strcmp(listOfList[i].list[j].departureCity, departureCity) == 0 && strcmp(listOfList[i].list[j].arrivalCity, arrivalCity) == 0 ) {
                listOfList[i].found = 1;
                departureIndex = j; arrivalIndex = j; // checks that it is true for both departure and arrival before moving on with calculations
            }
        }

            listOfList[i].totalTime = listOfList[i].list[departureIndex].time;
            // Accumulating the distance of all stops along the way, to determine the length of the route
            listOfList[i].totalDistance = listOfList[i].list[departureIndex].distance;

            listOfList[i].averageSpeed = (listOfList[i].totalDistance / (listOfList[i].totalTime / 60));

        printf("index %d and %d: ", departureIndex, arrivalIndex); //Printing of index for debugging purposes

        printf("list: %d. totalTime =  %lf | totalDistance =  %lf | averageSpeed = %lf\n", i,
               listOfList[i].totalTime,
               listOfList[i].totalDistance, listOfList[i].averageSpeed);
        departureIndex = -1;
        arrivalIndex = -1;
    }


        for (int i = 1; i < totalRoutes; i++) {           //for every list
            for (int j = 0; j < routes[i].length; j++) { //for every line
                if (strcmp(listOfList[i].list[j].departureCity, departureCity) == 0) {
                    departureIndex = j;
                }
                if (strcmp(listOfList[i].list[j].arrivalCity, arrivalCity) == 0) {
                    arrivalIndex = j;
                }
            }


            if (departureIndex >= 0 && arrivalIndex >= 0) {
                listOfList[i].found = 1;
                // Adding parameters to the following struct to store information of the different stuff
                if (departureIndex > arrivalIndex) {
                    // Then the list is upwards
                    for (int k = departureIndex - 1; k > arrivalIndex + 0; k--) {
                        // Adding all the time, saved from the list
                        listOfList[i].totalTime += listOfList[i].list[k].time;
                        // Accumulating the distance of all stops along the way, to determine the length of the route
                        listOfList[i].totalDistance += listOfList[i].list[k].distance;

                    }
                    listOfList[i].averageSpeed = (listOfList[i].totalDistance / (listOfList[i].totalTime / 60));
                } else {
                    // list is read downwards
                    for (int p = departureIndex; p < arrivalIndex + 1; p++) {
                        //Adding all the time, saved from the list
                        listOfList[i].totalTime += listOfList[i].list[p].time;
                        // Accumulating the distance of all stops along the way, to determine the length of the route
                        listOfList[i].totalDistance += listOfList[i].list[p].distance;
                    }
                    // Calculating the average speed across the given route
                    listOfList[i].averageSpeed = (listOfList[i].totalDistance / (listOfList[i].totalTime / 60));
                }
            }


            printf("index %d and %d: ", departureIndex, arrivalIndex); //Printing of index for debugging purposes

            printf("list: %d. totalTime =  %lf | totalDistance =  %lf | averageSpeed = %lf\n", i,
                   listOfList[i].totalTime,
                   listOfList[i].totalDistance, listOfList[i].averageSpeed);
            // Resetting so Indexes are no longer equal to j
            departureIndex = -1;
            arrivalIndex = -1;
        }
    }
