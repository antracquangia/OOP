#pragma once
#include "KhachHang.h"
class LoaiA: public KhachHang
{
    public:
        LoaiA(string ten ="", int soluong = 0, long long dongia = 0);
        long long GetSoTien();  
};