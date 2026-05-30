#include "LapTrinhVien.h"
// Phương thức thiết lập có tham số mặc định
LapTrinhVien::LapTrinhVien(string mnv , string ht , int t, int sdt, string em, int luongcb, int giothem): NhanVien(mnv, ht, t, sdt, em, luongcb), SoGioThem(giothem)
{
    loai = 1;
}
// Hàm nhập
void LapTrinhVien::Nhap()
{
    NhanVien::Nhap();
    string s;
    while (1)
    {
        cout<<"Nhap vao so gio lam them: ";
        getline(cin,s);
        if (CheckInteger(s))
            break;
        else cout<<"Nhap lai so gio lam them la so int\n";
    }
    SoGioThem = stoi(s);
}
// Hàm xuất
void LapTrinhVien::Xuat()
{
    NhanVien::Xuat();
    cout << setw(13)<< TinhLuong()  <<endl;
}
// Hàm tính lương
long long LapTrinhVien::TinhLuong()
{
    return LuongCoBan + SoGioThem * 200000;
}