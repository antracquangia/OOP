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
        CVector &operator=(const CVector &a); 
        CVector operator+ (const CVector &a);
        CVector operator- (const CVector &a);
        double operator* (const CVector &a);
        friend istream &operator>> (istream &is , CVector &a);
        friend ostream &operator<< (ostream &os , const CVector &a);
        int Getn();
};
#endif
