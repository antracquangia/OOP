#include "Dat.h"
// Phương thức thiết lập có tham số mặc định
Dat::Dat (string magd , int ngay, int thang, int nam, long long dongia, double dientich, int loai): GiaoDich(magd, ngay, thang, nam, dongia,dientich)
{
    loaiGD = 1;
    LoaiDat = loai;
}
// Hàm nhập
void Dat::Nhap()
{
    GiaoDich::Nhap();
    string s;
    while (1)
    {
        cout<<"Nhap vao loai dat: (A la 1, B la 2, C la 3): ";
        getline (cin,s);
        if (CheckInt(s) && (stoi(s) == 1 || stoi(s) == 2 || stoi(s) == 3)) break;
        else cout<<"Loai dat khong hop le\n";
    }
    LoaiDat = stoi(s);
}
// Hàm lấy giá trị thành tiền
long long Dat::GetThanhTien()
{
    if (LoaiDat == 1) return DienTich * DonGia * 1.5;
    else return DienTich * DonGia;
}