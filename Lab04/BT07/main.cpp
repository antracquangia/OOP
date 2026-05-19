#include "header.h"
#include "CMatrix.h"
int main()
{
    CMatrix a,b;
    cout<<"Nhap vao ma tran A:\n";
    cin>>a;
    cout<<"Ma tran A:\n";
    cout<<a;
    cout<<"Nhap vao ma tran B:\n";
    cin>>b;
    cout<<"Ma tran B:\n";
    cout<<b;
    if (a.Getm() != b.Getm() || a.Getn() != b.Getn())
        cout<<"Khong the thuc hien phep cong, tru giua hai ma tran A va B\n";
    else
    {
        CMatrix c = a + b;
        cout<<"Tong ma tran A va B:\n";
        cout<<c;
        CMatrix d = a - b;
        cout<<"Hieu ma tran A va B:\n";
        cout<<d;
    }
    if (a.Getn() != b.Getm())
        cout<<"Khong the thuc hien phep nhan giua hai ma tran A va B\n";
    else
    {
        CMatrix e = a * b;
        cout<<"Tich ma tran A va B:\n";
        cout<<e;
    }
    CVector v;
    cout<<"Nhap vao vector V:\n";
    cin>>v;
    cout<<"Vector V:\n";
    cout<<v<<endl;
    if (a.Getn() != v.Getn())
        cout<<"Khong the thuc hien phep nhan giua ma tran A va vector V\n";
    else
    {
        CMatrix f = a * v;
        cout<<"Tich ma tran A va vector V:\n";
        cout<<f;
    }
    if (b.Getn() != v.Getn())
        cout<<"Khong the thuc hien phep nhan giua ma tran B va vector V\n";
    else
    {
        CMatrix g = b * v;
        cout<<"Tich ma tran B va vector V:\n";
        cout<<g;
    }
    return 0;
}