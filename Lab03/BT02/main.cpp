#include "DaGiac.h"
#include <iostream>
using namespace std;
int main()
{
    DaGiac d;
    cout<<"Nhap vao thong tin da giac\n";
    d.Nhap();
    int check = d.KiemtraDaGiac();
    if (!check)
    {
        cout<<"Day khong phai la da giac\n";
        return 0;
    }
    if (check == 1)
        cout<<"Day la da giac phuc\n";
    else cout<<"Day la da giac loi\n";
    cout<<"Thong tin cua da giac luc dau:\n";
    d.Xuat();
    double chuvi = d.TinhChuVi();
    cout<<"Chu vi da giac: "<<chuvi<<endl;
    if (check == 1)
        cout<<"Khong the tinh duoc dien tich da giac phuc\n";
    else
    {
        double dientich = d.TinhDienTich();
        cout<<"Dien tich da giac: "<<dientich<<endl;
    }
    DaGiac tinhtien = d.TinhTien();
    cout<<"Thong tin cua da giac sau khi tinh tien:\n";
    tinhtien.Xuat();
    DaGiac quay = d.Quay();
    cout<<"Thong tin cua da giac sau khi quay:\n";
    quay.Xuat();
    DaGiac phongto = d.PhongTo();
    cout<<"Thong tin cua da giac sau khi phong to:\n";
    phongto.Xuat();
    DaGiac thunho = d.ThuNho();
    cout<<"Thong tin cua da giac sau khi thu nho:\n";
    thunho.Xuat();
    return 0;
}