#include "TamGiac.h"
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
// Hàm kiểm tra số double
bool laDouble(string s) {
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

// Phương thức thiết lập mặc định
TamGiac::TamGiac(): A(0,0), B(0,0), C(0,0)
{}

// Phương thức thiết lập có tham số
TamGiac::TamGiac(Diem a, Diem b, Diem c): A(a), B(b), C(c)
{}

// Hàm nhập
void TamGiac::Nhap()
{
    cout<<"Nhap vao thong tin tam giac\n";
    cout<<"Nhap vao diem A:\n";
    A.Nhap();
    cout<<"Nhap vao diem B:\n";
    B.Nhap();
    cout<<"Nhap vao diem C:\n";
    C.Nhap();
}

// Hàm xuất
void TamGiac::Xuat()
{
    cout<<"Diem A: ";
    A.Xuat();
    cout<<"\nDiem B: ";
    B.Xuat();
    cout<<"\nDiem C: ";
    C.Xuat();
    cout<<endl;
}

/**
* @brief Kiểm tra loại tam giác
* @return int trả về 0 nếu không là tam giác, 1 nếu là tam giác đều, 
2 nếu là tam giác cân,3 nếu là tam giác vuông, 4 nếu là tam giác tù, 
5 nếu là tam giác nhọn
**/
int TamGiac::KiemtraTamGiac()
{
    // Truy vấn giá trị hoành độ, tung độ của 3 điểm A, B, C
    double xa = A.GetX();
    double ya = A.GetY();
    double xb = B.GetX();
    double yb = B.GetY();
    double xc = C.GetX();
    double yc = C.GetY();
    // Tính 3 cạnh của tam giác
    double AB = sqrt((xa-xb)*(xa-xb) + (ya-yb)*(ya-yb));
    double BC = sqrt((xb-xc)*(xb-xc) + (yb-yc)*(yb-yc));
    double AC = sqrt((xa-xc)*(xa-xc) + (ya-yc)*(ya-yc));
    // Xét không phải tam giác
    if (AB + BC <= AC || AB + AC <= BC || AC + BC <= AB)
        return 0;
    // Xét tam giác đều
    else if (AB == BC && AB == AC)
        return 1;
    // Xét tam giác cân
    else if (AB == BC || AB == AC || BC == AC)
        return 2;
    // Xét tam giác vuông
    else if (AB*AB + BC*BC == AC*AC || AB*AB + AC*AC == BC*BC || BC*BC + AC*AC == AC*AC)
        return 3;
    // Xét tam giác tù
    else if ((xa-xb)*(xa-xc) + (ya-yb)*(ya-yc) < 0 || (xb-xa)*(xb-xc) + (yb-ya)*(yb-yc) < 0 || (xc-xa)*(xc-xb) + (yc-ya)*(yc-yb) < 0)
        return 4;
    // Tam giác nhọn
    else return 5;
}

/**
* @brief Tính chu vi tam giác
* @return double chu vi tam giác
**/
double TamGiac::TinhChuVi()
{
    // Truy vấn giá trị hoành độ, tung độ của 3 điểm A, B, C
    double xa = A.GetX();
    double ya = A.GetY();
    double xb = B.GetX();
    double yb = B.GetY();
    double xc = C.GetX();
    double yc = C.GetY();
    // Tính 3 cạnh của tam giác
    double AB = sqrt((xa-xb)*(xa-xb) + (ya-yb)*(ya-yb));
    double BC = sqrt((xb-xc)*(xb-xc) + (yb-yc)*(yb-yc));
    double AC = sqrt((xa-xc)*(xa-xc) + (ya-yc)*(ya-yc));
    return AB + BC + AC;    
}

/**
* @brief Tính diện tích tam giác
* @note Tính diện tích theo phương pháp Heron
* @return double diện tích tam giác
**/
double TamGiac:: TinhDienTich()
{
    // Truy vấn giá trị hoành độ, tung độ của 3 điểm A, B, C
    double xa = A.GetX();
    double ya = A.GetY();
    double xb = B.GetX();
    double yb = B.GetY();
    double xc = C.GetX();
    double yc = C.GetY();
    // Tính 3 cạnh của tam giác
    double AB = sqrt((xa-xb)*(xa-xb) + (ya-yb)*(ya-yb));
    double BC = sqrt((xb-xc)*(xb-xc) + (yb-yc)*(yb-yc));
    double AC = sqrt((xa-xc)*(xa-xc) + (ya-yc)*(ya-yc));
    // Tính nửa chu vi
    double p = TinhChuVi() /2;
    // Tính diện tích
    return sqrt(p*(p-AB)*(p-AC)*(p-BC));
}


// Hàm nhập hoành độ, tung độ có kiểm tra double và nhập lại
void DoubleNhap(double &x, double &y)
{
    string a,b;
    while (1)
    {
        cout<<"Nhap vao hoanh do ox: ";
        getline(cin,a);
        if (laDouble(a)) break;
        else cout<<"Hoanh do ox phai la so double\n";
    }
    x = stod(a);
    while (1)
    {
        cout<<"Nhap vao tung do oy: ";
        getline(cin,b);
        if (laDouble(b)) break;
        else cout<<"Tung do oy phai la so double\n";
    }
    y = stod(b);
}
// Hàm tịnh tiến tam giác qua 1 vector
TamGiac TamGiac::TinhTien() const
{
    double vx,vy;
    cout<<"Nhap vao vector tinh tien tam giac\n";
    DoubleNhap(vx,vy);
    TamGiac ans;
    ans.A = A.TinhTien(vx,vy);
    ans.B = B.TinhTien(vx,vy);
    ans.C = C.TinhTien(vx,vy);
    return ans;
}

// Hàm lấy trọng tâm tam giác
Diem TamGiac::getTrongTam() const {
    double gx = (A.GetX() + B.GetX() + C.GetX()) / 3.0;
    double gy = (A.GetY() + B.GetY() + C.GetY()) / 3.0;
    return Diem(gx, gy);
}

// Hàm quay tam giác
TamGiac TamGiac::Quay() const
{
    Diem G;
    TamGiac ans;
    string s;
    cout<<"Nhap vao tam quay\n";
    G.Nhap();
    while (1)
    {
        cout<<"Nhap vao so do goc: ";
        getline(cin,s);
        if (laDouble(s)) break;
        else cout<<"So do goc phai la so double\n";
    }
    double goc = stod(s) * 3.14 / 180;
    ans.A = A.Quay(G, goc);
    ans.B = B.Quay(G, goc);
    ans.C = C.Quay(G, goc);
    return ans;
}

// Hàm phóng to
TamGiac TamGiac::PhongTo() const
{
    TamGiac ans;
    double k;
    string s;
    while (1)
    {
        cout<<"Nhap vao kich thuoc thay doi: ";
        getline(cin,s);
        if (laDouble(s)) break;
        else cout<<"So do kich thuoc phai la so double\n";
    }
    k = stod(s);
    Diem G = getTrongTam();
    ans.A = A.PhongTo(G,k);
    ans.B = B.PhongTo(G,k);
    ans.C = C.PhongTo(G,k);
    return ans;
}

// Hàm thu nhỏ
TamGiac TamGiac::ThuNho() const
{
    TamGiac ans;
    double k;
    string s;
    while (1)
    {
        cout<<"Nhap vao kich thuoc thay doi: ";
        getline(cin,s);
        if (laDouble(s)) break;
        else cout<<"So do kich thuoc phai la so double\n";
    }
    k = stod(s);
    Diem G = getTrongTam();
    ans.A = A.ThuNho(G,k);
    ans.B = B.ThuNho(G,k);
    ans.C = C.ThuNho(G,k);
    return ans;
}













