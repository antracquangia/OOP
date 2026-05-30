#pragma once
#include "KhachHang.h"
class LoaiB: public KhachHang
{
    private:
        int SoNam;
    public:
        LoaiB(string ten ="", int soluong = 0, long long dongia = 0, int sonam = 0);
        void Nhap(ifstream &input);
        long long GetSoTien();
};