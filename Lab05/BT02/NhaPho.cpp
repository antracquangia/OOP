#include "NhaPho.h"
// Phương thức thiết lập có tham số mặc định
NhaPho::NhaPho (string magd , int ngay, int thang, int nam, long long dongia, double dientich, int loai, string diachi): GiaoDich(magd, ngay, thang, nam, dongia,dientich)
{
    loaiGD = 2;
    LoaiNha = loai;
    DiaChi = diachi;
}
// Hàm nhập
void NhaPho::Nhap()
{
    GiaoDich::Nhap();
    string s;
    while (1)
    {
        cout<<"Nhap vao loai nha: (cao cap la 1, thuong la 2): ";
        getline (cin,s);
        if (CheckInt(s) && (stoi(s) == 1 || stoi(s) == 2)) break;
        else cout<<"Loai nha khong hop le\n";
    }
    LoaiNha = stoi(s);
    cout<<"Nhap vao dia chi: ";
    getline(cin,DiaChi);
}
// Hàm lấy giá trị thành tiền
long long NhaPho::GetThanhTien()
{
    if (LoaiNha == 1) return DienTich * DonGia;
    else return DienTich * DonGia * 0.9;
}