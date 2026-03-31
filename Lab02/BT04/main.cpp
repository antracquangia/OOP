#include <iostream>
#include "GioPhutGiay.h"
using namespace std;
int main()
{
    GioPhutGiay now;
    cout<<"Nhap vao gio phut giay hien tai:\n";
    now.Nhap();
    if (now.Check() == 0)
    {
        cout<<"Gio phut giay khong hop le";
        return 0;
    }
    GioPhutGiay then = now.TinhCongThemMotGiay();
    cout<<"Gio phut giay hien tai:     ";
    now.Xuat();
    cout<<"Gio phut giay sau mot giay: ";
    then.Xuat();
    return 0;
}