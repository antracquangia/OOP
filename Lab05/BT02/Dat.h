#pragma once
#include "GiaoDich.h"
class Dat: public GiaoDich
{
    private:
        int LoaiDat;
    public:
        Dat (string magd = "", int ngay = 0, int thang = 0, int nam = 0, long long dongia = 0, double dientich = 0, int loai = 0);
        void Nhap();
        long long GetThanhTien();
};