#include <iostream>
#include <string>
#include "SoPhuc.h"
using namespace std;

/**
 * @brief Hàm khởi tạo số phức mặc định là 0 + 0i
 */
SoPhuc::SoPhuc() : iThuc(0), iAo(0)
{}

/**
 * @brief Hàm phá hủy
 */
SoPhuc::~SoPhuc()
{}

/**
 * @brief Kiểm tra xem chuỗi có phải là số nguyên
 * @param s chuỗi cần kiểm tra
 * @return bool trả về 1 nếu chuỗi là số nguyên, 0 nếu chuỗi không là số nguyên
 */
bool isNumber(const std::string& s)
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

/**
 * @brief Nhập vào số phức từ bàn phím
 * @details Hàm kiểm tra phần thực, phần ảo có là số nguyên
 * @note Nếu nhập vào không phải là số nguyên, hàm sẽ bắt người dùng nhập lại
 */
void SoPhuc::Nhap()
{
    string x,y;
    while (1) {
        cout << "Nhap vao phan thuc: ";
        cin >> x;
        if (isNumber(x))
        {
            iThuc = stoi(x);
            break;
        }
        cout << "Phan thuc phai la so nguyen.\n";
    }
    while (1) {
        cout << "Nhap vao phan ao: ";
        cin >> y;
        if (isNumber(y))
        {
            iAo = stoi(y);
            break;
        }
        cout << "Phan ao phai la so nguyen.\n";
    }
}

/**
 * @brief Xuất ra màn hình so phức theo định dạng a + bi
 * @note Nếu phần ảo  = 0 thì xuất ra phần thực thôi
 */
void SoPhuc::Xuat()
{
    if (iAo == 0) cout<<iThuc<<"\n";
    else cout<<iThuc<<(iAo < 0 ?" - " :" + ")<<abs(iAo)<<"i\n";
}
/**
* @brief Tổng của số phức hiện tại với số phức a
* @param a Số phức thứ hai
* @return SoPhuc Tổng của hai số
*/
SoPhuc SoPhuc::Tong(const SoPhuc &a)
{
    SoPhuc ans;
    ans.iThuc = iThuc + a.iThuc;
    ans.iAo = iAo + a.iAo;
    return ans;
}

/**
* @brief Hiệu của số phức hiện tại với số phức a
* @param a Số phức thứ hai
* @return SoPhuc Hiệu của hai số
*/
SoPhuc SoPhuc::Hieu(const SoPhuc &a)
{
    SoPhuc ans;
    ans.iThuc = iThuc - a.iThuc;
    ans.iAo = iAo - a.iAo;
    return ans;
}

/**
* @brief Tích của số phức hiện tại với số phức a
* @param a Số phức thứ hai
* @return SoPhuc Tích của hai số
*/
SoPhuc SoPhuc::Tich(const SoPhuc &a)
{
    SoPhuc ans;
    ans.iThuc = iThuc * a.iThuc - iAo * a.iAo;
    ans.iAo = iThuc * a.iAo + iAo * a.iThuc;
    return ans;
}

/**
* @brief Thương của số phức hiện tại với số phức a
* @note khai báo phần thực và phần ảo là số nguyên nên giá trị bị ép kiểu về int
* @param a Số phức thứ hai
* @return SoPhuc Thương của hai số
*/
SoPhuc SoPhuc::Thuong(const SoPhuc &a)
{
    SoPhuc ans;
    float Mau = a.iThuc * a.iThuc + a.iAo * a.iAo;
    if (Mau == 0) return ans;
    ans.iThuc = (iThuc * a.iThuc + iAo * a.iAo)/Mau;
    ans.iAo = (iAo * a.iThuc - iThuc * a.iAo)/Mau;
    return ans;
}

/**
 * @brief Truy xuất giá trị phần thực
 * @return int iThuc
 */
int SoPhuc::getThuc()
{
    return iThuc;
}

/**
 * @brief Truy xuất giá trị phần ảo
 * @return int iAo
 */
int SoPhuc::getAo()
{
    return iAo;
}
