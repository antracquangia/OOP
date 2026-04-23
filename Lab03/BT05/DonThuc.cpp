#include <cmath>
#include "DonThuc.h"
#include <string>
using namespace std;
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

// Hàm kiểm tra chuỗi có dạng int không
bool isInt(const std::string& s)
{
    if (s.empty()) return false;
    // Kiểm tra nếu có dấu âm ở đầu
    int start = (s[0] == '-') ? 1 : 0;
    // Trường hợp chỉ nhập mỗi dấu "-" là sai
    if (start == 1 && s.length() == 1) return false; 
    //Kiểm tra từng kí tự xem có phải là số không
    for (int i = start; i < s.length(); i++) {
        if (s[i] < '0' || s[i] > '9') return false;
    }
    return true;
}
// Toán tử nhập đơn thức
istream &operator>>(istream& is, DonThuc &dt)
{
    string a;
    while (1)
    {
        cout<<"Nhap vao he so phan tu: ";
        getline(cin,a);
        if (isInt(a)) break;
        else cout<<"He so phai la so int\n";
    }
    dt.Heso = stoi(a);
    return is;
}

// Toán tử xuất đơn thức
ostream &operator<<(ostream& os, DonThuc dt)
{
    if (dt.Somu == 0) os<<abs(dt.Heso);
    else if (dt.Somu == 1 && abs(dt.Heso) != 1) os<<abs(dt.Heso)<<"x";
    else if (dt.Somu == 1 && abs(dt.Heso) == 1) os<<"x";
    else if (abs(dt.Heso) == 1) os<<"x^"<<dt.Somu;
    else os <<abs(dt.Heso) <<"x^"<<dt.Somu;
    return os;
}

// Hàm gán số mũ
void DonThuc::SetSomu(int sm)
{
    Somu = sm;
}

// Hàm gán hệ số
void DonThuc::SetHeso(int hs)
{
    Heso = hs;
}

//Hàm tính giá trị đơn thức
int DonThuc::TinhX(int x)
{
    return Heso * pow(x, Somu);
}

// Hàm lấy hệ số
int DonThuc::GetHeso() const
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