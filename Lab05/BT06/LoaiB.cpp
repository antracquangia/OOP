#include "LoaiB.h"
// Phương thức thiết lập có tham số mặc định
LoaiB::LoaiB(string ten, int soluong, long long dongia, int sonam): KhachHang(ten, soluong, dongia)
{
    SoNam = sonam;
}
// Phép lấy giá trị số tiền
long long LoaiB::GetSoTien()
{
    double SoPhanTram = max(SoNam * 5.0, 50.0); 
    double phanTramPhaiTra = 1.0 - (SoPhanTram / 100.0);
    double thanhTien = (SoLuong * DonGia) * phanTramPhaiTra * 1.1;    
    return (long long)thanhTien; 
}
// Hàm nhập
void LoaiB::Nhap(ifstream &input) {
    input >> ws; 
    getline(input, Ten);
    input >> SoLuong >> DonGia >> SoNam;
}