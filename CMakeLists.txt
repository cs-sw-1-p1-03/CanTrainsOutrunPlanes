    cmake_minimum_required(VERSION 3.23)
project(TrainPlaneP1 C)

set(CMAKE_C_STANDARD 99)

add_executable(TrainPlaneP1 main.c interface.h getArrayOfRoutes.h searchRoutes.h emissionCalculator.h transportToNodes.h advancedDetails.h)
