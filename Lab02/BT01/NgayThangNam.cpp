#include <iostream>
#include <string>
#include "NgayThangNam.h"
using namespace std;
/**
 * @brief Hàm khởi tạo ngày tháng năm mặc định là 0/0/0
 */
NgayThangNam::NgayThangNam(): iNgay(0), iThang(0), iNam(0)
{}

/**
 * @brief Hàm phá hủy
 */
NgayThangNam::~NgayThangNam()
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
 * @brief Nhập vào ngày tháng năm từ bàn phím
 * @details Hàm kiểm tra ngày, tháng, năm có là số nguyên
 * @note Nếu nhập vào không phải là số nguyên, hàm sẽ bắt người dùng nhập lại
 */
void NgayThangNam::Nhap()
{
    string x,y,z;
    while (1) {
        cout << "Nhap vao ngay: ";
        cin >> x;
        if (isNumber(x))
        {
            iNgay = stoi(x);
            break;
        }
        cout << "Ngay phai la so nguyen.\n";
    }
    while (1) {
        cout << "Nhap vao thang: ";
        cin >> y;
        if (isNumber(y))
        {
            iThang = stoi(y);
            break;
        }
        cout << "Thang phai la so nguyen.\n";
    }
    while (1) {
        cout << "Nhap vao nam: ";
        cin >> z;
        if (isNumber(z))
        {
            iNam = stoi(z);
            break;
        }
        cout << "Nam phai la so nguyen.\n";
    }
}

/**
 * @brief Xuất ra màn hình ngày, tháng, năm theo định dạng dd/mm/yyyy
 */
void NgayThangNam::Xuat()
{
    if (iNgay <= 9)
        cout<<"0";
    cout<<iNgay<<"/";
    if (iThang <= 9)
        cout<<"0";
    cout<<iThang<<"/";
    if (iNam <= 9)
        cout<<"000";
    else if (iNam <= 99)
        cout<<"00";
    else if (iNam <= 999)
        cout<<"0";
    cout<<iNam<<"\n";
}

/**
 * @brief Kiểm tra tính hợp lệ của tháng, năm
 * @return bool 0 nếu (1<= tháng <= 12) và (năm >= 1), 1 nếu ngược lại
 */
bool NgayThangNam::CheckThangNam()
{
    if ((iThang >=1 && iThang <= 12) && iNam >= 1)
        return 1;
    else return 0; 
}

/**
 * @brief Tính số lượng ngày lớn nhất trong tháng
 * @note Kiểm tra tính hợp lệ của tháng, năm trước
 * @return int -1 nếu không hợp lệ, ngược lại là số ngày lớn nhất trong tháng
 */
int NgayThangNam::MaxNgay()
{
    if (CheckThangNam() == 0)
        return -1;
    else
    {
        if (iThang == 1 || iThang == 3 || iThang == 5 || iThang == 7 || iThang == 8 || iThang == 10 || iThang == 12)
            return 31;
        else if (iThang == 4|| iThang == 6 || iThang == 9 || iThang == 11)
            return 30;
        else if (iNam % 4 == 0 && iNam % 100 != 0)
            return 29;
        else if (iNam % 400 == 0)
            return 29;
        else
            return 28;        
    }
}

/**
 * @brief Kiểm tra tính hợp lệ của ngày
 * @return bool 0 nếu không hợp lệ, 1 nếu hợp lệ
 */
bool NgayThangNam::CheckNgay()
{
    if (MaxNgay() == -1)
        return 0;
    else if (iNgay < 1 || iNgay > MaxNgay())
        return 0;
    else return 1;

}

/**
 * @brief Ngày tháng năm tiếp theo
 * @return NgayThangNam ngày tháng năm kế tiếp ngày đã nhập
 */
NgayThangNam NgayThangNam::NgayThangNamTiepTheo()
{
    NgayThangNam next = *this;
    int maxD = MaxNgay();
    if (iNgay < maxD)
        next.iNgay ++;
    else if (iNgay == maxD && iThang == 12)
    {
        next.iNgay = 1;
        next.iThang = 1;
        next.iNam ++;
    }
    else
    {
        next.iNgay = 1;
        next.iThang ++;
    }
    return next;
}
