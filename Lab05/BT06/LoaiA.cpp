#include "LoaiA.h"
// Phương thức thiết lập có tham số mặc định
LoaiA::LoaiA(string ten, int soluong, long long dongia): KhachHang(ten, soluong, dongia)
{}
// Phép lấy giá trị số tiền
long long LoaiA::GetSoTien()
{
    return SoLuong * DonGia * 1.1;
}
