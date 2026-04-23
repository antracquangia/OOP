#ifndef DaThuc_h
#define DaThuc_h
#include "DonThuc.h"
class DaThuc
{
    private:
        DonThuc *p;
        int n;
    public:
        DaThuc();
        DaThuc(int n);
        DaThuc(const DaThuc& dat);
        ~DaThuc();
        DaThuc operator=(const DaThuc& dat);
        int TinhX(int x);
        friend istream& operator>>(istream& is, DaThuc& dat);
        friend ostream& operator<<(ostream& os, DaThuc dat);
        DaThuc operator+(const DaThuc& dat);
        DaThuc operator-(const DaThuc& dat);
};
#endif