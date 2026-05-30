#include "LoaiA.h"
#include "LoaiB.h"
#include "LoaiC.h"

int main()
{
    int x, y, z;
    ifstream input("XYZ.INP");
    ofstream output("XYZ.OUT");

    if (!input.is_open() || !output.is_open())
    {
        cout << "Khong the mo file input hoac output\n";
        return 0;
    }

    input >> x >> y >> z;
    
    long long tongSoTienCongTy = 0;
    // Xử lý khách hàng Loại A
    for (int i = 0; i < x; i++)
    {
        LoaiA a;
        a.Nhap(input);
        a.Xuat(output);
        tongSoTienCongTy += a.GetSoTien();
    }

    // Xử lý khách hàng Loại B
    for (int i = 0; i < y; i++)
    {
        LoaiB b;
        b.Nhap(input);
        b.Xuat(output);
        tongSoTienCongTy += b.GetSoTien();
    }

    // Xử lý khách hàng Loại C
    for (int i = 0; i < z; i++)
    {
        LoaiC c;
        c.Nhap(input);
        c.Xuat(output);
        tongSoTienCongTy += c.GetSoTien();
    }

    // Ghi dòng tổng số tiền của công ty vào cuối file OUT 
    output << tongSoTienCongTy << endl;

    input.close();
    output.close();
    return 0;
}