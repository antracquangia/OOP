#ifndef DonThuc_h
#define DonThuc_h
#include <iostream>
using namespace std;
class DonThuc
{
    private:
        int Heso;
        int Somu;
    public:
        DonThuc();
        ~DonThuc();
        int GetHeso() const;
        void SetHeso(int hs);
        void SetSomu(int sm);
        int TinhX(int x);
        friend istream& operator>>(istream& is, DonThuc& dt);
        friend ostream& operator<<(ostream& os, DonThuc dt);
        DonThuc operator+(const DonThuc& dt);
        DonThuc operator-(const DonThuc& dt);
        
};
#endif
