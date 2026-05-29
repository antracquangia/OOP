#pragma once
#include "header.h"
class GiaoDich
{
    protected:
        int loaiGD;
        string MaGiaoDich;
        int iNgay;
        int iThang;
        int iNam;
        long long DonGia;
        double DienTich;
    public:
        GiaoDich (string magd = "", int ngay = 0, int thang = 0, int nam = 0, long long dongia = 0, double dientich = 0);
        virtual ~GiaoDich();
        virtual void Nhap();
        void Xuat();
        virtual long long GetThanhTien() = 0;
        int GetThang();
        int GetNam();
        int GetLoai();
};