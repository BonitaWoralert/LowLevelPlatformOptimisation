#include <iostream>
#include "MyObject.h"
#include "StaticClass.h"
#include "MemoryTracker.h"

int main()
{
    MemoryTracker* defaultTracker = (MemoryTracker*)malloc(sizeof(MemoryTracker*));

    //int* newArr = new int[10]; //allocate memory using new
    //int* mallocArr = (int*)malloc(sizeof(int) * 10); //allocate memory using malloc

    //MyObject* object = new MyObject(); //create class using new

    //StaticClass* statics = new StaticClass(); //create class using new

    /*statics->WriteToVector(1);
    statics->WriteToVector(2);
    statics->WriteToVector(3);*/

    //int num = 7;
    //std::cout << "The number is " << num << std::endl;

    //delete[] newArr; //deallocate memory using delete

    //delete[] Arr;

    //free(mallocArr); //deallocate memory using free

    //delete object; //delete class using delete

    // statics; //delete class using delete
    
}