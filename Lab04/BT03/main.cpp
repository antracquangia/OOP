#include "header.h"
#include "CTime.h"
int main()
{
    CTime t;
    cin>>t;
    cout<<"Thoi gian luc dau: "<<t<<endl;
    string s;
    while (1)
    {
        cout<<"Nhap vao so giay cong them: ";
        getline(cin,s);
        if (CheckInt(s) && stoi(s) >= 0) break;
        else cout<<"So giay phai la so nguyen lon hon 0\n";
    }
    int giay = stoi(s);
    CTime a = t + giay;
    cout<<"Thoi gian sau khi cong them "<<giay<<": "<<a<<endl;
    while (1)
    {
        cout<<"Nhap vao so giay tru di: ";
        getline(cin,s);
        if (CheckInt(s)&& stoi(s) >= 0) break;
        else cout<<"So giay phai la so nguyen lon hon 0\n";
    }
    giay = stoi(s);
    CTime b = t - giay;
    cout<<"Thoi gian sau khi tru di "<<giay<<": "<<b<<endl;
    CTime c = ++t;
    cout<<"Thoi gian sau khi thuc hien toan tu ++ prefix: "<<c<<endl;
    cout<<"Thoi gian ban dau la: "<<t<<endl;
    CTime d = t++;
    cout<<"Thoi gian sau khi thuc hien toan tu ++ suffix: "<<d<<endl;
    cout<<"Thoi gian ban dau la: "<<t<<endl;
    CTime e = --t;
    cout<<"Thoi gian sau khi thuc hien toan tu -- prefix: "<<e<<endl;
    cout<<"Thoi gian ban dau la: "<<t<<endl;
    CTime f = t--;
    cout<<"Thoi gian sau khi thuc hien toan tu -- suffix: "<<f<<endl;
    cout<<"Thoi gian ban dau la: "<<t<<endl;
    return 0;
}