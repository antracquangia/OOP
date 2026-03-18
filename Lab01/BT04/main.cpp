#include <iostream>
using namespace std;
struct Date{
    int day, month, year;
};
void Input( Date &d) // Nhập vào ngày, tháng, năm
{
    cout<<"Nhap vao ngay hien tai:\n";
    cout<<"Nhap vao ngay: ";
    cin>>d.day;
    cout<<"Nhap vao thang: ";
    cin>>d.month;
    cout<<"Nhap vao nam: ";
    cin>>d.year;
}
int maxDays(Date d) //Tính ngày lớn nhất của tháng
{
    if (d.month == 1 || d.month == 3 || d.month == 5 || d.month == 7 || d.month == 8 || d.month == 10 || d.month == 12) {
        return 31;
    } else if (d.month == 4 || d.month == 6 || d.month == 9 || d.month == 11) {
        return 30;
    } else {
        if ((d.year % 4 == 0 && d.year % 100 != 0) || (d.year % 400 == 0)) {
            return 29;
        } else {
            return 28;
        }
    }
}
bool Check(Date d) { //Kiểm tra tính hợp lệ của năm và tháng
    if (d.year < 0 || d.month < 1 || d.month > 12) return false;
    int maxD = maxDays(d);
    return (d.day >= 1 && d.day <= maxD); //sau đó kiểm tra ngày qua ngày lớn nhất của tháng
}
Date Nextday(Date d) { //Tính ngày tiếp theo 
    Date next = d;
    if (!Check(d)) return next;
    int maxD = maxDays(d);
    if (d.day < maxD) { //nếu không là ngày cuối tháng thì ngày tăng thêm 1
        next.day++;
    }
    else { //nếu là ngày cuối tháng thì qua tháng mới, ngày = 1
        next.day = 1;
        if (d.month == 12) {
            next.month = 1;
            next.year++;
        }
        else next.month++;
        }
    return next;
}
void Output(Date d) { 
    if (Check(d)) { //xuất ra ngày,tháng,năm nếu hợp lệ
        if (d.day < 10) cout << "0";
        cout << d.day << "/";
        if (d.month < 10) cout << "0";
        cout << d.month << "/" << d.year << endl;
    } else { //ngược lại xuất ra không hợp lệ
        cout << "Ngay thang nam khong hop le" << endl;
    }
}
int main()
{
    Date today;
    Input(today);
    Date tomorrow = Nextday(today);
    cout<<"Ngay hien tai: ";
    Output(today);
    cout<<"Ngay hom sau:  ";
    Output(tomorrow);
    return 0;
}
