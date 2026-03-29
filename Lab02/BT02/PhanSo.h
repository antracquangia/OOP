#ifndef PhanSo_h
#define PhanSo_h
class  PhanSo
{
private:
    int iTuSo; 
    int iMauSo;
public:
    PhanSo();
    ~PhanSo();
    void Nhap();
    void Xuat();
    void RutGon();
    PhanSo Tong(const PhanSo &a);
    PhanSo Hieu(const PhanSo &a);
    PhanSo Tich(const PhanSo &a);
    PhanSo Thuong(const PhanSo &a);
    int SoSanh(const PhanSo &a);
    int getTuSo();
    int getMauSo();
};
#endif
