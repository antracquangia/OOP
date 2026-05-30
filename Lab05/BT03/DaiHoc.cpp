#include "Header.h"
#include "DaiHoc.h"
// Phương thức thiết lập mặc định
DaiHoc::DaiHoc() : SinhVien(), TenLuanVan(""), DiemLuanVan(0)
{
	loai = 2;
}
// Phương thức thiết lập có tham số
DaiHoc::DaiHoc(string MSV, string HT, string DC, int TTC, float Diem, string TLV, float DLV) : SinhVien(MSV, HT, DC, TTC, Diem), TenLuanVan(TLV), DiemLuanVan(DLV)
{
}
// Phương thức phá hủy
DaiHoc::~DaiHoc()
{
}
// Hàm nhập thông tin sinh viên đại học có kiểm tra dữ liệu đầu vào
void DaiHoc::Nhap()
{
	cout<<"Nhap vao thong tin sinh vien dai hoc:\n";
	SinhVien::Nhap();
	cout << "Nhap ten luan van: ";
	getline(cin, TenLuanVan);
	string input;
	while (1)
	{
		cout << "Nhap diem luan van: ";
		getline(cin, input);
		if (CheckDouble(input) && stof(input) >= 0 && stof(input) <= 10)
			break;
		else
			cout << "Diem luan van phai la so thuc >= 0 va <= 10" << endl;
	}
	DiemLuanVan = stod(input);
}
// Hàm xuất thông tin sinh viên đại học
void DaiHoc::Xuat()
{
	SinhVien::Xuat();
	cout << "Ten luan van: " << TenLuanVan << endl;
	cout << "Diem luan van: " << DiemLuanVan << endl;
}
// Hàm kiểm tra thông tin tốt nghiệp
bool DaiHoc::CheckTotNghiep()
{
	return(TongTinChi >= 170 && DTB >= 5 && DiemLuanVan >= 5);
}