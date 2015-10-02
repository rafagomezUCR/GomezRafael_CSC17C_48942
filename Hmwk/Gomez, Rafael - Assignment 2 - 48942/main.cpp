/* 
 * File:   main.cpp
 * Author: Rafael Gomez
 *
 * Created on September 16, 2015, 4:27 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>

#include "SimpleVector++.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int size = 10;
    SimpleVector<int> sv(size);
    for(int i = 0; i < sv.size(); i++){
        sv[i] = i;
    }
    for(int i = 0; i < sv.size(); i++){
        cout << sv[i] << " ";
    }
    cout << endl;
    cout << "Delete last element from vector " << endl;
    sv.pull();
    for(int i = 0; i < sv.size(); i++){
        cout << sv[i] << " ";
    }
    cout << endl;
    cout << "Add one value and double size " << endl;
    sv.push(22);
    for(int i = 0; i < sv.size(); i++){
        cout << sv[i] << " ";
    }
    cout << endl;
    cout << "Size of array " << sv.size();
    return 0;
}

