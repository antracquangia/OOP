#ifndef SoPhuc_h
#define SoPhuc_h
class SoPhuc
{
    private:
        int iThuc, iAo;
    public:
        SoPhuc();
        ~SoPhuc();
        void Nhap();
        void Xuat();
        SoPhuc Tong(const SoPhuc &a);
        SoPhuc Hieu(const SoPhuc &a);
        SoPhuc Tich(const SoPhuc &a);
        SoPhuc Thuong(const SoPhuc &a);
        int getThuc();
        int getAo();
};
#endif