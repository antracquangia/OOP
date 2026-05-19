#ifndef DonThuc_h
#define DonThuc_h
#include "header.h"
using namespace std;
class DonThuc
{
    private:
        double Heso;
        int Somu;
    public:
        DonThuc();
        ~DonThuc();
        double GetHeso() const;
        void SetHeso(double hs);
        void SetSomu(int sm);
        double TinhX(double x);
        friend istream& operator>>(istream& is, DonThuc& dt);
        friend ostream& operator<<(ostream& os, DonThuc dt);
        DonThuc operator+(const DonThuc& dt);
        DonThuc operator-(const DonThuc& dt);
        
};
#endif
