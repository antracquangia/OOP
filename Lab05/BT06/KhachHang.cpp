#include "KhachHang.h"
// Phương thức thiết lập có tham số mặc định
KhachHang::KhachHang(string ten, int soluong, long long dongia)
{
    Ten = ten;
    SoLuong = soluong;
    DonGia = dongia;
}
// Phương thức phá hủy
KhachHang::~KhachHang()
{}
// Hàm nhập
void KhachHang::Nhap(ifstream &input)
{
    input>>ws;
    getline(input, Ten);
    input>>SoLuong>>DonGia;
}
// Hàm xuất
void KhachHang::Xuat(ofstream &output)
{
    output<<Ten<<endl;
    output<<GetSoTien()<<endl;
}