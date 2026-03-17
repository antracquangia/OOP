#include <iostream>
using namespace std;
struct PhanSo
{
    int TuSo, MauSo;
};
void Input(PhanSo &ps) //Hàm nhập phân số (mẫu số khác 0)
{
    int a,b;
    cout<<"Nhap vao tu so: ";
    cin>>a;
    ps.TuSo = a;
    do{
        cout<<"Nhap vao mau so: ";
        cin>>b;
        if (b==0) cout<<"Mau so khong duoc bang 0, vui long nhap lai\n";
    } while (b == 0);
    ps.MauSo = b;
}
void RutGon(PhanSo &ps) //Hàm rút gọn phân số
{
    int a = max(ps.TuSo,ps.MauSo);
    int b = min(ps.TuSo, ps.MauSo);
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    ps.TuSo = ps.TuSo/a;
    ps.MauSo = ps.MauSo/a;
    if (ps.MauSo <0)
    {
        ps.TuSo = -ps.TuSo;
        ps.MauSo = -ps.MauSo;
    }
}
PhanSo Greater(PhanSo a, PhanSo b) //Tìm phân số lớn nhất bằng cách quy đồng mẫu số
{
    long long c = a.TuSo * b.MauSo - b.TuSo*a.MauSo;
    if (c>=0) return a;
    else return b;
}
void Output(PhanSo ps) //Hàm in ra phân số lớn nhất
{
    if (ps.MauSo == 1) cout<<"Phan so lon nhat: "<<ps.TuSo;
    else cout<<"Phan so lon nhat: "<<ps.TuSo<<"/"<<ps.MauSo;
}
int main()
{
    PhanSo a,b,c;
    cout<<"Nhap vao phan so thu 1:\n";
    Input(a);
    cout<<"Nhap vao phan so thu 2:\n";
    Input(b);
    RutGon(a);
    RutGon(b);
    c= Greater(a,b);
    Output(c);
    return 0;
}
