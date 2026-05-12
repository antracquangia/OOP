#include "header.h"
#include "PhanSo.h"
// Phương thức thiết lập mặc định
PhanSo::PhanSo()
{
    iTu = 0;
    iMau = 0;
}
// Phương thức thiết lập có tham số
PhanSo::PhanSo(int a, int b)
{
    iTu = a;
    iMau = b;
    RutGon();
}
// Hàm rút gọn
void PhanSo::RutGon()
{
    int a = max(iTu, iMau);
    int b = min(iTu, iMau);
    while (b!=0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    iTu = iTu / a;
    iMau = iMau / a;
    if (iMau < 0)
    {
        iTu = -iTu;
        iMau = -iMau;
    }
}
// Toán tử cộng
PhanSo operator+ (const PhanSo &a, const PhanSo &b)
{
    PhanSo ans;
    ans.iTu = a.iTu * b.iMau + b.iTu * a.iMau;
    ans.iMau = a.iMau * b.iMau;
    ans.RutGon();
    return ans;
}
// Toán tử trừ
PhanSo operator- (const PhanSo &a, const PhanSo &b)
{
    PhanSo ans;
    ans.iTu = a.iTu * b.iMau - b.iTu * a.iMau;
    ans.iMau = a.iMau * b.iMau;
    ans.RutGon();
    return ans;
}
// Toán tử nhân
PhanSo operator* (const PhanSo &a, const PhanSo &b)
{
    PhanSo ans;
    ans.iTu = a.iTu * b.iTu;
    ans.iMau = a.iMau * b.iMau;
    ans.RutGon();
    return ans;
}
// Toán tử chia
PhanSo operator/ (const PhanSo &a, const PhanSo &b)
{
    PhanSo ans;
    ans.iTu = a.iTu * b.iMau;
    ans.iMau = a.iMau * b.iTu;
    ans.RutGon();
    return ans;
}
// Toán tử so sánh bằng
bool operator==(const PhanSo &a, const PhanSo &b)
{
    return (a.iTu == b.iTu && a.iMau == b.iMau);
}
// Toán tử so sánh bé hơn
bool operator<(const PhanSo &a, const PhanSo &b)
{
    return (a.iTu * b.iMau < b.iTu * a.iMau);
}
// Toán tử so sánh lớn hơn
bool operator>(const PhanSo &a, const PhanSo &b)
{
    return (a.iTu * b.iMau > b.iTu * a.iMau);
}
// Toán tử nhập
istream &operator>> (istream &is, PhanSo &a)
{
    string s;
    while (1)
    {
        cout<<"Nhap vao tu so: ";
        getline(is,s);
        if (CheckInt(s)) break;
        else cout<<"Tu so phai la so nguyen\n";
    }
    a.iTu = stoi(s);
    while (1)
    {
        cout<<"Nhap vao mau so: ";
        getline(is,s);
        if (CheckInt(s) && stoi(s) != 0) break;
        else cout<<"Mau so phai la so nguyen\n";
    }
    a.iMau = stoi(s);
    a.RutGon();
    return is;
}
// Toán tử xuất
ostream &operator<< (ostream &os, PhanSo a)
{
    if (a.iMau == 1) os<<a.iTu;
    else os<<a.iTu<<"/"<<a.iMau;
    return os;
}