#include "header.h"
#include "PhanSo.h"
int main()
{
    PhanSo a;
    int b;
    cout<<"Nhap vao phan so A:\n";
    cin>>a;
    //cin.ignore();
    string s;
    while (1)
    {
        cout<<"Nhap vao so nguyen B: ";
        getline(cin,s);
        if (CheckInt(s)) break;
        else cout<<"B phai la so nguyen\n";
    }
    b = stoi(s);
    if (a > b) cout<< a <<" > "<<b<<endl;
    else if (a < b) cout<< a <<" < "<<b<<endl;
    else cout<< a <<" = "<<b<<endl;
    cout<< a <<" + "<< b <<" = "<< a+b<<endl;
    cout<< a <<" - "<< b <<" = "<< a-b<<endl;
    cout<< b <<" - "<< a <<" = "<< b-a<<endl;
    cout<< a <<" * "<< b <<" = "<< a*b<<endl;
    if (b == 0) cout<<"Khong the thuc hien phep chia voi mau la so nguyen B = 0\n";
    else cout<< a <<" / "<< b <<" = "<< a/b<<endl;
    if (a == 0) cout<<"Khong the thuc hien phep chia voi mau la phan so A = 0\n";
    else cout<< b <<" / "<< a <<" = "<< b/a<<endl;
    return 0;
}