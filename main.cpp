#include <iostream>
#include <fstream>
#include <string>
#include "mylib.h"

using namespace std;


//#define TASK_1_5
//#define TASK_2
//#define TASK_3
//#define TASK_4

#ifdef TASK_1_5
#define SIZE_FLOAT_ARRAY 10
#endif

#ifdef TASK_2
#define MyFunc(x, y) ((x >= 0 && x < y) ? true : false) // TASK 1(5)
#endif

#ifdef TASK_3
#define SwapINT(a, b) int tmp; tmp = a; a = b; b = tmp //TASK 3
#define SIZE_INT_ARRAY 10
#endif


#ifdef TASK_3
void initIntArray(int * arr, int size);
void sortBubble(int * arr, int size);
#endif

#ifdef TASK_4
#pragma pack(push, 1)

struct Employee {
    uint32_t age{};
    string firstName;
    string lastName;
    uint32_t salary{};
};
#pragma pack(pop)

void writeStructEmployee(Employee *emp){
    ofstream fout("Employee.txt", ios_base::binary);
    if(fout.is_open()){
        fout.write((char*)emp, sizeof((*emp)));
        fout.close();
    }
}
Employee readStructEmployee(){
    ifstream fin("Employee.txt", ios_base::binary);
    Employee emp1 = {};
    if(fin.is_open()){
        fin.read((char*)&emp1, sizeof(emp1));
        fin.close();
    }
    return emp1;
}

void printStructEmployee(Employee * emp){
    cout << "age = " << emp->age << endl;
    cout << "firstName = " << emp->firstName << endl;
    cout << "lastName = " << emp->lastName << endl;
    cout << "salary = " << emp->salary << endl;
}

#endif


int main() {
#ifdef TASK_1_5
    float arr[SIZE_FLOAT_ARRAY];
    MyLib::initArray(arr, SIZE_FLOAT_ARRAY);
    MyLib::printArray(arr, SIZE_FLOAT_ARRAY);
    MyLib::PositiveNegativeResult res = MyLib::PositiveNegativeCount(arr, SIZE_FLOAT_ARRAY);
    cout << "Positive = " << res.positiveNum << "; Negative = " << res.negativeNum << endl;
#endif

#ifdef TASK_2
    int num1, num2;
    cout << "enter two numbers:\n";
    cin >> num1 >> num2;
    cout << (MyFunc(num1, num2)? "true" : "false") << endl;
#endif

#ifdef TASK_3
    int arrInt[SIZE_INT_ARRAY] = {0};
    initIntArray(arrInt, SIZE_INT_ARRAY);
    sortBubble(arrInt, SIZE_INT_ARRAY);
#endif

#ifdef TASK_4
    auto *emp = new Employee;
    emp->age = 30;
    emp->firstName = "Bob";
    emp->lastName = "Smith";
    emp->salary = 100000;
    cout << sizeof(*emp) << endl;
    printStructEmployee(emp);
    writeStructEmployee(emp);
    delete emp;

#endif

    return 0;
}


#ifdef TASK_3
void initIntArray(int * arr, const int size){
    cout << "enter " << size << " numbers" << endl;
    for (int k = 0; k < size; ++k) {
        cin >> arr[k];
    }
}
void sortBubble(int * arr, const int size){
    for(int i = 0; i < size - 1; ++i){
        for (int j = 0; j < size - i - 1; ++j) {
            if(arr[j] > arr[j + 1]) {
                SwapINT(arr[j], arr[j + 1]);
            }
        }
    }
}
#endif