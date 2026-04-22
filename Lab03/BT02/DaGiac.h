#ifndef DAGIAC_H
#define DAGIAC_H
#include "Diem.h"

class DaGiac : public Diem {
private:
    int n;
    Diem *A;
public:
    DaGiac();
    DaGiac(Diem *a, int k);
    DaGiac(const DaGiac &d);
    DaGiac& operator=(const DaGiac &d);
    ~DaGiac(); 
    void Nhap();
    void Xuat();    
    int KiemtraDaGiac();
    double TinhChuVi();
    double TinhDienTich();    
    DaGiac TinhTien();
    DaGiac Quay();
    DaGiac PhongTo();
    DaGiac ThuNho();
};

#endif