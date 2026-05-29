#pragma once
#include "GiaoDich.h"
class NhaPho: public GiaoDich
{
    private:
        int LoaiNha;
        string DiaChi;
    public:
        NhaPho(string magd = "", int ngay = 0, int thang = 0, int nam = 0, long long dongia = 0, double dientich = 0, int loai = 0, string diachi = "");
        void Nhap();
        long long GetThanhTien();      
};