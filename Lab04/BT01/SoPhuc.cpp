#include "SoPhuc.h"
#include "header.h"
// Phương thức thiết lập mặc định
SoPhuc::SoPhuc()
{
    dThuc = 0;
    dAo = 0;
}
// Phương thức thiết lập có tham số
SoPhuc::SoPhuc(double a, double b)
{
    dThuc = a;
    dAo = b;
}
// Chuyển kiểu bằng constructor
SoPhuc::SoPhuc(double a)
{
    dThuc = a;
    dAo = 0;
}
// Toán tử cộng
SoPhuc operator+(const SoPhuc &a, const SoPhuc &b)
{
    SoPhuc ans;
    ans.dThuc = a.dThuc + b.dThuc;
    ans.dAo = a.dAo + b.dAo;
    return ans;
}
// Toán tử trừ 
SoPhuc operator-(const SoPhuc &a, const SoPhuc &b)
{
    SoPhuc ans;
    ans.dThuc = a.dThuc - b.dThuc;
    ans.dAo = a.dAo - b.dAo;
    return ans;
}
// Toán tử nhân
SoPhuc operator*(const SoPhuc &a, const SoPhuc &b)
{
    SoPhuc ans;
    ans.dThuc = a.dThuc * b.dThuc - a.dAo * b.dAo;
    ans.dAo = a.dThuc * b.dAo + a.dAo * b.dThuc;
    return ans;
}
// Toán tử chia
SoPhuc operator/(const SoPhuc &a, const SoPhuc &b)
{
    double k = b.dThuc * b.dThuc + b.dAo * b.dAo;
    SoPhuc ans;
    ans.dThuc = (a.dThuc * b.dThuc + a.dAo * b.dAo)/k;
    ans.dAo = (a.dThuc * b.dAo - a.dAo * b.dThuc)/k;
    return ans;
}
// Toán tử so sánh bằng
bool SoPhuc::operator==(const SoPhuc &a)
{
    return (dThuc == a.dThuc && dAo == a.dAo);
}
// Toán tử so sánh khác
bool SoPhuc::operator!=(const SoPhuc &a)
{
    return !operator==(a);
}
istream& operator>> (istream &is, SoPhuc &a)
{
    string s;
    while (1)
    {
        cout<<"Nhap vao phan thuc: ";
        getline(is,s);
        if (CheckDouble(s)) break;
        else cout<<"Phan thuc phai la so double\n";
    }
    a.dThuc = stod(s);
    while (1)
    {
        cout<<"Nhap vao phan ao: ";
        getline(is,s);
        if (CheckDouble(s)) break;
        else cout<<"Phan ao phai la so double\n";
    }
    a.dAo = stod(s);
    return is;
}
ostream& operator<< (ostream &os, const SoPhuc &a)
{
    os << "(" << a.dThuc << ", " << a.dAo << ")";
    return os;
}