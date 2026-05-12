#include "header.h"
#include "CTime.h"
// Phương thức thiết lập mặc định có tham số
CTime::CTime(int gio, int phut, int giay)
{
    iGio = gio;
    iPhut = phut;
    iGiay = giay;
}
// Toán tử cộng
CTime CTime::operator+(int giay)
{
    CTime ans = *this;
    long long time = ans.iGio * 3600 + ans.iPhut * 60 + ans.iGiay + giay;
    time = time % 86400;
    ans.iGio = time / 3600;
    time = time % 3600;
    ans.iPhut = time / 60;
    time = time % 60;
    ans.iGiay = time; 
    return ans;
}
// Toán tử trừ
CTime CTime::operator-(int giay)
{
    CTime ans = *this;
    long long time = ans.iGio * 3600 + ans.iPhut * 60 + ans.iGiay - giay;
    while (time < 0)
    time = time + 86400;
    ans.iGio = time / 3600;
    time = time % 3600;
    ans.iPhut = time / 60;
    time = time % 60;
    ans.iGiay = time; 
    return ans;
}
// Toán tử ++ prefix
CTime CTime::operator++()
{
    *this = operator+(1);
    return *this;
}
// Toán tử ++ postfix
CTime CTime::operator++(int k)
{
    CTime temp = *this;
    *this = operator+(1);
    return temp;
}
// Toán tử -- prefix
CTime CTime::operator--()
{
    *this = operator-(1);
    return *this;
}
// Toán tử -- postfix
CTime CTime::operator--(int k)
{
    CTime temp = *this;
    *this = operator-(1);
    return temp;
}
// Toán tử nhập
istream &operator>> (istream &is, CTime &t)
{
    string s;
    while (1)
    {
        cout<<"Nhap vao so gio: ";
        getline(is,s);
        if (CheckInt(s) && stoi (s) >= 0 && stoi(s) <= 23) break;
        else cout<<"So gio phai la so nguyen tu 0 den 23\n";
    }
    t.iGio = stoi(s);
    while (1)
    {
        cout<<"Nhap vao so phut: ";
        getline(is,s);
        if (CheckInt(s)&& stoi (s) >= 0 && stoi(s) <= 59) break;
        else cout<<"So phut phai la so nguyen tu 0 den 59\n";
    }
    t.iPhut = stoi(s);
    while (1)
    {
        cout<<"Nhap vao so giay: ";
        getline(is,s);
        if (CheckInt(s)&& stoi (s) >= 0 && stoi(s) <= 59) break;
        else cout<<"So giay phai la so nguyen tu 0 den 59\n";
    }
    t.iGiay = stoi(s);
    return is;
}
// Toán tử xuất
ostream &operator<< (ostream &os, CTime t)
{
    if (t.iGio < 10) os<<0;
    os<<t.iGio<<":";
    if (t.iPhut < 10) os<<0;
    os<<t.iPhut<<":";
    if (t.iGiay < 10) os<<0;
    os<<t.iGiay;
    return os;
}