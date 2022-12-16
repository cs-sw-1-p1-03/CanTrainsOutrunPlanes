/**
 * Searches the array of routeFileArray for the given arrival- and departure city (Both ways).
 * @param arrivalCity The city from where the route starts.
 * @param departureCity The city where the route will end.
 * @param arrayOfRoutes The array that contains all routeFileArray.
 * @param totalRoutes The total amount of routeFileArray available.
 */
void searchRoutes(char arrivalCity[], char departureCity[], route_t arrayOfRoutes[], routeFile_t routeFileArray[])
{

    // starting at -1 because our list elements start at 0. Starting at -1 allows element at line 0 to be included
    int departureIndex = -1;
    int arrivalIndex = -1;
    int flightIndex = -1;

    //Making sure that no list is found before we start searching.

    for (int i = 0; i < numberOfRoutes; i++) {
        arrayOfRoutes[i].totalTime = 0;
        arrayOfRoutes[i].totalDistance = 0;
        arrayOfRoutes[i].averageSpeed = 0;
        arrayOfRoutes[i].found = 0;
    }

    //This for loop is designed for the plane file, which is the spot [0] of arrayOfRoutes.
    for (int i = 0; i < 1; i++) {

        for (int j = 0; j < routeFileArray[i].length; j++) { //for every line
            if ((strcmp(arrayOfRoutes[i].list[j].departureCity, departureCity) == 0 &&
                 strcmp(arrayOfRoutes[i].list[j].arrivalCity, arrivalCity) == 0) ||
                (strcmp(arrayOfRoutes[i].list[j].arrivalCity, departureCity) == 0 && //scans the otherway around becuase an departure can be in the arrival row for plane file.
                 strcmp(arrayOfRoutes[i].list[j].departureCity, arrivalCity) == 0)) {
                arrayOfRoutes[i].found = 1;
                flightIndex = j;
                 // checks that it is true for both departure and arrival before moving on with calculations
            }
        }

        if (arrayOfRoutes[i].found == 1) {
            arrayOfRoutes[i].totalTime = arrayOfRoutes[i].list[flightIndex].time;
            // Accumulating the distance of all stops along the way, to determine the length of the route
            arrayOfRoutes[i].totalDistance = arrayOfRoutes[i].list[flightIndex].distance;

            arrayOfRoutes[i].averageSpeed = (arrayOfRoutes[i].totalDistance / (arrayOfRoutes[i].totalTime / 60));

            //printf("index %d and %d: ", departureIndex, arrivalIndex); //Printing of index for debugging purposes
        }


        departureIndex = -1;
        arrivalIndex = -1;
    }

        for (int i = 1; i < numberOfRoutes; i++) {           //for every list
            for (int j = 0; j < routeFileArray[i].length; j++) { //for every line
                if (strcmp(arrayOfRoutes[i].list[j].departureCity, departureCity) == 0) {
                    departureIndex = j;
                }
                if (strcmp(arrayOfRoutes[i].list[j].arrivalCity, arrivalCity) == 0) {
                    arrivalIndex = j;
                }
            }


            if (departureIndex >= 0 && arrivalIndex >= 0) {
                arrayOfRoutes[i].found = 1;
                // Adding parameters to the following struct to store information of the different stuff
                if (departureIndex > arrivalIndex) {
                    // Then the list is upwards
                    for (int k = departureIndex - 1; k > arrivalIndex + 0; k--) {    //her skal faktoriseres se linje 83-87
                        // Adding all the time, saved from the list
                        arrayOfRoutes[i].totalTime += arrayOfRoutes[i].list[k].time;
                        // Accumulating the distance of all stops along the way, to determine the length of the route
                        arrayOfRoutes[i].totalDistance += arrayOfRoutes[i].list[k].distance;
                    }
                    arrayOfRoutes[i].averageSpeed = (arrayOfRoutes[i].totalDistance /
                                                     (arrayOfRoutes[i].totalTime / 60));
                } else {
                    // list is read downwards
                    for (int p = departureIndex; p < arrivalIndex + 1; p++) {
                        //Adding all the time, saved from the list
                        arrayOfRoutes[i].totalTime += arrayOfRoutes[i].list[p].time;
                        // Accumulating the distance of all stops along the way, to determine the length of the route
                        arrayOfRoutes[i].totalDistance += arrayOfRoutes[i].list[p].distance;
                    }
                    // Calculating the average speed across the given route
                    arrayOfRoutes[i].averageSpeed = (arrayOfRoutes[i].totalDistance /
                                                     (arrayOfRoutes[i].totalTime / 60));
                }


               // printf("index %d and %d: ", departureIndex, arrivalIndex); //Printing of index for debugging purposes
                // Resetting so Indexes are no longer equal to j
            }

            departureIndex = -1;
            arrivalIndex = -1;
        }

    }
