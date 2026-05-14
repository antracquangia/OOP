#include "header.h"
#include "CVector.h"
int main()
{
    CVector a,b;
    cout<<fixed<<setprecision(2);
    cout<<"Nhap vao vector A:\n";
    cin>>a;
    cout<<"Nhap vao vector B:\n";
    cin>>b;
    if (a.Getn() != b.Getn())
        cout<<"Hai vector co so chieu khac nhau khong the thuc hien phep tinh";
    else
    {
        CVector c = a + b;
        cout<<a<<" + "<<b<<" = "<<c<<endl;
        CVector d = a - b;
        cout<<a<<" - "<<b<<" = "<<d<<endl;
        double e = a * b;
        cout<<a<<" * "<<b<<" = "<<e<<endl;
    }
    return 0;
}