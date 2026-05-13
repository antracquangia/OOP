#ifndef CDATE_H
#define CDATE_H
#include "header.h"
class CDate
{
    private:
        int iNgay;
        int iThang;
        int iNam;
    public:
        CDate();
        CDate(int ngay, int thang, int nam);
        CDate operator+(int ngay);
        CDate operator-(int ngay);
        CDate operator++();
        CDate operator++(int k);
        CDate operator--();
        CDate operator--(int k);
        long TongNgay();
        friend int operator-(CDate a, CDate b);
        friend istream &operator>> (istream &is, CDate &d);
        friend ostream &operator<< (ostream &os, CDate d);
};
#endif