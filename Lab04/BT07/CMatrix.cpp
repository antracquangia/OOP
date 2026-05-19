#include "header.h"
#include "CMatrix.h"
// Phương thức thiết lập có tham số mặc định
CMatrix::CMatrix (int x, int y)
{
    m = x;
    n = y;
    if (m > 0 && n > 0)
    {
        p = new double* [m];
        for (int i =0; i<m; i++)
            p[i] = new double [n];
    }
    else p = nullptr;
}
// Phương thức thiết lập sao chép
CMatrix::CMatrix(const CMatrix &a)
{
    m = a.m;
    n = a.n;
    p = new double* [m];
    for (int i =0; i<m; i++)
        p[i] = new double [n];
    for (int i =0; i<m; i++)
        for (int j =0; j<n; j++)
            p[i][j] = a.p[i][j];
}
// Phép toán ép kiểu
CMatrix::CMatrix (CVector a)
{
    m = a.Getn();
    n = 1;
    p = new double* [m];
    for (int i =0; i<m; i++)
        p[i] = new double [n]; 
    for (int i =0; i<m; i++)
        p[i][0] = a[i];   
}
// Toán tử gán
CMatrix& CMatrix::operator= (const CMatrix &a)
{
    if (this != &a)
    {
        if (p != nullptr)
        {
            for (int i =0; i<m; i++)
                delete [] p[i];
            delete []p;
        }
        m = a.m;
        n = a.n;
        p = new double* [m];
        for (int i =0; i<m; i++)
        {
            p[i] = new double [n];
            for (int j =0; j<n; j++)
                p[i][j] = a.p[i][j];
        }

    }
    return *this;
}
// Phương thức phá hủy
CMatrix::~CMatrix()
{
    for (int i =0; i<m; i++)
        delete [] p[i];
    delete  [] p;
}
// Toán tử cộng
CMatrix CMatrix::operator+(const CMatrix &a)
{
    CMatrix ans (m,n);
    for (int i =0; i<m; i++)
        for (int j =0; j<n; j++)
            ans.p[i][j] = p[i][j] + a.p[i][j];
    return ans; 
}
// Toán tử trừ
CMatrix CMatrix::operator-(const CMatrix &a)
{
    CMatrix ans (m,n);
    for (int i =0; i<m; i++)
        for (int j =0; j<n; j++)
            ans.p[i][j] = p[i][j] - a.p[i][j];
    return ans; 
}
// Toán tử nhân
CMatrix CMatrix::operator*(const CMatrix &a)
{
    CMatrix ans (m,a.n);
    for (int i =0; i<m; i++)
        for (int j =0; j<a.n; j++)
        {
            ans.p[i][j] = 0;
            for (int k =0; k <n; k++)
                ans.p[i][j] +=  p[i][k] * a.p[k][j];
        }
    return ans; 
}
// Toán tử nhập
istream &operator>> (istream &is, CMatrix &a)
{

    string s;
    while (1)
    {
        cout<<"Nhap vao so dong: ";
        getline(is,s);
        if (CheckInt(s) && stoi(s)>=1) break;
        else cout<<"So dong phai la so nguyen lon hon hoac bang 1\n";
    }
    a.m = stoi(s);
    while (1)
    {
        cout<<"Nhap vao so cot: ";
        getline(is,s);
        if (CheckInt(s) && stoi(s)>=1) break;
        else cout<<"So cot phai la so nguyen lon hon hoac bang 1\n";
    }
    a.n = stoi(s);
    a = CMatrix (a.m,a.n);
    for (int i =0; i<a.m; i++)
        for (int j =0; j<a.n; j++)
        {
            while (1)
            {
                cout<<"Nhap vao gia tri p["<<i<<"]["<<j<<"]: ";
                getline(is,s);
                if (CheckDouble(s)) break;
                else cout<<"gia tri p["<<i<<"]["<<j<<"] phai la so double\n";
            }
            a.p[i][j] = stod(s);
        }
    return is;
}
// Toán tử xuất
ostream &operator<< (ostream &os, const CMatrix &a)
{
    for (int i =0; i<a.m; i++)
    {
        for (int j =0; j<a.n; j++)
        {
            os << setw(10) << left << a.p[i][j];
        }
        os<<endl;
    }
    return os;
}
// Phép lấy giá trị m
int CMatrix::Getm()
{
    return m;
}
// Phép lấy giá trị n
int CMatrix::Getn()
{
    return n;
}