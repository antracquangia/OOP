#include <iostream>
#include "NgayThangNam.h"
using namespace std;
int main()
{
    NgayThangNam today, tomorrow;
    today.Nhap();
    if (today.CheckNgay() == 0)
    {
        cout<<"Ngay thang nam khong hop le\n";
    }
    else
    {
        tomorrow = today.NgayThangNamTiepTheo();
        cout<<"Ngay thang nam hien tai:  ";
        today.Xuat();
        cout<<"Ngay thang nam tiep theo: ";
        tomorrow.Xuat();
    }
    return 0;
}