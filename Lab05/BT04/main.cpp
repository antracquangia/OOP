#include "LapTrinhVien.h"
#include "KiemChungVien.h"
int main() {
    int n;
    string s;
    while (1)
    {
        cout<<"Nhap vao so nhan vien: ";
        getline(cin,s);
        if (CheckInteger(s))
            break;
        else cout<<"Nhap lai so nhan vien la so int\n";
    }
    n = stoi(s);
    vector<NhanVien*> dsNV;
    
    for (int i = 0; i < n; i++) {
        int loai;
        cout << "\nChon loai NV (1: Lap trinh vien, 2: Kiem chung vien): "; 
        cin >> loai;
        cin.ignore();
        NhanVien* nv;
        if (loai == 1) nv = new LapTrinhVien();
        else nv = new KiemChungVien();
        
        nv->Nhap();
        dsNV.push_back(nv);
    }

    cout << "\n--- DANH SACH NHAN VIEN ---\n";
    cout << setw(12) << "Ma nhan vien" << " | "<< setw(20) << "Ho ten" << " | "<< setw(5) << "Tuoi" << " | "<< setw(13) << "So dien thoai" << " | "<< setw(30) << "Email" << " | "<<setw(12)<< "Luong"<<endl;
    for (auto nv : dsNV) {
        nv->Xuat();
    }

    long long tongLuong = 0;
    for (auto nv : dsNV) {
        tongLuong += nv->TinhLuong();
    }
    double luongTB = (n > 0) ? (double)tongLuong / n : 0;
    cout << "\nLuong trung binh cua cong ty: " << fixed << setprecision(0) << luongTB << endl;

    cout << "\n--- NHAN VIEN CO LUONG THAP HON MUC TRUNG BINH ---\n";
    cout << setw(12) << "Ma nhan vien" << " | "<< setw(20) << "Ho ten" << " | "<< setw(5) << "Tuoi" << " | "<< setw(13) << "So dien thoai" << " | "<< setw(30) << "Email" << " | "<<setw(12)<< "Luong"<<endl;
    for (auto nv : dsNV) {
        if (nv->TinhLuong() < luongTB) {
            nv->Xuat();
        }
    }
    int max = -1, min = -1, maxLTV = -1, minKCV = -1;
    for (int i =0; i<n; i++)
    {
        if (max == -1 || dsNV[i]->TinhLuong() > dsNV[max]->TinhLuong())
            max = i;
        if (min == -1 || dsNV[i]->TinhLuong() < dsNV[min]->TinhLuong())
            min = i;
        if (dsNV[i]->GetLoai() == 1 && (maxLTV == -1 || dsNV[i]->TinhLuong() > dsNV[maxLTV]->TinhLuong()))
            maxLTV = i;
        if (dsNV[i]->GetLoai() == 2 && (minKCV == -1 || dsNV[i]->TinhLuong() < dsNV[minKCV]->TinhLuong()))
            minKCV = i;
    }
    cout << "--- NHAN VIEN CO LUONG CAO NHAT ---\n";
    dsNV[max]->Xuat();
    cout << "--- NHAN VIEN CO LUONG THAP NHAT ---\n";
    dsNV[min]->Xuat();
    cout << "--- LAP TRINH VIEN CO LUONG CAO NHAT ---\n";
    dsNV[maxLTV]->Xuat();
    cout<< "--- KIEM CHUNG VIEN CO LUONG THAP NHAT ---\n";
    dsNV[minKCV]->Xuat();
    for (auto nv : dsNV) delete nv;    
    return 0;
}