#include <iostream>
#include <cmath>
#include "PhanSo.h"
#include <string>
using namespace std;
/**
 * @brief Hàm khởi tạo phân số mặc định là 0/1
 */
PhanSo::PhanSo() :iTuSo(0), iMauSo(1)
{}  

/**
 * @brief Hàm phá hủy
 */
PhanSo::~PhanSo()
{}

/**
 * @brief Kiểm tra xem chuỗi có phải là số nguyên
 * @param s chuỗi cần kiểm tra
 * @return trả về 1 nếu chuỗi là số nguyên, 0 nếu chuỗi không là số nguyên
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
 * @brief Nhập vào phân số từ bàn phím
 * @details Hàm có kiểm tra tử số, mẫu số là số nguyên, mẫu số khác 0
 * @note Nếu nhập vào không phải là số nguyên hay mẫu số = 0, hàm sẽ bắt người dùng nhập lại
 */
void PhanSo::Nhap()
{ 
    string x, y;
    // Nhập tử số
    while (true) {
        cout << "Nhap vao tu so: ";
        cin >> x;
        if (isNumber(x)) //Kiểm tra số nguyên
        {
            iTuSo = stoi(x);
            break;
        }
        cout << "Tu so phai la so nguyen.\n";
    }

    // Nhập mẫu số
    while (true) {
        cout << "Nhap vao mau so: ";
        cin >> y;
        if (isNumber(y)) //Kiểm tra số nguyên 
        {
            int tempMau = stoi(y);
            if (tempMau != 0) //Kiểm tra mẫu khác 0
            {
                iMauSo = tempMau;
                break;
            } 
            else cout << "Mau so phai khac 0.\n";
        }    
        else cout << "Mau so phai la so nguyen.\n";
    }
}

/**
 * @brief Xuất phân số ra màn hình theo định dạng tu/mau
 * @note Nếu mẫu số bằng 1, hàm chỉ in ra tử số (số nguyên)
 */
void PhanSo::Xuat()
{
    if (iMauSo == 1) 
        cout<<iTuSo<<"\n";
    else
        cout<<iTuSo<<"/"<<iMauSo<<"\n";
}

/**
 * @brief Tối giản phân số về dạng phân số tối giản và chuẩn hóa dấu.
 * @details Hàm tìm UCLN của tử số và mẫu số để rút gọn 
 * Nếu mẫu số âm, dấu trừ sẽ được đưa lên tử số.
 * @note Hàm này thay đổi trực tiếp giá trị của iTuSo và iMauSo.  
 */
void PhanSo::RutGon()
{
    int m = max(iTuSo, iMauSo);
    int n = min(iTuSo, iMauSo);
    while(n != 0)
    {
        int r = m%n;
        m = n;
        n = r;
    }
    iTuSo = iTuSo / m;
    iMauSo = iMauSo /m;
    if (iMauSo < 0)
    {
        iTuSo = iTuSo * -1;
        iMauSo = iMauSo * -1;
    }
}

/**
* @brief Tổng của phân số hiện tại với phân số a.
* @param a Phân số thứ hai.
* @return PhanSo Kết quả phép cộng sau khi đã rút gọn.
*/
PhanSo PhanSo::Tong(const PhanSo &a)
{
    PhanSo b;
    b.iTuSo = iTuSo * a.iMauSo + iMauSo * a.iTuSo;
    b.iMauSo = iMauSo * a.iMauSo;
    b.RutGon();
    return b;
}

/**
* @brief Hiệu của phân số hiện tại với phân số a.
* @param a Phân số thứ hai.
* @return PhanSo Kết quả phép trừ sau khi đã rút gọn.
*/
PhanSo PhanSo::Hieu(const PhanSo &a)
{
    PhanSo b;
    b.iTuSo = iTuSo * a.iMauSo - iMauSo * a.iTuSo;
    b.iMauSo = iMauSo * a.iMauSo;
    b.RutGon();
    return b;
}

/**
* @brief Tích của phân số hiện tại với phân số a.
* @param a Phân số thứ hai.
* @return PhanSo Kết quả phép nhân sau khi đã rút gọn.
*/
PhanSo PhanSo::Tich(const PhanSo &a)
{
    PhanSo b;
    b.iTuSo = iTuSo * a.iTuSo;
    b.iMauSo = iMauSo * a.iMauSo;
    b.RutGon();
    return b;
}

/**
* @brief Thương phân số hiện tại với phân số a.
* @param a Phân số thứ hai.
* @return PhanSo Kết quả phép chia sau khi đã rút gọn.
* @note Nếu phân số a có tử số = 0 hàm không thực hiện
*/
PhanSo PhanSo::Thuong(const PhanSo &a)
{
    PhanSo b;
    if (a.iTuSo == 0) return b;
    b.iTuSo = iTuSo * a.iMauSo;
    b.iMauSo = iMauSo * a.iTuSo;
    b.RutGon();
    return b;
}

/**
* @brief So sánh phân số hiện tại với phân số a.
* @param a Phân số thứ hai.
* @return int Trả về:
* 1: Nếu phân số hiện tại > a.
* -1: Nếu phân số hiện tại < a.
* 0: Nếu hai phân số bằng nhau.
*/
int PhanSo::SoSanh(const PhanSo &a)
{
    int k = iTuSo * a.iMauSo - a.iTuSo * iMauSo;
    if (k > 0) return 1;
    else if (k < 0) return -1;
    else return 0; 
}

/**
 * @brief Truy xuất giá trị tử số
 * @return int iTuso
 */
int PhanSo::getTuSo()
{
    return iTuSo;
}

/**
 * @brief Truy xuất giá trị mẫu số
 * @return int iMauso
 */
int PhanSo::getMauSo()
{
    return iMauSo;
}
