#include "TamGiac.h"
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    TamGiac a;
    a.Nhap();
    int loai = a.KiemtraTamGiac();
    if (loai == 0)
    {
        cout<<"Day khong phai la tam giac\n";
        return 0;
    }
    else if (loai == 1) cout<<"Day la tam giac deu\n";
    else if (loai == 2) cout<<"Day la tam giac can\n";
    else if (loai == 3) cout<<"Day la tam giac vuong\n";
    else if (loai == 4) cout<<"Day la tam giac tu\n";
    else if (loai == 5) cout<<"Day la tam giac nhon\n";
    cout<<"Tam giac luc dau:\n";
    a.Xuat();
    double chuvi = a.TinhChuVi();
    cout << fixed << setprecision(2)<<"Chu vi tam giac: "<<chuvi<<endl;
    double dientich = a.TinhDienTich();
    cout << fixed << setprecision(2)<<"Dien tich tam giac: "<<dientich<<endl;
    TamGiac tinhtien = a.TinhTien();
    cout<<"Tam giac sau khi tinh tien:\n";
    tinhtien.Xuat();
    TamGiac quay = a.Quay();
    cout<<"Tam giac sau khi quay:\n";
    quay.Xuat();
    TamGiac phongto = a.PhongTo();
    cout<<"Tam giac sau khi phong to:\n";
    phongto.Xuat();
    TamGiac thunho = a.ThuNho();
    cout<<"Tam giac sau khi thu nho:\n";
    thunho.Xuat();
    return 0;
}