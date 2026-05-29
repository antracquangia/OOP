#pragma once
#include "NhanVien.h"
class VanPhong: public NhanVien
{
    private:
        int SoNgay;
    public:
        VanPhong(string ten = "", int ngay = 0, int thang = 0, int nam = 0, int songay = 0);
        void Nhap();
        void TinhLuong();
};