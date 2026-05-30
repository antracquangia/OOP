#include "LoaiC.h"
// Phương thức thiết lập có tham số mặc định
LoaiC::LoaiC(string ten, int soluong, long long dongia): KhachHang(ten, soluong, dongia)
{}
// Phép lấy giá trị số tiền
long long LoaiC::GetSoTien()
{
    return SoLuong * DonGia * (0.5+0.1);
}