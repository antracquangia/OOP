#ifndef DaThuc_h
#define DaThuc_h
#include "DonThuc.h"
#include "header.h"
class DaThuc : public DonThuc
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
        double TinhX(double x);
        friend istream& operator>>(istream& is, DaThuc& dat);
        friend ostream& operator<<(ostream& os, DaThuc dat);
        DaThuc operator+(const DaThuc& dat);
        DaThuc operator-(const DaThuc& dat);
};
#endif