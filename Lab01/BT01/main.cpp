#include <iostream>
using namespace std;
struct PhanSo
{
    int TuSo, MauSo;
};
void Input(PhanSo &ps) //Nhập vào tử số, mẫu số
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
void RutGon(PhanSo &ps)
{
    int a = max(ps.TuSo,ps.MauSo);
    int b = min(ps.TuSo, ps.MauSo);
    while (b != 0) //Tìm UCLN
    {
        int r = a % b;
        a = b;
        b = r;
    }
    ps.TuSo = ps.TuSo/a; //Rút gọn phân số
    ps.MauSo = ps.MauSo/a;
    if (ps.MauSo <0)
    {
        ps.TuSo = -ps.TuSo;
        ps.MauSo = -ps.MauSo;
    }
}
void Output(PhanSo ps) //Xuất ra phân số
{
    if (ps.MauSo == 1) cout<<"Phan so toi gian: "<<ps.TuSo;
    else cout<<"Phan so toi gian: "<<ps.TuSo<<"/"<<ps.MauSo;
}
int main()
{
    PhanSo ps;
    Input(ps);
    RutGon(ps);
    Output(ps);
    return 0;
}
