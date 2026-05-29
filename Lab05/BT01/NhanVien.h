#pragma once
#include "header.h"
class NhanVien
{
    protected:
        string HoTen;
        int iNgay;
        int iThang;
        int iNam;
        long long Luong;
        int loai;
    public:
        NhanVien(string ten = "", int ngay = 0, int thang = 0, int nam = 0);
        virtual ~NhanVien();
        virtual void TinhLuong() = 0; 
        virtual void Nhap();
        void Xuat();
        long long getLuong();
        int SoSanh(const NhanVien &a);
        int getLoai();
};