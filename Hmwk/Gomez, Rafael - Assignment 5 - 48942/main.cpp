/* 
 * File:   main.cpp
 * Author: Rafael Gomez
 *
 * Created on October 8, 2015, 5:30 PM
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
    for(int i = 0; i < v.size(); i++){
        v[i] = rand()%90+10;
    }
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl << v.getElement(5) << endl;
    v.append(100);
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl << "Pulled out last item in list " << endl;
    v.pull();
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl << v.first() << endl;
    cout << v.last() << endl;
    v.prepend(1);
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    SimpleList<int> a(v.size());
    a.operator =(v);
    cout << endl;
    for(int i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    }
    return 0;
}

