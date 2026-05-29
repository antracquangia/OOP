#pragma once
#include "NhanVien.h"
class SanXuat: public NhanVien
{
    private:
        long long LuongCB;
        int SoSanPham;
    public:
        SanXuat(string ten = "", int ngay = 0, int thang = 0, int nam = 0, long long lcb = 0, int sosp = 0);
        void Nhap();
        void TinhLuong();
};