#pragma once
#include "GiaoDich.h"
class CanHo: public GiaoDich
{
    private:
        int ViTri;
        string MaCan;
    public:
        CanHo (string magd = "", int ngay = 0, int thang = 0, int nam = 0, long long dongia = 0, double dientich = 0, int vitri = 0, string macan = "");
        void Nhap();
        long long GetThanhTien();  
};