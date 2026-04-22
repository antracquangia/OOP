#include "Diem.h"
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

// Phương thức thiết lập mặc định
Diem::Diem() : x(0), y(0) {}

// Phương thức thiết lập có tham số
Diem::Diem(double a, double b) : x(a), y(b) {}

// Hàm kiểm tra chuỗi có dạng double không
bool isDouble(string s) {
    if (s.empty()) return false;
    int i = 0;
    int n = s.length();
    bool coChuSo = 0;
    int soDauCham = 0;

    // 1. Kiểm tra dấu (+ hoặc -) ở vị trí đầu tiên
    if (s[i] == '+' || s[i] == '-') {
        i++;
    }
    for (; i < n; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            coChuSo = true;
        } 
        else if (s[i] == '.') {
            if (coChuSo == 0) return false;
            soDauCham++;
            if (soDauCham > 1) return false;
        } 
        else {
            return false;
        }
    }
    //Kiểm soát cuối cùng: Phải có ít nhất một chữ số
    if (!coChuSo) return false;

    return true;
}

// Hàm nhập điểm
void Diem::Nhap()
{
    string a,b;
    while (1)
    {
        cout<<"Nhap vao hoanh do ox: ";
        getline(cin,a);
        if (isDouble(a)) break;
        else cout<<"Hoanh do ox phai la so double\n";
    }
    x = stod(a);
    while (1)
    {
        cout<<"Nhap vao tung do oy: ";
        getline(cin,b);
        if (isDouble(b)) break;
        else cout<<"Tung do oy phai la so double\n";
    }
    y = stod(b);
}

// Hàm xuất điểm
void Diem::Xuat() {
    cout <<fixed<<setprecision(2)<< "(" << x << " , " << y << ")";
}

// Hàm lấy giá trị tung độ ox
double Diem::GetX() const 
{ 
    return x; 
}

// Hàm lấy giá trị hoành độ oy
double Diem::GetY() const 
{ 
    return y; 
}

// Hàm cập nhật giá trị tung độ ox
void Diem::SetX(const double &a) 
{ 
    x = a; 
}

// Hàm cập nhật giá trị hoành độ oy
void Diem::SetY(const double &a) 
{ 
    y = a; 
}

// Phép tịnh tiến 1 điểm qua vector
Diem Diem::TinhTien(double &vx, double &vy) {
    return Diem(x + vx, y + vy);
}

// Phép quay 1 điểm
Diem Diem::Quay(const Diem &a, const double &goc) {
    double rad = goc * 3.14 / 180.0;
    double nx = a.x + (x - a.x) * cos(rad) - (y - a.y) * sin(rad);
    double ny = a.y + (x - a.x) * sin(rad) + (y - a.y) * cos(rad);
    return Diem(nx, ny);
}

// Phép phóng to
Diem Diem::PhongTo(const Diem &a, const double &k) {
    double ansx = a.x + k * (x - a.x);
    double ansy = a.y + k * (y - a.y);
    return Diem(ansx, ansy);
}

// Phép thu nhỏ
Diem Diem::ThuNho(const Diem &a, const double &k) {
    double ansx = a.x + 1.0/k * (x - a.x);
    double ansy = a.y + 1.0/k * (y - a.y);
    return Diem(ansx, ansy);
}