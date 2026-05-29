#include "GiaoDich.h"
// Phương thức thiết lập có tham số mặc định
GiaoDich::GiaoDich (string magd , int ngay, int thang, int nam, long long dongia, double dientich)
{
    MaGiaoDich = magd;
    iNgay = ngay;
    iThang = thang;
    iNam = nam;
    DonGia = dongia;
    DienTich = dientich;
}
// Phương thức phá hủy
GiaoDich::~GiaoDich()
{}
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
// Hàm nhập
void GiaoDich::Nhap()
{
    cout<<"Nhap vao ma giao dich: ";
    getline (cin,MaGiaoDich);
    string s;
    while(1)
    {
        while (1)
        {
            cout<<"Nhap vao ngay giao dich: ";
            getline(cin,s);
            if (CheckInt(s)) break;
            else cout<<"So ngay phai la so nguyen\n";
        }
        iNgay = stoi(s);
        while (1)
        {
            cout<<"Nhap vao thang giao dich: ";
            getline(cin,s);
            if (CheckInt(s)) break;
            else cout<<"So thang phai la so nguyen\n";
        }
        iThang = stoi(s);
        while (1)
        {
            cout<<"Nhap vao nam giao dich: ";
            getline(cin,s);
            if (CheckInt(s)) break;
            else cout<<"So nam phai la so nguyen\n";
        }
        iNam = stoi(s);
        if (iNam > 0 && (iThang >= 1 && iThang <= 12) && (iNgay >= 1 && iNgay <= MaxNgay(iThang, iNam)))
            break;
        else cout<<"Ngay thang nam khong hop le vui long nhap lai\n";
    }
    while (1)
    {
        cout<<"Nhap vao don gia: ";
        getline(cin,s);
        if (CheckInt(s)) break;
        else cout<<"Don gia phai la so nguyen\n";
    }
    DonGia = stoll(s);
    while (1)
    {
        cout<<"Nhap vao dien tich: ";
        getline(cin,s);
        if (CheckDouble(s)) break;
        else cout<<"Dien tich phai la so double\n";
    }
    DienTich = stod(s);

}
// Hàm xuất
void GiaoDich::Xuat()
{
    cout<<"Ma giao dich: "<<MaGiaoDich<<endl;
    cout<<"Ngay giao dich: ";
    if (iNgay < 10) cout <<"0";
    cout<<iNgay<<"/";
    if (iThang < 10) cout<<"0";
    cout<<iThang<<"/";
    if (iNam < 10) cout<<"000";
    else if (iNam < 100) cout <<"00";
    else if (iNam < 1000) cout<<"0";
    cout<<iNam<<endl;
    cout<<"Thanh tien: "<<GetThanhTien()<<endl;
}
// Hàm lấy giá trị tháng
int GiaoDich::GetThang()
{
    return iThang;
}
// Hàm lấy giá trị năm
int GiaoDich::GetNam()
{
    return iNam;
}
// Hàm lấy giá trị loại
int GiaoDich::GetLoai()
{
    return loaiGD;
}