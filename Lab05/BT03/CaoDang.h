#pragma once
#include "SinhVien.h"
#include "Header.h"
class CaoDang : public SinhVien
{
	private:
		double DiemTotNghiep;
	public:
		CaoDang();
		CaoDang(string MSV, string HT, string DC, int TTC, float Diem, float DTN);
		~CaoDang();
		void Nhap();
		void Xuat();
		bool CheckTotNghiep();
};
