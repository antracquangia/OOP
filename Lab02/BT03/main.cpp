#include <iostream>
#include "SoPhuc.h"
using namespace std;
int main()
{
    SoPhuc a, b;
    cout<<"Nhap vao so phuc A:\n";
    a.Nhap();
    cout<<"Nhap vao so phuc B:\n";
    b.Nhap();
    cout<<"So phuc A: ";
    a.Xuat();
    cout<<"So phuc B: ";
    b.Xuat();
    SoPhuc TONG = a.Tong(b);
    cout<<"Tong hai so phuc A va B: ";
    TONG.Xuat();
    SoPhuc HIEU = a.Hieu(b);
    cout<<"Hieu hai so phuc A va B: ";
    HIEU.Xuat();
    SoPhuc TICH = a.Tich(b);
    cout<<"Tich hai so phuc A va B: ";
    TICH.Xuat();
    if (b.getThuc() == 0 && b.getAo() == 0)
        cout<<"Khong the thuc hien thuong\n";
    else
    {
        SoPhuc THUONG = a.Thuong(b);
        cout<<"Thuong hai so phuc A va B: ";
        THUONG.Xuat();
    }
    return 0;
}