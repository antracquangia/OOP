#ifndef PHANSO_H
#define PHANSO_H
#include "header.h"
class PhanSo
{
    private:
        int iTu;
        int iMau;
    public:
        PhanSo();
        PhanSo(int a, int b = 1);
        void RutGon();
        friend PhanSo operator+ (const PhanSo &a, const PhanSo &b);
        friend PhanSo operator- (const PhanSo &a, const PhanSo &b);
        friend PhanSo operator* (const PhanSo &a, const PhanSo &b);
        friend PhanSo operator/ (const PhanSo &a, const PhanSo &b);
        friend bool operator== (const PhanSo &a, const PhanSo &b);
        friend bool operator> (const PhanSo &a, const PhanSo &b);
        friend bool operator< (const PhanSo &a, const PhanSo &b);
        friend istream &operator>> (istream &is, PhanSo &a);
        friend ostream &operator<< (ostream &os, PhanSo a);
};
#endif