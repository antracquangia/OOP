#include "SanXuat.h"
// Phương thức thiết lập có tham số mặc định
SanXuat::SanXuat(string ten, int ngay, int thang, int nam, long long lcb, int sosp): NhanVien (ten, ngay, thang, nam)
{
    LuongCB = lcb;
    SoSanPham = sosp;
}
// Hàm nhập
void SanXuat::Nhap()
{
    NhanVien::Nhap();
    string s;
    while (1){
        cout<<"Luong can ban: ";
        getline(cin,s);
        if (CheckInt(s)) break;
        else cout<<"Luong can ban phai la so nguyen\n";
    }
    LuongCB = stoll(s);
    while (1)
    {
        cout<<"So san pham: ";
        getline(cin,s);
        if (CheckInt(s) ) break;
        else cout<<"So san pham phai la so nguyen\n";
    }
    SoSanPham = stoi(s);
    loai = 1;
}
// Hàm tính lương
void SanXuat::TinhLuong()
{
    Luong = LuongCB + SoSanPham * 5000;
}