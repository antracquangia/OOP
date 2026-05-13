#include "header.h"
#include "CDate.h"
int main()
{
    CDate now;
    cin>>now;
    cout<<"Ngay hien tai: "<<now<<endl;
    string s;
    while (1)
        {
            cout<<"Nhap vao so ngay cong them vao: ";
            getline(cin,s);
            if (CheckInt(s) && stoi(s) >= 0) break;
            else cout<<"So ngay phai la so nguyen lon hon hoac bang 0\n";
        }
    int day = stoi(s);
    CDate a = now + day;
    cout<<"Ngay hien tai neu cong them "<<day<<" ngay: "<<a<<endl;
    while (1)
        {
            cout<<"Nhap vao so ngay tru di: ";
            getline(cin,s);
            if (CheckInt(s) && stoi(s) >= 0) break;
            else cout<<"So ngay phai la so nguyen lon hon hoac bang 0\n";
        }
    day = stoi(s);
    CDate b = now - day;
    cout<<"Ngay hien tai neu tru di "<<day<<" ngay: "<<b<<endl;
    CDate k;
    cout<<"Nhap vao mot ngay de tinh toan ngay chenh lech\n";
    cin>>k;
    day = now - k;
    cout<<"So ngay chenh lech la: "<<day<<endl;
    CDate c = ++now;
    cout<<"Ngay hien tai neu thuc hien toan tu ++ prefix: "<<now<<endl;
    cout<<"Ngay cong them neu thuc hien toan tu ++ prefix: "<<c<<endl;
    CDate d = now++;
    cout<<"Ngay hien tai neu thuc hien toan tu ++ postfix: "<<now<<endl;
    cout<<"Ngay cong them neu thuc hien toan tu ++ postfix: "<<d<<endl;
    CDate e = --now;
    cout<<"Ngay hien tai neu thuc hien toan tu -- prefix: "<<now<<endl;
    cout<<"Ngay cong them neu thuc hien toan tu -- prefix: "<<e<<endl;
    CDate f = now--;
    cout<<"Ngay hien tai neu thuc hien toan tu -- postfix: "<<now<<endl;
    cout<<"Ngay cong them neu thuc hien toan tu -- postfix: "<<f<<endl;   
    return 0;
}