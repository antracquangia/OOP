#ifndef DAIHOC_H
#define DAIHOC_H
#include "SinhVien.h"
#include "Header.h"
class DaiHoc : public SinhVien
{
	private:
		string TenLuanVan;
		double DiemLuanVan;
	public:
		DaiHoc();
		DaiHoc(string MSV, string HT, string DC, int TTC, float Diem, string TLV, float DLV);
		~DaiHoc();
		void Nhap();
		void Xuat();
		bool CheckTotNghiep();
};
#endif
