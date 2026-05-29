#include "CanHo.h"
// Phương thức thiết lập có tham số mặc định
CanHo::CanHo(string magd , int ngay, int thang, int nam, long long dongia, double dientich, int vitri, string macan): GiaoDich(magd, ngay, thang, nam, dongia,dientich)
{
    loaiGD = 3;
    ViTri = vitri;
    MaCan = macan;
}
// Hàm nhập
void CanHo::Nhap()
{
    GiaoDich::Nhap();
    string s;
    while (1)
    {
        cout<<"Nhap vao vi tri tang: ";
        getline (cin,s);
        if (CheckInt(s)) break;
        else cout<<"Vi tri tang khong hop le\n";
    }
    ViTri = stoi(s);
    cout<<"Nhap vao ma can: ";
    getline(cin,MaCan);
}
// Hàm lấy giá trị thành tiền
long long CanHo::GetThanhTien()
{
    if (ViTri == 1) return DienTich * DonGia * 2;
    else if (ViTri == 15) return DienTich * DonGia * 1.2;
    else return DienTich * DonGia;
}