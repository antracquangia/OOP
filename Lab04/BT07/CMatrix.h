#ifndef CMATRIX_H
#define CMATRIX_H
#include "header.h"
#include "CVector.h"
class CMatrix
{
    private:
        int m,n;
        double **p;
    public:
        CMatrix(int x = 0, int y = 0);
        CMatrix (CVector a);
        CMatrix (const CMatrix &a);
        CMatrix &operator= (const CMatrix &a);
        ~CMatrix();
        CMatrix operator+ (const CMatrix &a);
        CMatrix operator- (const CMatrix &a);
        CMatrix operator* (const CMatrix &a);
        friend istream &operator>> (istream &is, CMatrix &a);
        friend ostream &operator<< (ostream &is, const CMatrix &a);
        int Getm();
        int Getn();        
};
#endif