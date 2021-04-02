#include <iostream>
#include "mylib.h"
using namespace std;

#define SIZE_F_ARRAY 100

int main() {

    float arr[SIZE_F_ARRAY];
    MyLib::initArray(arr, SIZE_F_ARRAY);
    MyLib::printArray(arr, SIZE_F_ARRAY);



    return 0;
}


