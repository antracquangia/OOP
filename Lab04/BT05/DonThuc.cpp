#include "header.h"
#include "DonThuc.h"

// Hàm khởi tạo mặc định
DonThuc::DonThuc()
{
    Heso = 0;
    Somu = 0;
}

// Hàm phá hủy
DonThuc::~DonThuc()
{
}

// Toán tử nhập đơn thức
istream &operator>>(istream& is, DonThuc &dt)
{
    string s;
    while (1)
    {
        getline(is,s);
        if (CheckDouble(s)) break;
        else
        {
            cout<<"He so phai la so double\n";
            cout<<"Nhap lai he so: ";
        } 
    }
    dt.Heso = stod(s);
    return is;
}

// Toán tử xuất đơn thức
ostream &operator<<(ostream& os, DonThuc dt)
{
    if (dt.Somu == 0) os << dt.Heso; 
    else if (dt.Heso == 1) os << "x^" << dt.Somu;
    else if (dt.Heso == -1) os << "-x^" << dt.Somu;
    else os << dt.Heso << "*x^" << dt.Somu;
    return os;
}

// Hàm gán số mũ
void DonThuc::SetSomu(int sm)
{
    Somu = sm;
}

// Hàm gán hệ số
void DonThuc::SetHeso(double hs)
{
    Heso = hs;
}

//Hàm tính giá trị đơn thức
double DonThuc::TinhX(double x)
{
    return Heso * pow(x, Somu);
}

// Hàm lấy hệ số
double DonThuc::GetHeso() const
{
    return Heso;
}

// Toán tử cộng hai đơn thức
DonThuc DonThuc::operator+(const DonThuc& dt)
{
    DonThuc tong;
    tong.Heso = Heso + dt.Heso;
    tong.Somu = Somu;
    return tong;
}

// Toán tử trừ hai đơn thức
DonThuc DonThuc::operator-(const DonThuc& dt)
{
    DonThuc hieu;
    hieu.Heso = Heso - dt.Heso;
    hieu.Somu = Somu;
    return hieu;
}