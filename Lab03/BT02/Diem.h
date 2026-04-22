#ifndef DIEM_H
#define DIEM_H
class Diem {
private:
    double x, y;
public:
    Diem();
    Diem(double a, double b);
    void Nhap();
    void Xuat();    
    double GetX() const;
    double GetY() const;
    void SetX(const double &a);
    void SetY(const double &a);
    Diem TinhTien(double &vx, double &vy);
    Diem Quay(const Diem &a, const double &goc);
    Diem PhongTo(const Diem &a, const double &k);
    Diem ThuNho(const Diem &a, const double &k);
};
#endif