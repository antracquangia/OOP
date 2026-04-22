#include "DaGiac.h"
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// Phương thức thiết lập mặc định
DaGiac::DaGiac() : n(0), A(nullptr) {}

// Phương thức thiết lập có tham số
DaGiac::DaGiac(Diem *a, int k) : n(k) {
    A = new Diem[n];
    for (int i = 0; i < n; i++) A[i] = a[i];
}

// Phương thức thiết lập sao chép
DaGiac::DaGiac(const DaGiac &d) : n(d.n) {
    A = new Diem[n];
    for (int i = 0; i < n; i++) 
        A[i] = d.A[i];
}

// Toán tử gán
DaGiac& DaGiac::operator=(const DaGiac &d) {
    if (this != &d) {
        delete[] A;
        n = d.n;
        A = new Diem[n];
        for (int i = 0; i < n; i++) A[i] = d.A[i];
    }
    return *this;
}

// Phương thức phá hủy
DaGiac::~DaGiac() {
    delete[] A;
}

// Hàm kiểm tra chuỗi có dạng double không
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
// Hàm kiểm tra chuỗi có dạng int không
bool isInt(const std::string& s)
{
    if (s.empty()) return false;
    // Kiểm tra nếu có dấu âm ở đầu
    int start = (s[0] == '-') ? 1 : 0;
    // Trường hợp chỉ nhập mỗi dấu "-" là sai
    if (start == 1 && s.length() == 1) return false; 
    //Kiểm tra từng kí tự xem có phải là số không
    for (int i = start; i < s.length(); i++) {
        if (s[i] < '0' || s[i] > '9') return false;
    }
    return true;
}

// Hàm nhập
void DaGiac::Nhap() {
    string a;
    while (1)
    {
        cout<<"Nhap vao so dinh: ";
        getline(cin,a);
        if (isInt(a)&& stoi(a) >= 3) break;
        else cout<<"So dinh phai la so int lon hon hoac bang 3\n";
    }
    n = stoi(a);    
    delete[] A;
    A = new Diem[n];
    for (int i = 0; i < n; i++) {
        cout << "Nhap dinh thu " << i + 1 << ":\n";
        A[i].Nhap();
    }
}

// Hàm xuất
void DaGiac::Xuat() {
    for (int i = 0; i < n; i++) {
        A[i].Xuat();
        if (i < n - 1) cout << " ; ";
    }
    cout << endl;
}

// Hàm tích có hướng
bool ccw(Diem a, Diem b, Diem c) {
    double val = (b.GetX() - a.GetX()) * (c.GetY() - a.GetY()) - (b.GetY() - a.GetY()) * (c.GetX() - a.GetX());
    return val > 0;
}

// Kiểm tra hai đoạn thẳng AB và CD có cắt nhau không
bool intersect(Diem a, Diem b, Diem c, Diem d) {
    return (ccw(a, b, c) != ccw(a, b, d)) && (ccw(c, d, a) != ccw(c, d, b));
}

// Hàm kiểm tra đa giác trả về 0 nếu không phải đa giác, trả về 1 nếu là đa giác phức (tự cắt nhau)
// trả về 2 nếu là đa giác lồi
int DaGiac::KiemtraDaGiac() {
    // Các điểm thẳng hàng
    if (TinhDienTich() == 0) return 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 2; j < n; j++) {
            // Không kiểm tra cạnh cuối với cạnh đầu (vì kề nhau)
            if (i == 0 && j == n - 1) continue;

            if (intersect(A[i], A[(i + 1) % n], A[j], A[(j + 1) % n])) {
                return 1;
            }
        }
    }
    return 2;
}

// Hàm tính chu vi đa giác
double DaGiac::TinhChuVi() {
    double p = 0;
    for (int i = 0; i < n; i++) {
        double d1 = A[i].GetX() - A[(i+1)%n].GetX();
        double d2 = A[i].GetY() - A[(i+1)%n].GetY();
        p += sqrt(d1*d1 + d2*d2);
    }
    return p;
}

// Hàm tính diện tích đa giác
double DaGiac::TinhDienTich() {
    double area = 0;
    for (int i = 0; i < n; i++) {
        int next = (i + 1) % n;
        area += (A[i].GetX() * A[next].GetY() - A[next].GetX() * A[i].GetY());
    }
    return abs(area) / 2.0;
}

// Phép tịnh tiến đa giác
DaGiac DaGiac::TinhTien() {
    double vx, vy;
    cout << "Nhap vector tinh tien (vx, vy):\n";
    string a,b;
    while (1)
    {
        cout<<"Nhap vao hoanh do vx: ";
        getline(cin,a);
        if (laDouble(a)) break;
        else cout<<"Hoanh do vx phai la so double\n";
    }
    vx = stod(a);
    while (1)
    {
        cout<<"Nhap vao tung do vy: ";
        getline(cin,b);
        if (laDouble(b)) break;
        else cout<<"Tung do vy phai la so double\n";
    }
    vy = stod(b);
    DaGiac res = *this;
    for (int i = 0; i < n; i++) 
        res.A[i] = A[i].TinhTien(vx, vy);
    return res;
}

// Phép quay đa giác
DaGiac DaGiac::Quay() {
    Diem pivot;
    double goc;
    cout << "Nhap tam quay:\n"; 
    pivot.Nhap();
    string a;
    while (1)
    {
        cout<<"Nhap vao so do goc: ";
        getline(cin,a);
        if (laDouble(a)) break;
        else cout<<"So do goc phai la so double\n";
    }
    goc = stod(a);
    DaGiac res = *this;
    for (int i = 0; i < n; i++) 
        res.A[i] = A[i].Quay(pivot, goc);
    return res;
}

// Phép phóng to đa giác
DaGiac DaGiac::PhongTo() {
    Diem pivot;
    double k;
    cout << "Nhap tam phong to:\n"; 
    pivot.Nhap();
    string a;
    while (1)
    {
        cout << "Nhap he so phong to k: "; 
        getline(cin,a);
        if (laDouble(a)) break;
        else cout<<"He so k phai la so double\n";
    }
    k = stod(a);
    DaGiac res = *this;
    for (int i = 0; i < n; i++) 
        res.A[i] = A[i].PhongTo(pivot, k);
    return res;
}

// Phép thu nhỏ đa giác
DaGiac DaGiac::ThuNho() {
    Diem pivot;
    double k;
    cout << "Nhap tam thu nho:\n"; 
    pivot.Nhap();
    string a;
    while (1)
    {
        cout<<"Nhap he so thu nho k: ";
        getline(cin,a);
        if (laDouble(a)) break;
        else cout<<"He so k phai la so double\n";
    }
    k = stod(a);
    DaGiac res = *this;
    for (int i = 0; i < n; i++) 
        res.A[i] = A[i].ThuNho(pivot, k);
    return res;
}