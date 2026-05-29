#include "VanPhong.h"
// Phương thức thiết lập có tham số mặc định
VanPhong::VanPhong(string ten, int ngay, int thang, int nam, int songay): NhanVien(ten,ngay,thang,nam)
{
    SoNgay = songay;
}
// Hàm nhập
void VanPhong::Nhap()
{
    NhanVien::Nhap();
    string s;
    while (1){
        cout<<"So ngay lam viec: ";
        getline(cin,s);
        if (CheckInt(s)) break;
        else cout<<"So ngay can ban phai la so nguyen\n";
    }
    SoNgay = stoi(s);
    loai = 2;
}
// Hàm tính lương
void VanPhong::TinhLuong()
{
    Luong = SoNgay * 100000;
}