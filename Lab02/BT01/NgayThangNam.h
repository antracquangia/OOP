#ifndef NgayThangNam_h
#define NgayThangNam_h
class NgayThangNam
{
    private:
        int iNgay, iThang, iNam;
    public:
        NgayThangNam();
        ~NgayThangNam();
        void Nhap();
        void Xuat();
        bool CheckThangNam();
        int MaxNgay();
        bool CheckNgay();
        NgayThangNam NgayThangNamTiepTheo();
};
#endif