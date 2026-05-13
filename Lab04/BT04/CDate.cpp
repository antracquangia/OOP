#include "CDate.h"
// Phương thức thiết lập mặc định
CDate:: CDate()
{
    iNgay = 0;
    iThang = 0;
    iNam = 0;
}
// Phương thức thiết lập có tham số
CDate:: CDate(int ngay, int thang, int nam)
{
    iNgay = ngay;
    iThang = thang;
    iNam = nam;
}
// Số ngày lớn nhất trong tháng
int MaxNgay(int Thang, int Nam)
{
    if (Thang == 1 || Thang == 3 || Thang == 5 || Thang == 7 || Thang == 8 || Thang == 10 || Thang == 12)
        return 31;
    else if (Thang == 4 || Thang == 6 || Thang == 9 || Thang == 11)
        return 30;
    else if ((Nam % 4 == 0 && Nam % 100 != 0 )|| Nam % 400 == 0)
        return 29;
    else return 28;
}
// Toán tử cộng thêm số ngày
CDate CDate::operator+(int ngay)
{
    CDate a = *this;
    a.iNgay = a.iNgay + ngay;
    while (a.iNgay > MaxNgay (a.iThang, a.iNam))
    {
        a.iNgay = a.iNgay - MaxNgay(a.iThang, a.iNam);
        a.iThang++;
        if (a.iThang > 12)
        {
            a.iThang = 1;
            a.iNam++;
        }
    }
    return a;
}
// Toán tử trừ đi số ngày
CDate CDate::operator-(int ngay)
{
    CDate a = *this;
    a.iNgay = a.iNgay - ngay;
    while (a.iNgay <= 0)
    {
        a.iThang--;
        if (a.iThang < 1)
        {
            a.iThang = 12;
            a.iNam--;
        }
        a.iNgay = a.iNgay + MaxNgay (a.iThang, a.iNam);
    }
    return a;
}
// Toán tử ++ prefix
CDate CDate::operator++()
{
    *this = operator+(1);
    return *this;
}
// Toán tử ++ postfix
CDate CDate::operator++(int k)
{
    CDate a = *this;
    *this = operator+(1);
    return a;
}
// Toán tử -- prefix
CDate CDate::operator--()
{
    *this = operator-(1);
    return *this;
}
// Toán tử -- postfix
CDate CDate::operator--(int k)
{
    CDate a = *this;
    *this = operator-(1);
    return a;
}
// Hàm hỗ trợ tính tổng ngày để trừ 2 CDate
long CDate::TongNgay() {
    long total = iNgay;
    for (int y = 1; y < iNam; y++) {
        total += ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) ? 366 : 365;
    }
    for (int m = 1; m < iThang; m++) {
        total += MaxNgay(m, iNam);
    }
    return total;
}
// Toán tử trừ để tính số ngày chênh lệch

int operator-(CDate a, CDate b) {
    return abs(a.TongNgay() - b.TongNgay());
}
// Toán tử nhập
istream &operator>> (istream &is, CDate &a)
{
    while(1)
    {
        string s;
        while (1)
        {
            cout<<"Nhap vao so ngay: ";
            getline(is,s);
            if (CheckInt(s)) break;
            else cout<<"So ngay phai la so nguyen\n";
        }
        a.iNgay = stoi(s);
        while (1)
        {
            cout<<"Nhap vao so thang: ";
            getline(is,s);
            if (CheckInt(s)) break;
            else cout<<"So thang phai la so nguyen\n";
        }
        a.iThang = stoi(s);
        while (1)
        {
            cout<<"Nhap vao so nam: ";
            getline(is,s);
            if (CheckInt(s)) break;
            else cout<<"So nam phai la so nguyen\n";
        }
        a.iNam = stoi(s);
        if (a.iNam > 0 && (a.iThang >= 1 && a.iThang <= 12) && (a.iNgay >= 1 && a.iNgay <= MaxNgay(a.iThang, a.iNam)))
            break;
        else cout<<"Ngay thang nam khong hop le vui long nhap lai\n";
    } 
    return is;   
}
// Toán tử xuất theo định dạng dd/mm/yyyy
ostream &operator<< (ostream &os, CDate a)
{
    if (a.iNgay < 10) os<<"0";
    os <<a.iNgay<<"/";
    if (a.iThang < 10) os<<"0";
    os <<a.iThang<<"/";
    if (a.iNam <10) os<<"000";
    else if (a.iNam <100) os<<"00";
    else if (a.iNam <1000) os<<"0";
    os<<a.iNam;
    return os;
}