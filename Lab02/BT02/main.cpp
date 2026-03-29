#include <iostream>
#include "PhanSo.h"
using namespace std;
int main()
{
    PhanSo a, b;
    cout<<"Nhap vao phan so A:\n";
    a.Nhap();
    a.RutGon();
    cout<<"Nhap vao phan so B:\n";
    b.Nhap();
    b.RutGon();
    cout<<"Phan so A:";
    a.Xuat();
    cout<<"Phan so B:";
    b.Xuat();
    PhanSo TONG = a.Tong(b);
    cout<<"Tong hai phan so A va B: ";
    TONG.Xuat();
    PhanSo HIEU = a.Hieu(b);
    cout<<"Hieu hai phan so A va B: ";
    HIEU.Xuat();
    PhanSo TICH = a.Tich(b);
    cout<<"Tich hai phan so A va B: ";
    TICH.Xuat();
    if (b.getMauSo()== 0)
        cout<<"Khong the thuc hien thuong\n";
    else
    {
        PhanSo THUONG = a.Thuong(b);
        cout<<"Thuong hai phan so A va B: ";
        THUONG.Xuat();
    }
    int k = a.SoSanh(b);
    if (k == 1) cout<<"Phan so A lon hon phan so B\n";
    else if (k == -1) cout<<"Phan so B lon hon phan so A\n";
    else cout<<"Hai phan so bang nhau\n";
    return 0;
}