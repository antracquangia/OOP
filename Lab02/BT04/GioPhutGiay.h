#ifndef GioPhutGiay_h
#define GioPhutGiay_h
class GioPhutGiay
{
    private:
        int iGio, iPhut, iGiay;
    public:
        GioPhutGiay();
        ~GioPhutGiay();
        void Nhap();
        void Xuat();
        bool Check();
        GioPhutGiay TinhCongThemMotGiay();
};
#endif