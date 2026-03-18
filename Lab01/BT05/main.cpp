#include <iostream>
#include <string>
using namespace std;
struct HocSinh
{
    string HoTen;
    float DiemToan,DiemVan, DTB;
};
void Input(HocSinh &hs) //Nhập vào họ tên, điểm toán, điểm văn
{
    cout<<"Thong tin hoc sinh:\n";
    cout<<"Ho ten: ";
    getline(cin,hs.HoTen);
    cout<<"Diem toan: ";
    cin>>hs.DiemToan;
    cout<<"Diem van: ";
    cin>>hs.DiemVan;
}
void TinhDTB(HocSinh &hs) //Tính điểm trung bình
{
    hs.DTB = (hs.DiemToan + hs.DiemVan)/2;
}
void Output(HocSinh hs) //In ra thông tin học sinh
{
    cout<<"Thong tin hoc sinh:\n";
    cout<<"Ho ten: "<<hs.HoTen<<"\n";
    cout<<"Diem toan: "<<hs.DiemToan<<"\n";
    cout<<"Diem van: "<<hs.DiemVan<<"\n";
    cout<<"DTB: "<<hs.DTB<<"\n";
}
int main()
{
    HocSinh hs;
    Input(hs);
    TinhDTB(hs);
    Output(hs);
    return 0;
}