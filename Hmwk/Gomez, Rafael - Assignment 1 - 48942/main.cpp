/*
 * Rafael Gomez
 * Sept 8, 2015
 * Purpose:  Templated Class Tranigular Matrix
*/

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries
#include "TMatrix.h"
#include "TemplateMatrix.h"

//Execution Begins Here
int main(){
    TriMatrix matrix;
    matrix.setCol(10);
    int *array = matrix.filAray(matrix.getCol());
    int **array2 = matrix.filAray(array, matrix.getCol());
    //matrix.prntAry(array, matrix.getCol());
    cout << "Triangular Matrix in Class " << endl;
    matrix.prntAry(array2, array, matrix.getCol());
    cout << "Triangular Matrix template class " << endl;
    TriMatrixT<int> mtrx;
    mtrx.setCol(10);
    int *tArry = mtrx.filAray(mtrx.getCol());
    int **tArry2 = mtrx.filAray(tArry, mtrx.getCol());
    //mtrx.prntAry(tArry, mtrx.getCol());
    mtrx.prntAry(tArry2, tArry, mtrx.getCol());
    return 0;
}
