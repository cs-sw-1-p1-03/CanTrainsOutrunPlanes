#include "stdio.h"

void transportToNodes(list_t arrayOfRoutes[],int totalRoutes,route_t routes[],char arrivalCity[])
{
    char luggage[10];
    char transport[10]; //Initializing a new term for transport to determine whether it is a train or an airplane.
    int distanceFromStation, distanceFromAirport; //Initializing distance to calculate from the different nodes
    printf("\nAre you taking the airplane or train?");
    scanf("%s", transport);
    printf("Type your distance from the train station and the airport in km");
    scanf("%d %d", &distanceFromStation, &distanceFromAirport);
    printf("Are you taking luggage, yes/no");
    scanf("%s", luggage);
    double walkResult, averageWalkSpeed = 5, busResult, averageBusSpeed = 50;
    double busCo2, busEmission = 11; //Assuming based on data that bus emission is 11 grams of CO2 per person km


    // set definitions
    walkResult = (distanceFromStation * 1 / averageWalkSpeed) * 60;
    busResult = (distanceFromStation * 1 / averageBusSpeed) * 60;
    busCo2 = (busEmission * distanceFromStation);


    if (strcmp(transport,"train") == 0 || strcmp(transport,"Train") ==0 )
    {
        printf("\nThis is how long it will take you to get to the train station:\n");
        printf("If you are walking to the train station it will take you -> ");
        printf("%.2lf min.\n", walkResult);
        printf("If you are taking the bus to the train station -> ");
        printf("%.2lf min.\n\n", busResult);
    }

        //In this we calculate the different variables
        for (int i = 0; i < totalRoutes; ++i)
        {
            arrayOfRoutes[i].totalTimeWalk = arrayOfRoutes[i].totalTime + walkResult;
            arrayOfRoutes[i].totalTimeBus = arrayOfRoutes[i].totalTime + busResult;
            arrayOfRoutes[i].totalTravelCO2 = (arrayOfRoutes[i].totalCO2 + busCo2) / 1000;
            
            if (arrayOfRoutes[i].found == 1 && strcmp(routes[i].typeOfTransport,"airplane") != 0 && strcmp(transport,"train") == 0)
            {
                printf("Train type %s to %s. Total: %.2lf minutes with walking distance | Total: %.2lf minutes with bus travel \n"
                       "Total CO2 emission is %.2lf kilograms\n", routes[i].typeOfTransport, arrivalCity,
                       arrayOfRoutes[i].totalTimeWalk,arrayOfRoutes[i].totalTimeBus, arrayOfRoutes[i].totalTravelCO2);
            }
        }
    // user inputs airplane

        int luggageTime = 22; //Average time spent in the airport to claim luggage
        int boardingTime = 90; //Average time spent in the airport to board and go through security

        if (strcmp(luggage,"yes") == 0)
        {
            luggageTime = 22;
        }
        else if(strcmp(luggage, "no") == 0)
        {
            luggageTime = 0;
        }

        walkResult = (distanceFromAirport * 1 / averageWalkSpeed) * 60;
        busResult = (distanceFromAirport * 1 / averageBusSpeed) * 60;
        busCo2 = (busEmission * distanceFromStation);

        if (strcmp(transport,"airplane") == 0)
        {
            printf("\nThis is how long it will take you to get to the Airport:\n");
            printf("If you are walking to the airplane it will take you -> ");
            printf("%.2lf min\n", walkResult);
            printf("If you are taking the bus to the airplane -> ");
            printf("%.2lf min\n", busResult);
        }

        //In this we calculate the different variables
        for (int i = 0; i < totalRoutes; ++i)
        {
            arrayOfRoutes[i].totalTimeWalk = arrayOfRoutes[i].totalTime + walkResult + boardingTime + luggageTime;
            arrayOfRoutes[i].totalTimeBus = arrayOfRoutes[i].totalTime + busResult + boardingTime + luggageTime;
            arrayOfRoutes[i].totalTravelCO2 = (arrayOfRoutes[i].totalCO2 + busCo2) / 1000;

            if (arrayOfRoutes[i].found == 1 && strcmp(routes[i].typeOfTransport,"airplane") == 0 && strcmp(transport,"airplane")==0 )
            {
                printf("Airplane to %s. Total: %.2lf minutes with walking distance | Total: %.2lf minutes with bus travel \n"
                       "Total CO2 emission is %.2lf kilograms\n", arrivalCity,
                       arrayOfRoutes[i].totalTimeWalk, arrayOfRoutes[i].totalTimeBus, arrayOfRoutes[i].totalTravelCO2);
            }
        }

        for (int i = 0; i < totalRoutes;i++)
        {
            double comparedCO2Result, comparedSpeedResult;
            int indexForAirplane;

            if(arrayOfRoutes[i].found == 1 && strcmp(routes[i].typeOfTransport,"airplane") == 0)
            {
                indexForAirplane = i;
            }
            if(arrayOfRoutes[i].found == 1 && strcmp(routes[i].typeOfTransport,"airplane") != 0)
            {

                if (strcmp(transport,"airplane") == 0 || strcmp(transport,"Airplane") == 0 )
                {
                    comparedCO2Result = arrayOfRoutes[indexForAirplane].totalTravelCO2 - arrayOfRoutes[i].totalTravelCO2;
                    
                    printf("If you take the train %s you would save %.2lf kilograms CO2\n",routes[i].typeOfTransport,comparedCO2Result);
                }
                if (strcmp(transport,"train") == 0 || strcmp(transport,"Train") == 0 )
                {
                    comparedCO2Result =  arrayOfRoutes[indexForAirplane].totalTravelCO2 -arrayOfRoutes[i].totalTravelCO2;
                    printf("If you take the airplane it would use %.2lf more kilograms of CO2 compared to %s train \n",comparedCO2Result,routes[i].typeOfTransport);
                }
            }
        }
}