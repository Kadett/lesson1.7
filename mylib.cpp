#include "mylib.h"


namespace MyLib {


    void initArray(float *arr, const int size) {
        srand(time(0));
        for (int i = 0; i < size; ++i) {
            arr[i] = ((float) (rand() % 10000) / (rand() % 100));
        }
    }


    void printArray(float *arr, const int size) {
        for (int i = 0; i < size; ++i) {
            if (!(i % 10)) std::cout << std::endl;
            std::cout << arr[i] << " ";
        }
    }


    PositiveNegativeResult PositiveNegativeCount(float *arr, const int size) {
        PositiveNegativeResult res = {0, 0};
        for (int i = 0; i < size; ++i) (arr[i] >= 0) ? res.positiveNum++ : res.negativeNum++;
        return res;
    }
}
