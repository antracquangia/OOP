#include "cNhanvienSX.h"
#include <iostream>
#include <vector>
using namespace std;
// Hàm kiểm tra kiểu int
bool laInt(string s)
{
    int i = 0;
    if (s[i] == '-') i++;
    for (; i<s.size(); i++)
    {
        if (s[i] < '0' || s[i] > '9') return 0;
    }
    return 1;
}
int main()
{
    NhanvienSX *DS;
    int n;
    string s;
    // Nhập vào số lượng phần tử có kiểm tra điều kiện nhập
    while (1)
    {
        cout<<"Nhap vao so luong nhan vien: ";
        getline(cin,s);
        if (laInt(s) && (stoi(s) > 0)) break;
        else cout<<"So luong nhan vien phai la so nguyen lon hon 0\n";
    }
    n = stoi(s);
    DS = new NhanvienSX[n];

    // Nhập vào thông tin các nhân viên
    for (int i =0; i<n; i++)
    {
        cout<<"Nhap vao thong tin nhan vien thu "<<i+1<<endl;
        DS[i].Nhap();
    }

    //Xuất ra thông tin các nhân viên
    for (int i =0; i<n; i++)
    {
        cout<<"\nThong tin nhan vien thu "<<i+1<<endl;
        DS[i].Xuat();
    }

    // Tìm nhân viên có lương thấp nhất
    vector<int> k;
    k.push_back(0);
    for (int i = 1; i<n; i++)
    {
        if (DS[i].SoSanhLuong(DS[k[0]]) == -1)
        {
            k.clear();
            k.push_back(i);
        }
        else if (DS[i].SoSanhLuong(DS[k[0]]) == 0)
        {
           k.push_back(i);
        }
    }
    cout<<"\nThong tin nhan vien co luong thap nhat:\n";
    for (int i =0; i< k.size(); i++)
    {
        cout<<DS[k[i]].GetHoTen()<<" - "<<DS[k[i]].GetMaNV()<<endl;
    }
    
    // Tính tổng lương
    long long sum = 0;
    for (int i =0; i<n; i++)
    {
        sum = sum + DS[i].TinhLuong();
    }
    cout<<"Tong tien luong phai tra: "<<sum<<endl;
    
    // Nhân viên có tuổi cao nhất
    vector<int> a;
    a.push_back(0);
    for (int i = 1; i<n; i++)
    {
        if (DS[i].SoSanhTuoi(DS[a[0]]) == -1)
        {
            a.clear();
            a.push_back(i);
        }
        else if (DS[i].SoSanhTuoi(DS[a[0]]) == 0)
        {
            a.push_back(i);
        }
    }
    cout<<"Thong tin nhan vien co tuoi cao nhat:\n";
    for (int i =0; i< a.size(); i++)
    {
        cout<<DS[a[i]].GetHoTen()<<" - "<<DS[a[i]].GetMaNV()<<endl;
    }

    // Sắp xếp danh sách nhân viên tăng dần theo lương
    for (int i =0; i<n; i++)
        for (int j = i+1; j<n; j++)
            if (DS[i].SoSanhLuong(DS[j]) == 1)
                swap (DS[i], DS[j]);
    cout<<"Danh sach nhan vien sau khi sap xep theo luong";
    for (int i =0; i<n; i++)
    {
        cout<<"\nThong tin nhan vien thu "<<i+1<<endl;
        DS[i].Xuat();
    }
    delete []DS;
    return 0;
}