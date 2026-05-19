#ifndef CVECTOR_H
#define CVECTOR_H
#include "header.h"
class CVector
{
    private:
        int n;
        double *p;
    public:
        CVector(int x = 0);
        CVector(const CVector &a);
        ~CVector();
        friend istream &operator>> (istream &is , CVector &a);
        friend ostream &operator<< (ostream &os , CVector a);
        int Getn();
        double operator[](int i) const;
};
#endif
