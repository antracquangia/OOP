#ifndef CTIME_H
#define CTIME_H
#include "header.h"
class CTime
{
    private:
        int iGio;
        int iPhut;
        int iGiay;
    public:
        CTime (int gio =0, int phut =0, int giay = 0);
        CTime operator+ (int giay);
        CTime operator- (int giay);
        CTime operator++();
        CTime operator++(int k);
        CTime operator--();
        CTime operator--(int k);
        friend istream &operator>> (istream &is, CTime &t);
        friend ostream &operator<< (ostream &os, CTime t);
};
#endif