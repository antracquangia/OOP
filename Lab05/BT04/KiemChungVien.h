#ifndef KIEMCHUNGVIEN_H
#define KIEMCHUNGVIEN_H
#include "NhanVien.h"
class KiemChungVien : public NhanVien
{
    private:
        int SoLoi;
    public:
        KiemChungVien(string mnv = "", string ht = "", int t = 0, int sdt = 0, string em = "", int luongcb = 0, int soloi = 0);
        void Nhap();
        void Xuat();
        long long TinhLuong();
};
#endif