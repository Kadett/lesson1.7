#pragma once
#include <time.h>
#include <iostream>

namespace MyLib{

    struct PositiveNegativeResult{
        int negativeNum;
        int positiveNum;
    };

    void initArray(float *arr, int size);

    void printArray(float *arr, int size);

    PositiveNegativeResult PositiveNegativeCount(float *arr, int size);


}