#ifndef LAPTRINHVIEN_H
#define LAPTRINHVIEN_H
#include "NhanVien.h"
class LapTrinhVien: public NhanVien
{
    private:
        int SoGioThem;
    public:
        LapTrinhVien(string mnv = "", string ht = "", int t = 0, int sdt = 0, string em = "", int luongcb = 0, int giothem = 0);
        void Nhap();
        void Xuat();
        long long TinhLuong();
};
#endif