#ifndef cNhanvienSX_h
#define cNhanvienSX_h
#include <string>
using namespace std;
class NhanvienSX
{
    private:
        string MaNV;
        string HoTen;
        int iNgay;
        int iThang;
        int iNam;
        int SoSP;
        long long DonGia;
    public:
        NhanvienSX();
        void Nhap();
        void Xuat();
        long long TinhLuong();
        string GetHoTen() const;
        string GetMaNV() const;
        int SoSanhTuoi (const NhanvienSX &b);
        int SoSanhLuong (NhanvienSX &b);
};
#endif