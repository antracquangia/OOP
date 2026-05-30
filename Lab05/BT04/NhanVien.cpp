#include "NhanVien.h"
// Phương thức thiết lập có tham số mặc định
NhanVien::NhanVien(string mnv , string ht , int t, int sdt , string em, int luongcb)
{
    MaNV = mnv;
    HoTen = ht;
    Tuoi = t;
    SDT = sdt;
    email = em;
    LuongCoBan = luongcb;
}
// Phương thức phá hủy
NhanVien::~NhanVien()
{}
// Hàm nhập
void NhanVien::Nhap()
{
    string s;
    cout<<"Nhap vao ma nhan vien: ";
    getline(cin,MaNV);
    cout<<"Nhap vao ho ten: ";
    getline(cin,HoTen);
    while (1)
    {
        cout<<"Nhap vao so tuoi: ";
        getline(cin,s);
        if (CheckInteger(s))
            break;
        else cout<<"Nhap lai so tuoi la so int\n";
    }
    Tuoi = stoi(s);
    while (1)
    {
        cout<<"Nhap vao so dien thoai: ";
        getline(cin,s);
        if (CheckInteger(s))
            break;
        else cout<<"Nhap lai so dien thoai la so int\n";
    }
    SDT = s;
    cout<<"Nhap vao email: ";
    getline(cin,email);
    while (1)
    {
        cout<<"Nhap vao luong co ban: ";
        getline(cin,s);
        if (CheckInteger(s))
            break;
        else cout<<"Nhap lai luong co ban la so long long\n";
    }
    LuongCoBan = stoll(s);
}
// Hàm xuất
void NhanVien::Xuat()
{
    cout << setw(12) << MaNV << " | " << setw(20) << HoTen << " | " << setw(5) << Tuoi << " | " << setw(13) << SDT << " | " << setw(30) << email << " | ";
}
// Hàm lấy giá trị loại
int NhanVien::GetLoai()
{
    return loai;
}