#include "Header.h"
#include "SinhVien.h"

//Phương thức thiết lập mặc định
SinhVien::SinhVien()
{
	MaSV = "";
	HoTen = "";
	DiaChi = "";
	TongTinChi = 0;
	DTB = 0;
}
//Phương thức thiết lập có tham số
SinhVien::SinhVien(string MSV, string HT, string DC, int TTC, double Diem)
{
	MaSV = MSV;
	HoTen = HT;
	DiaChi = DC;
	TongTinChi = TTC;
	DTB = Diem;
}
//Phương thức phá hủy
SinhVien::~SinhVien()
{
};
// Hàm nhập thông tin sinh viên có kiểm tra dữ liệu đầu vào
void SinhVien::Nhap()
{
	cout << "Nhap Ma SV: ";
	getline(cin, MaSV);
	cout << "Nhap Ho Ten: ";
	getline(cin, HoTen);
	cout << "Nhap Dia Chi: ";
	getline(cin, DiaChi);
	string input;
	while (1)
	{
		cout << "Nhap Tong Tin Chi: ";
		getline(cin, input);
		if (CheckInt(input) && stoi(input) >= 0)
			break;
		else
			cout << "Tong tin chi phai la so nguyen lon hon hoac bang 0" << endl;
	}
	TongTinChi = stoi(input);
	while (1)
	{
		cout << "Nhap diem trung binh: ";
		getline(cin, input);
		if (CheckDouble(input) && stod(input) >= 0)
			break;
		else
			cout << "Diem trung binh phai la so thuc lon hon hoac bang 0" << endl;
	}
	DTB = stod(input);
}
// Hàm xuất thông tin sinh viên
void SinhVien::Xuat()
{
	cout << "Ma SV: " << MaSV << endl;
	cout << "Ho Ten: " << HoTen << endl;
	cout << "Dia Chi: " << DiaChi << endl;
	cout << "Tong Tin Chi: " << TongTinChi << endl;
	cout << "Diem Trung Binh: " << DTB << endl;
}
// Hàm lấy thông tin loại
int SinhVien::GetLoai()
{
	return loai;
}
// Hàm lấy điểm trung bình
double SinhVien::GetDTB()
{
	return DTB;
}