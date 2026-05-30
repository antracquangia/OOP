#pragma once
#include "Header.h"
class SinhVien
{
	protected:
		string MaSV;
		string HoTen;
		string DiaChi;
		int TongTinChi;
		double DTB;
		int loai;
	public:
		SinhVien();
		SinhVien(string MSV, string HT, string DC, int TTC, double Diem);
		virtual ~SinhVien();
		virtual void Nhap();
		virtual void Xuat();
		virtual bool CheckTotNghiep() = 0;
		int GetLoai();
		double GetDTB();
};


