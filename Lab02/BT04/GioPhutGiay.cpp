#include <iostream>
#include <string>
#include "GioPhutGiay.h"
using namespace std;

/**
 * @brief Hàm khởi tạo giờ phút giây mặc định là 0 giờ 0 phút 0 giây
 */
GioPhutGiay::GioPhutGiay() : iGio(0), iPhut(0), iGiay(0)
{}

/**
 * @brief Hàm phá hủy
 */
GioPhutGiay::~GioPhutGiay()
{}

/**
 * @brief Kiểm tra xem chuỗi có phải là số nguyên không âm
 * @param s chuỗi cần kiểm tra
 * @return bool trả về 1 nếu chuỗi là số nguyên không âm, 0 nếu chuỗi không là số nguyên không âm
 */
bool isNumber(const std::string& s)
{
    if (s.empty()) return false;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] < '0' || s[i] > '9') return false;
    }
    return true;
}

/**
 * @brief Nhập vào giờ phút giây từ bàn phím
 * @details Hàm kiểm tra giờ phút giây có là số nguyên không âm
 * @note Nếu nhập vào không phải là số nguyên không âm, hàm sẽ bắt người dùng nhập lại
 */
void GioPhutGiay::Nhap()
{
   string x,y,z;
    while (1) {
        cout << "Nhap vao so gio: ";
        cin >> x;
        if (isNumber(x))
        {
            iGio = stoi(x);
            break;
        }
        cout << "So gio phai la so nguyen khong am.\n";
    }
    while (1) {
        cout << "Nhap vao so phut: ";
        cin >> y;
        if (isNumber(y))
        {
            iPhut = stoi(y);
            break;
        }
        cout << "So phut phai la so nguyen khong am.\n";
    } 
    while (1) {
        cout << "Nhap vao so giay: ";
        cin >> z;
        if (isNumber(z))
        {
            iGiay = stoi(z);
            break;
        }
        cout << "So giay phai la so nguyen khong am.\n";
    } 

}

/**
 * @brief Xuất ra màn hình giờ phút giây theo định dạng 00:00:00
 */
void GioPhutGiay::Xuat()
{
    if (iGio < 10) cout<<"0";
    cout<<iGio<<":";
    if (iPhut < 10) cout<<"0";
    cout<<iPhut<<":";
    if (iGiay < 10) cout<<"0";
    cout<<iGiay<<"\n";
}

/**
 * @brief Kiểm tra tính đúng đắn của giờ, phút, giây
 * @return bool false nếu không thỏa điều kiện, ngược lại là true
 */
bool GioPhutGiay::Check()
{
    if (iGiay >= 60 || iPhut >= 60 || iGio >= 24) return false;
    else return true;   
}

/**
 * @brief Tính cộng thêm một giây
 * @return Giờ phút giây sau khi cộng thêm một giây
 */
GioPhutGiay GioPhutGiay::TinhCongThemMotGiay()
{
    GioPhutGiay next = *this;
    next.iGiay ++;
    if (next.iGiay == 60)
    {
        next.iGiay = 0;
        next.iPhut ++;
    }
    if (next.iPhut == 60)
    {
        next.iPhut = 0;
        next.iGio ++;
    }
    if (next.iGio == 24)
    {
        next.iGio = 0;
    }
    return next;
}