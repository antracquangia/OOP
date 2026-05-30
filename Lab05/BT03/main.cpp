#include "DaiHoc.h"
#include "CaoDang.h"
#include "Header.h"
#include "SinhVien.h"
int main()
{
	vector<SinhVien*> DanhSach;
	int n;
	string s;
	SinhVien* p;
    while (1)
    {
        cout<<"Nhap vao so luong sinh vien: ";
        getline(cin,s);
        if (CheckInt(s)) break;
        else cout<<"So luong sinh vien khong hop le\n";
    }
    n = stoi(s);
	int loai;
	for (int i =0; i<n ; i++)
    {
        while (1)
        {
            cout<<"Nhap vao loai sinh vien: (1 la Cao Dang, 2 la Dai Hoc): ";
            getline (cin,s);
            if (CheckInt(s) && (stoi(s) == 1 || stoi(s) == 2)) break;
            else cout<<"Loai sinh vien khong hop le\n";
        }
        loai = stoi(s);
        if (loai == 1)
            p = new CaoDang;
        else 
            p = new DaiHoc;
		p->Nhap();
		DanhSach.push_back(p);
	}
	cout<<"Thong tin cac sinh vien:\n";
	for (int i =0; i<n; i++)
		DanhSach[i]->Xuat();
	bool flag01 = 0, flag02 = 0;
	cout<<"Thong tin cac sinh vien du dieu kien tot nghiep:\n";
	for (int i =0; i<n; i++)
		if (DanhSach[i]->CheckTotNghiep())
		{
			DanhSach[i]->Xuat();
			flag01 = 1;
		}
	if (flag01 == 0) cout<<"Khong co\n";
	cout<<"Thong tin cac sinh vien khong du dieu kien tot nghiep:\n";
	for (int i =0; i<n; i++)
		if (!DanhSach[i]->CheckTotNghiep())
		{
			DanhSach[i]->Xuat();
			flag02 = 1;
		}
	if (flag02 == 0) cout<<"Khong co\n";
	int maxCaoDang = -1, maxDaiHoc = -1;
	int n1 = 0, n2 = 0;
	for (int i =0; i<n; i++){
		if (DanhSach[i]->GetLoai() == 1)
		{
			if (maxCaoDang == -1 || DanhSach[i]->GetDTB() > DanhSach[maxCaoDang]->GetDTB())
				maxCaoDang = i; 
			if (!DanhSach[i]->CheckTotNghiep())
				n1++;
		}
		else
		{
			if (maxDaiHoc == -1 || DanhSach[i]->GetDTB() > DanhSach[maxDaiHoc]->GetDTB())
				maxDaiHoc = i;
			if (!DanhSach[i]->CheckTotNghiep())
				n2++;
		}
	}
	if (maxCaoDang == -1) cout<<"Khong co sinh vien cao dang\n";
	else 
	{
		cout<<"Thong tin sinh vien cao dang co diem trung binh cao nhat:\n";
		DanhSach[maxCaoDang]->Xuat();
	}
	if (maxDaiHoc == -1) cout<<"Khong co sinh vien dai hoc\n";
	else
	{
		cout<<"Thong tin sinh vien dai hoc co diem trung binh cao nhat:\n";
		DanhSach[maxDaiHoc]->Xuat();
	}
	cout<<"So luong sinh vien cao dang khong du dieu kien tot nghiep: "<<n1<<endl;
	cout<<"So luong sinh vien dai hoc khong du dieu kien tot nghiep: "<<n2<<endl;
	return 0;
}
