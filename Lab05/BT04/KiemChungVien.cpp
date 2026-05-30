#include "KiemChungVien.h"
// Phương thức thiết lập có tham số mặc định
KiemChungVien::KiemChungVien(string mnv, string ht, int t, int sdt, string em, int luongcb, int soloi) : NhanVien(mnv, ht, t, sdt, em, luongcb), SoLoi(soloi)
{
    loai = 2;
}
// Hàm nhập
void KiemChungVien::Nhap()
{
    NhanVien::Nhap();
    string s;
    while (1)
    {
        cout<<"Nhap vao so loi: ";
        getline(cin,s);
        if (CheckInteger(s))
            break;
        else cout<<"Nhap lai so loi la so int\n";
    }
    SoLoi = stoi(s);
}
// Hàm xuất
void KiemChungVien::Xuat()
{
    NhanVien::Xuat();
    cout << setw(13) << TinhLuong()  << endl;
}
// Hàm tính lương
long long KiemChungVien::TinhLuong()
{
    return LuongCoBan + SoLoi * 50000;
}