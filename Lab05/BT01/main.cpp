#include "NhanVien.h"
#include "SanXuat.h"
#include "VanPhong.h"
int main()
{
    vector<NhanVien*> DanhSach;
    int n;
    string s;
    while (1)
    {
        cout<<"Nhap vao so luong phan tu: ";
        getline(cin, s);
        if (CheckInt(s)) break;
        else cout<<"So luong phant u phai la so nguyen\n";
    }
    n = stoi(s);
    NhanVien* p;
    for (int i =0; i < n; i++)
    {
        int loai;
        cout<<"Nhap vao loai nhan vien (1: SanXuat, 2: VanPhong): ";
        cin>>loai;
        if (loai == 1) p = new SanXuat;
        else if (loai == 2) p = new VanPhong;
        p->Nhap();
        p->TinhLuong();
        DanhSach.push_back(p);
    }
    cout<<"Thong tin cac nhan vien\n";
    for (int i =0; i < n; i++)
    {
        cout<<"Nhan vien thu "<<i+1<<endl;
        DanhSach[i]->Xuat();
    }
    long long SumLuong = 0;
    for (int i =0; i<n; i++)
        SumLuong = SumLuong + DanhSach[i]->getLuong();
    cout<<"Tong luong cong ty phai tra: "<<SumLuong<<endl;
    int minLuong = -1;
    int maxTuoi = -1;
    for (int i =0; i<n; i++)
    {
        if (DanhSach[i]->getLoai() == 1)
        {
            if (minLuong == -1)
                minLuong = i;
            else if (DanhSach[minLuong]->getLuong() > DanhSach[i]->getLuong())
                minLuong = i;
        }
        else
        {
            if (maxTuoi == -1)
                maxTuoi = i;
            else if (DanhSach[maxTuoi]->SoSanh(*DanhSach[i]) == 1)
                maxTuoi = i;    
        }
    }
    if (minLuong == -1)
        cout<<"Khong co nhan vien san xuat\n";
    else
    {
        cout<<"Thong tin nhan vien san xuat co luong thap nhat:\n";
        DanhSach[minLuong]->Xuat();
    }
    if (maxTuoi == -1)
        cout<<"Khong co nhan vien van phong\n";
    else
    {
        cout<<"Thong tin nhan vien van phong co tuoi lon nhat:\n";
        DanhSach[maxTuoi]->Xuat();
    }
    return 0;
}