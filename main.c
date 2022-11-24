#include <stdio.h>
#include <stdlib.h>
#include "distanceFunctionPlane.h"
#include "distanceFunctionTrain.h"
#include "interface.h"

// void since using a char does not allow for multiple returns


int main()
{
    char departureCity[20]; // Assigning amount of characters, it did want to scan properly otherwise
    char arrivalCity[20]; //                           --||--
    interface(departureCity, arrivalCity); // We have added the interface function to a h file, and then we can call interface
                                             // the same way we woulc call a strcmp or strlen


    return 0;
}

