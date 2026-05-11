#ifndef SOPHUC_H
#define SOPHUC_H
#include "header.h"
class SoPhuc
{
    private:
        double dThuc;
        double dAo;
    public:
        SoPhuc();
        SoPhuc (double a, double b);
        SoPhuc (double a);
        friend SoPhuc operator+ (const SoPhuc &a, const SoPhuc &b);
        friend SoPhuc operator- (const SoPhuc &a, const SoPhuc &b);
        friend SoPhuc operator* (const SoPhuc &a, const SoPhuc &b);
        friend SoPhuc operator/ (const SoPhuc &a, const SoPhuc &b);
        bool operator== (const SoPhuc &a);
        bool operator!= (const SoPhuc &a);
        friend istream& operator>> (istream &is, SoPhuc &a);
        friend ostream& operator<< (ostream &os,const SoPhuc &a); 
};
#endif