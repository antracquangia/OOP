#include "header.h"
#include "CVector.h"
// Phương thức thiết lập có tham số mặc định
CVector::CVector (int x)
{
    n = x;
    p = new double [n];
}
// Phương thức thiết lập sao chép
CVector::CVector (const CVector &a)
{
    n = a.n;
    p = new double [n];
    for(int i = 0; i < n; i++) 
        p[i] = a.p[i];
}

// Phương thức phá hủy
CVector::~CVector()
{
    n = 0;
    if (p != nullptr)
        delete []p;
}

// Toán tử nhập
istream &operator>> (istream &is, CVector &a)
{
    string s;
    while (1)
    {
        cout<<"Nhap vao so phan tu: ";
        getline(is,s);
        if (CheckInt(s) && stoi(s)>=1) break;
        else cout<<"So phan tu phai la so nguyen lon hon hoac bang 1\n";
    }
    a.n = stoi(s);
    a.p = new double [a.n];
    for (int i =0; i< a.n; i++)
    {
        while (1)
        {
            cout<<"Nhap vao gia tri phan tu ["<<i<<"]: ";
            getline(cin,s);
            if (CheckDouble(s)) break;
            else cout<<"Gia tri phan tu ["<<i<<"] phai la so double\n";
        }
        a.p[i] = stod(s);
    } 
    return is;
}
// Toán tử xuất
ostream &operator<< (ostream &os, CVector a)
{
    for (int i =0; i<a.n; i++)
        os<<setw(10) << left <<a.p[i];
    return os;
}
// Phương thức truy xuất
int CVector::Getn()
{
    return n;
}
// Toán tử lấy giá trị
double CVector::operator[] (int i) const
{
    return p[i];
}
