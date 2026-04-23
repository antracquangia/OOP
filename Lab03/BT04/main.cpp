#include <iostream>
#include "cArray.h"
#include <string>
using namespace std;
// kiểm tra có là số nguyên không
bool laInt(const std::string& s)
{
    if (s.empty()) return false;
    int start = (s[0] == '-') ? 1 : 0;
    if (start == 1 && s.length() == 1) return false; 
    for (int i = start; i < s.length(); i++) {
        if (s[i] < '0' || s[i] > '9') return false;
    }
    return true;
}
int main()
{
    cArray a;
    a.TaoNgauNhien();
    cout<<"Day so la:\n";
    a.Xuat();
    int n =a.DemX();
    cout<<"So lan xuat hien cua x: "<< n <<"\n";
    bool check = a.CheckTang();
    if (check) cout<<"Day so co tinh tang dan\n";
    else cout<<"Day so khong co tinh tang dan\n";
    if (a.MinOdd() == -1) cout<<"Khong co so le trong day\n";
    else cout<<"So le nho nhat trong day la: "<<a[a.MinOdd()]<<endl;
    if (a.MaxPrime() == -1) cout<<"Khong co so nguyen to trong day\n";
    else cout<<"So nguyen to lon nhat trong day la: "<<a[a.MaxPrime()]<<endl;
    cArray b = a.SelectionSortTang();
    cout<<"Day sau khi sap xep tang dan voi selection sort la:\n";
    b.Xuat();
    cArray c = a.SelectionSortGiam();
    cout<<"Day sau khi sap xep giam dan voi selection sort la:\n";
    c.Xuat();
    cArray d = a.InsertionSortTang();
    cout<<"Day sau khi sap xep tang dan voi insertion sort la:\n";
    d.Xuat();
    cArray e = a.InsertionSortGiam();
    cout<<"Day sau khi sap xep giam dan voi insertion sort la:\n";
    e.Xuat();
    cArray f = a.HeapSortTang();
    cout<<"Day sau khi sap xep tang dan voi heap sort la:\n";
    f.Xuat();
    cArray g = a.HeapSortGiam();
    cout<<"Day sau khi sap xep giam dan voi heap sort la:\n";
    g.Xuat();
    cArray h = a.QuickSortTang();
    cout<<"Day sau khi sap xep tang dan voi quick sort la:\n";
    h.Xuat();
    cArray i = a.QuickSortGiam();
    cout<<"Day sau khi sap xep giam dan voi quick sort la:\n";
    i.Xuat();
    cArray j = a.MergeSortTang();
    cout<<"Day sau khi sap xep tang dan voi merge sort la:\n";
    j.Xuat();
    cArray k = a.MergeSortGiam();
    cout<<"Day sau khi sap xep giam dan voi merge sort la:\n";
    k.Xuat();
    return 0;
}