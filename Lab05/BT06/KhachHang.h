#pragma once
#include "header.h"
class KhachHang
{
    protected:
        string Ten;
        int SoLuong;
        long long DonGia;
    public:
        KhachHang(string ten ="", int soluong = 0, long long dongia = 0);
        virtual ~KhachHang();
        virtual long long GetSoTien() = 0;
        virtual void Nhap(ifstream &input);
        void Xuat(ofstream &output);
};