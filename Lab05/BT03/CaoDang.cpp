#include "CaoDang.h"

// Phương thức thiết lập mặc định
CaoDang::CaoDang() : SinhVien(), DiemTotNghiep(0)
{
	loai = 1;
}

// Phương thức thiết lập có tham số
CaoDang::CaoDang(string MSV, string HT, string DC, int TTC, float Diem, float DTN) : SinhVien(MSV, HT, DC, TTC, Diem), DiemTotNghiep(DTN)
{
}

// Phương thức phá hủy
CaoDang::~CaoDang()
{
}

// Hàm nhập thông tin sinh viên cao đẳng có kiểm tra dữ liệu đầu vào
void CaoDang::Nhap()
{
	cout<<"Nhap vao thong tin sinh vien cao dang:\n";
	SinhVien::Nhap();
	string input;
	while (1)
	{
		cout << "Nhap diem tot nghiep: ";
		getline(cin, input);
		if (CheckDouble(input) && stod(input) >= 0 && stod(input) <= 10)
			break;
		else
			cout << "Diem tot nghiep phai la so thuc >= 0 va <= 10" << endl;
	}
	DiemTotNghiep = stod(input);
}

// Hàm xuất thông tin sinh viên cao đẳng
void CaoDang::Xuat()
{
	SinhVien::Xuat();
	cout << "Diem tot nghiep: " << DiemTotNghiep << endl;
}

// Hàm kiểm tra thông tin tốt nghiệp
bool CaoDang::CheckTotNghiep()
{
	return (TongTinChi >= 120 && DTB >= 5 && DiemTotNghiep >= 5);
}