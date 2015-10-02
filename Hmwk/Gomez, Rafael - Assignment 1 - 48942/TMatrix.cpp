/* 
 * File:   TMatrix.h
 * Author: Rafael Gomez
 *
 * Created on September 8, 2015, 8:19 AM
 */

#include <iostream>
#include <cstdlib>

#include "TMatrix.h"

using namespace std;

TriMatrix::TriMatrix(){;}

TriMatrix::~TriMatrix(){
    delete []arry;
    for(int i = 0; i < col; i++){
        delete []arry2[i];
    }
    delete []arry2;
}

int *TriMatrix::filAray(int c){
    arry = new int[c];
    for(int i = 0; i < c; i++){
        arry[i]=i+1;
    }
    return arry;
}

int **TriMatrix::filAray(int *a, int c){
    srand(time(0));
    arry2 = new int*[col];
    for(int i = 0; i < c; i++){
        arry2[i] = new int[a[i]];
    }
    for(int row = 0; row < c; row++){
        for(int cols = 0; cols < a[row]; cols++){
            arry2[row][cols]=rand()%90+10;
        }
    }
    return arry2;
}

void TriMatrix::prntAry(int *a, int c){
    cout << endl;
    for(int i = 0; i < c; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void TriMatrix::prntAry(int **a, int *b, int c){
    cout << endl;
    for(int row = 0; row < c; row++){
        for(int cols = 0; cols < b[row]; cols++){
            cout << a[row][cols] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
