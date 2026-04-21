#include "Diem.h"
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;
// Phương thức thiết lập mặc định
Diem::Diem()
{
    x = 0;
    y = 0;
}

// Phương thức thiết lập có tham số
Diem::Diem(double a, double b):x(a), y(b)
{}

/**
 * @brief Kiểm tra xem chuỗi có phải là số double
 * @param s chuỗi cần kiểm tra
 * @return trả về 1 nếu chuỗi là số double, 0 nếu chuỗi không là số nguyên
 */
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
void Diem::Xuat()
{
    cout << fixed << setprecision(2)<<"("<<x<<","<<y<<")";
}

// Phương thức truy vấn hoành độ ox
double Diem::GetX() const
{
    return x;
}

// Phương thức truy vấn tung độ oy
double Diem::GetY() const
{
    return y;
}

// Phương thức cập nhật hoành độ ox
void Diem::SetX(const double &a)
{
    x = a;
}

// Phương thức cập nhật tung độ oy
void Diem::SetY(const double &a)
{
    y = a;
}

// Phép tịnh tiến 1 điểm qua vector
Diem Diem::TinhTien (double &vx, double &vy) const
{
    Diem ans;
    ans.x = x + vx;
    ans.y = y + vy;
    return ans;
}

// Phép quay 1 điểm
Diem Diem::Quay(const Diem &a, const double & rad) const
{
    Diem ans;
    double cosA = cos(rad);
    double sinA = sin(rad);
    // Tịnh tiến điểm về gốc tọa độ dựa trên tâm quay
    double xShifted = x - a.x;
    double yShifted = y - a.y;
    // Tính phép quay
    ans.x = xShifted * cosA - yShifted * sinA + a.x;
    ans.y = xShifted * sinA + yShifted * cosA + a.y;
    return ans;
}

// Phép phóng to
Diem Diem::PhongTo(const Diem &a,const double &k) const
{
    Diem ans;    
    ans.x = a.x + k * (x - a.x);
    ans.y = a.y + k * (y - a.y);
    return ans;
}

// Phép thu nhỏ
Diem Diem::ThuNho(const Diem &a, const double &k) const
{
    return PhongTo(a,1/k);
}