#include "cNhanvienSX.h"
#include <iostream>
#include <string>
using namespace std;

// Phương thức thiết lập mặc định
NhanvienSX::NhanvienSX()
{
    MaNV = "";
    HoTen ="";
    iNgay = 0;
    iThang = 0;
    iNam = 0;
    SoSP = 0;
    DonGia = 0;
}

// Hàm kiểm tra kiểu int
bool isInt(string s)
{
    int i = 0;
    if (s[i] == '-') i++;
    for (; i<s.size(); i++)
    {
        if (s[i] < '0' || s[i] > '9') return 0;
    }
    return 1;
}

// Hàm nhập thông tin nhân viên
void NhanvienSX::Nhap()
{
    cout<<"Nhap vao ma nhan vien: ";
    getline(cin,MaNV);
    cout<<"Nhap vao ho va ten: ";
    getline(cin,HoTen);
    string a,b,c, d, e;
    while (1)
    {
        cout<<"Nhap vao ngay sinh: ";
        getline(cin,a);
        if (isInt(a)) break;
        else cout<<"Ngay sinh phai la so nguyen\n";
    }
    iNgay = stoi(a);
    while (1)
    {
        cout<<"Nhap vao thang sinh: ";
        getline(cin,b);
        if (isInt(b)) break;
        else cout<<"Thang sinh phai la so nguyen\n";
    }
    iThang = stoi(b);
    while (1)
    {
        cout<<"Nhap vao nam sinh: ";
        getline(cin,c);
        if (isInt(c)) break;
        else cout<<"Nam sinh phai la so nguyen\n";
    }
    iNam = stoi(c);
    while (1)
    {
        cout<<"Nhap vao so san pham: ";
        getline(cin,d);
        if (isInt(d)) break;
        else cout<<"So san pham phai la so nguyen\n";
    }
    SoSP = stoi(d);
    while (1)
    {
        cout<<"Nhap vao don gia: ";
        getline(cin,e);
        if (isInt(e)) break;
        else cout<<"Don gia phai la so nguyen\n";
    }
    DonGia = stoi(e);
}

// Hàm xuất nhân viên
void NhanvienSX::Xuat()
{
    cout<<"Ma nhan vien: "<<MaNV<<endl;
    cout<<"Ho va ten: "<<HoTen<<endl;
    cout<<"Ngay sinh: "<<iNgay<<"/"<<iThang<<"/"<<iNam<<endl;
    cout<<"So san pham: "<<SoSP<<endl;
    cout<<"Don gia mot san pham: "<<DonGia<<endl;
    cout<<"Luong nhan vien: "<<TinhLuong();
}

// Hàm tính lương
long long NhanvienSX::TinhLuong()
{
    return SoSP * DonGia;
}

// Hàm lấy thông tin họ tên
string NhanvienSX::GetHoTen() const
{
    return HoTen;
}

//Hàm lấy thông tin mã nhân viên
string NhanvienSX::GetMaNV() const
{
    return MaNV;
}

// Hàm so sánh tuổi nhân viên trả về -1 nếu người hiện tại lớn hơn người b, trả về
// 1 nếu người hiện tại nhỏ hơn người b, trả về 0 nếu bằng nhau 
int NhanvienSX::SoSanhTuoi(const NhanvienSX &b)
{
    if (iNam < b.iNam) return -1;
    else if (iNam > b.iNam) return 1;
    else if (iThang < b.iThang) return -1;
    else if (iThang > b.iThang) return 1;
    else if (iNgay < b.iNgay) return -1;
    else if (iNgay > b.iNgay) return 1;
    else return 0;
}

int NhanvienSX::SoSanhLuong(NhanvienSX &b)
{
    if (TinhLuong() < b.TinhLuong()) return -1;
    else if (TinhLuong() > b.TinhLuong()) return 1;
    else return 0;
}