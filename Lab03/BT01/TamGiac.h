#ifndef TamGiac_h
#define TamGiac_h
#include "Diem.h"
class TamGiac : public Diem
{
    private:
        Diem A;
        Diem B;
        Diem C;
    public:
        TamGiac();
        TamGiac(Diem a, Diem b, Diem c);
        void Nhap();
        void Xuat();
        int KiemtraTamGiac();
        double TinhChuVi();
        double TinhDienTich();
        TamGiac TinhTien() const;
        TamGiac Quay() const;
        TamGiac PhongTo() const;
        TamGiac ThuNho() const;
        Diem getTrongTam() const;
};
#endif