#include "DaThuc.h"
int main()
{
    DaThuc a, b, tong, hieu;
    cout<<"Nhap vao da thuc thu nhat:\n";
    cin>>a;
    cout<<"Da thuc thu nhat la: "<<a<<endl;
    cout<<"Nhap vao da thuc thu hai:\n";
    cin>>b;
    cout<<"Da thuc thu hai la: "<<b<<endl;
    tong = a + b;
    cout<<"Tong hai da thuc la: "<<tong<<endl;
    hieu = a - b;
    cout<<"Hieu hai da thuc la: "<<hieu<<endl;
    int x;
    cout<<"Nhap vao gia tri x: ";
    cin>>x;
    cout<<"Gia tri cua da thuc thu nhat la: "<<a.TinhX(x)<<endl;
    cout<<"Gia tri cua da thuc thu hai la: "<<b.TinhX(x)<<endl;
    cout<<"Gia tri cua da thuc tong la: "<<tong.TinhX(x)<<endl;
    cout<<"Gia tri cua da thuc hieu la: "<<hieu.TinhX(x)<<endl;
    return 0;
}