#include <iostream>
using namespace std;
struct PhanSo
{
    long long TuSo, MauSo;
};
void Input(PhanSo &ps) //Hàm nhập phân số
{
    long long a,b;
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
PhanSo Tong(PhanSo a, PhanSo b) //Hàm tính tổng
{
    PhanSo c;
    c.MauSo = a.MauSo * b.MauSo;
    c.TuSo = a.TuSo * b.MauSo + b.TuSo * a.MauSo;
    RutGon(c);
    return c;
}
PhanSo Hieu(PhanSo a, PhanSo b) //Hàm tính hiệu
{
    PhanSo c;
    c.MauSo = a.MauSo * b.MauSo;
    c.TuSo = a.TuSo * b.MauSo - b.TuSo * a.MauSo;
    RutGon(c);
    return c;
}
PhanSo Tich (PhanSo a, PhanSo b) //Hàm tính tích
{
    PhanSo c;
    c.MauSo = a.MauSo * b.MauSo;
    c.TuSo = a.TuSo * b.TuSo;
    RutGon(c);
    return c;
}
bool flag = 1;
PhanSo Thuong (PhanSo a, PhanSo b) //Hàm tính thương, nếu mẫu số phân số thứ 2 = 0 thì không thực hiện phép chia
{
    PhanSo c;
    if (b.TuSo == 0)
    {
        cout<<"Khong the thuc hien phep chia";
        flag = 0;
        return c;
    }
    else
    {
        c.TuSo = a.TuSo * b.MauSo;
        c.MauSo = a.MauSo * b.TuSo;
        RutGon(c);
        return c;
    }
}
void Output(PhanSo ps) //Hàm in ra phân số
{
    if (flag == 0) return;
    if (ps.MauSo == 1) cout<<ps.TuSo;
    else cout<<ps.TuSo<<"/"<<ps.MauSo;
}
int main()
{
    PhanSo a,b,tong,hieu,tich,thuong;
    cout<<"Nhap vao phan so thu 1:\n";
    Input(a);
    cout<<"Nhap vao phan so thu 2:\n";
    Input(b);
    RutGon(a);
    RutGon(b);
    tong = Tong(a,b);
    cout<<"Tong: ";
    Output(tong);
    cout<<"\n";
    hieu = Hieu(a,b);
    cout<<"Hieu: ";
    Output(hieu);
    cout<<"\n";
    tich = Tich(a,b);
    cout<<"Tich: ";
    Output (tich);
    cout<<"\n";
    thuong = Thuong(a,b);
    cout<<"Thuong: ";
    Output (thuong);
    return 0;
}
