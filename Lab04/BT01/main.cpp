#include "header.h"
#include "SoPhuc.h"
int main()
{
    cout<<fixed<<setprecision(4);
    SoPhuc a;
    double b;
    cin>>a;
    string s;
    while (1)
    {
        cout<<"Nhap vao so thuc: ";
        getline(cin,s);
        if (CheckDouble(s)) break;
        else cout<<"Phai la so double\n";
    }
    b = stod(s);
    cout<<a<<" + "<< b<<" = "<< a+b<<endl;
    cout<<a<<" - "<< b<<" = "<< a-b<<endl;
    cout<<b<<" - "<< a<<" = "<< b-a<<endl;
    cout<<a<<" * "<< b<<" = "<< a*b<<endl;
    if (b == 0)
        cout<<"Khong the thuc hien phep chia voi mau la so thuc bang 0\n";
    else 
        cout<< a<<" / "<< b<<" = "<< a/b<<endl;
    if (a != 0)
        cout<< b<<" / "<< a<<" = "<< b/a<<endl;
    else cout<<"Khong the thuc hien phep chia voi mau la so phuc bang 0\n";
    return 0;
}