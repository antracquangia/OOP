#include "CanHo.h"
#include "Dat.h"
#include "NhaPho.h"
int main()
{
    string s;
    int n;
    int n1 =0, n2=0, n3 =0;
    int loai;
    vector<GiaoDich*> DanhSach;
    GiaoDich* p;
    while (1)
    {
        cout<<"Nhap vao so luong giao dich: ";
        getline(cin,s);
        if (CheckInt(s)) break;
        else cout<<"So luong giao dich khong hop le\n";
    }
    n = stoi(s);
    for (int i =0; i<n ; i++)
    {
        while (1)
        {
            cout<<"Nhap vao loai giao dich: (1 la Dat, 2 la Nha Pho, 3 la Can Ho): ";
            getline (cin,s);
            if (CheckInt(s) && (stoi(s) == 1 || stoi(s) == 2 || stoi(s) == 3)) break;
            else cout<<"Loai giao dich khong hop le\n";
        }
        loai = stoi(s);
        if (loai == 1)
        {
            p = new Dat;
            n1++;
        }
        else if (loai == 2)
        {
            p = new NhaPho;
            n2++;
        }
        else 
        {
            p = new CanHo;
            n3++;
        }
        p->Nhap();
        DanhSach.push_back(p);
    }
    long long SumCanHo = 0;
    int MaxNhaPho = -1;
    if (n1 == 0) cout<<"Khong co giao dich dat\n";
    else cout<<"So giao dich dat la: "<<n1<<endl;
    if (n2 == 0) cout<<"Khong co giao dich nha pho\n";
    else 
    {
        cout<<"So giao dich nha pho la: "<<n2<<endl;
        for (int i =0; i< n; i++)
            if (DanhSach[i]->GetLoai() == 2)
                if (MaxNhaPho == -1 || DanhSach[MaxNhaPho]->GetThanhTien() < DanhSach[i]->GetThanhTien())
                    MaxNhaPho = i;
        cout<<"Giao dich nha pho co gia tri cao nhat la:\n";
        DanhSach[MaxNhaPho]-> Xuat();
    }
    if (n3 == 0) cout<<"Khong co giao dich can ho\n";
    else 
    {
        cout<<"So giao dich can ho la: "<<n3<<endl;
        for (int i =0; i< n; i++)
            if (DanhSach[i]->GetLoai() == 3)
                SumCanHo = SumCanHo + DanhSach[i]->GetThanhTien();
        cout<<"Trung binh thanh tien giao dich can ho: "<<SumCanHo / n3<<endl;
    }
    cout<<"Thong tin cac giao dich cua thang 12 nam 2024:\n";
    bool flag = 0;
    for (int i =0; i<n; i++)
    {
        if (DanhSach[i]->GetThang() == 12 && DanhSach[i]->GetNam() == 2024)
        {
            DanhSach[i]->Xuat();
            flag = 1;
        }
    }
    if (flag == 0) cout<<"Khong co";
    return 0;
}