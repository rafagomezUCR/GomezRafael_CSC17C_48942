/* 
 * File:   TemplateMatrix.h
 * Author: User
 *
 * Created on September 9, 2015, 10:23 AM
 */

#ifndef TEMPLATEMATRIX_H
#define	TEMPLATEMATRIX_H

#include <iostream>
#include <cstdlib>

using namespace std;

template <class T>
class TriMatrixT{
    private:
        int col;
        T *arry;
        T **arry2;
    public:
        TriMatrixT();
        ~TriMatrixT();
        void setCol(int c)
        { col = c; }
        int getCol() const
        { return col; }
        T *filAray(int);
        T **filAray(T *, int);
        void prntAry(T *, int);
        void prntAry(T **, T *, int);
};

template <class T>
TriMatrixT<T>::TriMatrixT(){;}

template <class T>
TriMatrixT<T>::~TriMatrixT(){
    delete []arry;
    for(int i = 0; i < col; i++){
        delete []arry2[i];
    }
    delete []arry2;
}

template <class T>
T *TriMatrixT<T>::filAray(int c){
    arry = new T[c];
    for(int i = 0; i < c; i++){
        arry[i]=i+1;
    }
    return arry;
}

template <class T>
T **TriMatrixT<T>::filAray(T *a, int c){
    srand(time(0));
    arry2 = new T*[col];
    for(int i = 0; i < c; i++){
        arry2[i] = new T[a[i]];
    }
    for(int row = 0; row < c; row++){
        for(int cols = 0; cols < a[row]; cols++){
            arry2[row][cols]=rand()%90+10;
        }
    }
    return arry2;
}

template <class T>
void TriMatrixT<T>::prntAry(T *a, int c){
    cout << endl;
    for(int i = 0; i < c; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

template <class T>
void TriMatrixT<T>::prntAry(T **a, T *b, int c){
    cout << endl;
    for(int row = 0; row < c; row++){
        for(int cols = 0; cols < b[row]; cols++){
            cout << a[row][cols] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

#endif	/* TEMPLATEMATRIX_H */

