#pragma once
#include "KhachHang.h"
class LoaiC: public KhachHang
{
    public:
        LoaiC(string ten ="", int soluong = 0, long long dongia = 0);
        long long GetSoTien();  
};