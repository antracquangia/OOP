#ifndef Diem_h
#define Diem_h
class Diem
{
    private:
        double x;
        double y;
    public:
        Diem();
        Diem(double a, double b);
        void Nhap();
        void Xuat();
        double GetX() const;
        double GetY() const;
        void SetX(const double &a);
        void SetY(const double &a);
        Diem TinhTien (double &vx, double &vy) const;
        Diem Quay(const Diem &a, const double & rad) const;
        Diem PhongTo (const Diem &a,const double &k) const;
        Diem ThuNho (const Diem &a, const double &k) const;
};
#endif
