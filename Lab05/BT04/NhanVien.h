#ifndef NHANVIEN_H
#define NHANVIEN_H
#include "header.h"
class NhanVien
{
    protected:
        int loai;
        string MaNV;
        string HoTen;
        int Tuoi;
        string SDT;
        string email;
        long long LuongCoBan;
    public:
        NhanVien (string mnv = "", string ht = "", int t = 0, int sdt = 0, string em = "", int luongcb = 0);
        virtual long long TinhLuong() = 0;            
        virtual ~NhanVien();
        virtual void Nhap();
        virtual void Xuat();
        int GetLoai();
};
#endif