#include "NhanVien.h"
// Phương thức thiết lập có tham số mặc định
NhanVien::NhanVien(string ten, int ngay, int thang, int nam)
{
    HoTen = ten;
    iNgay = ngay;
    iThang = thang;
    iNam = nam;
}
// Phương thức phá hủy
NhanVien::~NhanVien()
{}
// Số ngày lớn nhất trong tháng
int MaxNgay(int Thang, int Nam)
{
    if (Thang == 1 || Thang == 3 || Thang == 5 || Thang == 7 || Thang == 8 || Thang == 10 || Thang == 12)
        return 31;
    else if (Thang == 4 || Thang == 6 || Thang == 9 || Thang == 11)
        return 30;
    else if ((Nam % 4 == 0 && Nam % 100 != 0 )|| Nam % 400 == 0)
        return 29;
    else return 28;
}
// Hàm nhập
void NhanVien::Nhap()
{
    string s;
    cin.ignore();
    cout<<"Nhap vao ho ten: ";
    getline(cin, HoTen);
    while(1)
    {
        string s;
        while (1)
        {
            cout<<"Nhap vao ngay sinh: ";
            getline(cin,s);
            if (CheckInt(s)) break;
            else cout<<"So ngay phai la so nguyen\n";
        }
        iNgay = stoi(s);
        while (1)
        {
            cout<<"Nhap vao thang sinh: ";
            getline(cin,s);
            if (CheckInt(s)) break;
            else cout<<"So thang phai la so nguyen\n";
        }
        iThang = stoi(s);
        while (1)
        {
            cout<<"Nhap vao nam sinh: ";
            getline(cin,s);
            if (CheckInt(s)) break;
            else cout<<"So nam phai la so nguyen\n";
        }
        iNam = stoi(s);
        if (iNam > 0 && (iThang >= 1 && iThang <= 12) && (iNgay >= 1 && iNgay <= MaxNgay(iThang, iNam)))
            break;
        else cout<<"Ngay thang nam khong hop le vui long nhap lai\n";
    } 
}
// Hàm xuất
void NhanVien::Xuat()
{
    cout<<"Ho ten: "<<HoTen<<endl;
    cout<<"Ngay sinh: ";
    if (iNgay < 10) cout <<"0";
    cout<<iNgay<<"/";
    if (iThang < 10) cout<<"0";
    cout<<iThang<<"/";
    if (iNam < 10) cout<<"000";
    else if (iNam < 100) cout <<"00";
    else if (iNam < 1000) cout<<"0";
    cout<<iNam<<endl;
    cout<<"Luong: "<<Luong<<endl;
}
// Hàm lấy giá trị lương
long long NhanVien::getLuong()
{
    return Luong;
}
// Hàm so sánh tuổi
int NhanVien::SoSanh(const NhanVien &a)
{
    if (iNam > a.iNam) return 1;
    else if (iNam < a.iNam) return -1;
    else if (iThang > a.iThang) return 1;
    else if (iThang < a.iThang) return -1;
    else if (iNgay > a.iNgay) return 1;
    else if (iNgay < a.iNgay) return -1;
    else return 0;
}
// Hàm lấy loại
int NhanVien::getLoai()
{
    return loai;
}