/* 
 * File:   TMatrix.h
 * Author: Rafael Gomez
 *
 * Created on September 8, 2015, 8:19 AM
 */

#ifndef TMATRIX_H
#define	TMATRIX_H

class TriMatrix{
    private:
        int col;
        int *arry;
        int **arry2;
    public:
        TriMatrix();
        ~TriMatrix();
        void setCol(int c)
        { col = c; }
        int getCol() const
        { return col; }
        int *filAray(int);
        int **filAray(int *, int);
        void prntAry(int *, int);
        void prntAry(int **, int *, int);
};

#endif	/* TMATRIX_H */

