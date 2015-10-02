/* 
 * File:   main.cpp
 * Author: User
 *
 * Created on September 27, 2015, 12:48 PM
 */

#include <cstdlib>
#include <iostream>
#include "VectorList.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    srand(time(0));
    int size = 6;
    SimpleList<int> v(size);
    for(int i = 0; i < size; i++){
        v[i] = rand()%90+10;
    }
    for(int i = 0; i < size; i++){
        cout << v[i] << " ";
    }
    cout << endl << v.getElement(5) << endl;
    v.push(100), size++;
    for(int i = 0; i < size; i++){
        cout << v[i] << " ";
    }
    return 0;
}

