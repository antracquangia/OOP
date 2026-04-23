#include <iostream>
#include <ctime>
#include <random>
#include <string>
#include "cArray.h"
#define MAXN 10000
using namespace std;

// Phương thức thiết lập mặc định
cArray::cArray()
{
    n = 0;
    p = NULL;
}

// Phương thức thiết lập có tham số
cArray::cArray(int a, int *b)
{
    n = a;
    p = new int [n];
    for (int i =0; i< n; i++)
        p[i] = b[i];
}

// Phương thức thiết lập sao chép
cArray::cArray(const cArray &a)
{
    n = a.n;
    p = new int [n];
    for (int i =0; i< n; i++)
        p[i] = a.p[i];
}

// Toán tử gán
cArray cArray::operator= (const cArray &a)
{
    if (this != &a)
    {
        delete []p;
        n = a.n;
        p = new int [n];
        for (int i =0; i< n; i++)
            p[i] = a.p[i]; 
    }
    return *this;
}

// Phương thức phá hủy
cArray::~cArray()
{
    delete[] p;
}

// phép toán lấy phần tử của mảng
int &cArray::operator[] (int i)
{
    return p[i];
}

// Hàm xuất ra các phần tử
void cArray::Xuat()
{
    for (int i = 0; i<n; i++)
        cout<<p[i]<<(i == n-1 ?"\n":" ");
}

// Hàm kiểm tra chuỗi có dạng int không
bool isInt(const std::string& s)
{
    if (s.empty()) return false;
    // Kiểm tra nếu có dấu âm ở đầu
    int start = (s[0] == '-') ? 1 : 0;
    // Trường hợp chỉ nhập mỗi dấu "-" là sai
    if (start == 1 && s.length() == 1) return false; 
    //Kiểm tra từng kí tự xem có phải là số không
    for (int i = start; i < s.length(); i++) {
        if (s[i] < '0' || s[i] > '9') return false;
    }
    return true;
}
// Hàm nhập vào số lượng phần tử và tạo ngẫu nhiên các phần tử từ -100 đến 100
void cArray::TaoNgauNhien()
{
    delete []p;
    string a;
    while (1)
    {
        cout<<"Nhap vao so luong phan tu: ";
        getline(cin,a);
        if (isInt(a)&& stoi(a) >= 1) break;
        else cout<<"So dinh phai la so int lon hon hoac bang 1\n";
    }
    n = stoi(a);
    p = new int [n];
    srand(time(NULL));
    for (int i=0; i<n; i++)
        p[i] = rand()% 201 - 100;
}

// Hàm đếm số lần xuất hiện của x
int cArray::DemX()
{
    string s;
    while (1)
    {
        cout<<"Nhap vao so nguyen x: ";
        getline(cin,s);
        if (isInt(s)) break;
        else cout<<"So phai la so int\n";
    }
    int x = stoi(s);
    int count = 0;
    for (int i =0; i<n;i++)
        if (p[i] == x)
            count++;
    return count;
}

// Hàm kiểm tra tính tăng dần của mảng
bool cArray::CheckTang()
{
    for (int i = 1; i < n ;i++)
        if (p[i] < p[i-1])
            return false;
    return true;
}

// Hàm tìm phân tử lẻ nhỏ nhất
int cArray::MinOdd()
{
    int min = -1;
    for (int i =0; i <n; i++)
        if ((p[i] % 2 != 0) && (min == -1 || p[i] < p[min]))
                min = i;
    return min;
}

// Hàm kiểm tra số nguyên tố
bool prime(int x)
{
    if (x < 2) return false;
    for (int i = 2; i*i <= x; i++)
        if (x % i == 0) 
            return false;
    return true;
}

// Hàm tìm số nguyên tố lớn nhất
int cArray::MaxPrime()
{
    int max = -1;
    for (int i =0; i<n; i++)
    {
        if ((prime (p[i])) && ( max == -1 || p[i] > p[max]))
            max = i;
    }
    return max;
}

// Hàm sắp xếp Selection Sort tăng
cArray cArray::SelectionSortTang()
{
    cArray a = *this;
    for (int i =0; i<n; i++)
    {
        int min = i;
        for (int j = i+1; j<n; j++)
            if (a.p[j] < a.p[min])
                min = j;
        swap(a.p[i], a.p[min]);
    }
    return a;
}

// Hàm sắp xếp Selection Sort giảm
cArray cArray::SelectionSortGiam()
{
    cArray a = *this;
    for (int i =0; i<n; i++)
    {
        int max = i;
        for (int j = i+1; j<n; j++)
            if (a.p[j] > a.p[max])
                max = j;
        swap(a.p[i], a.p[max]);
    }
    return a;
}
// Hàm sắp xếp Insertion Sort tăng
cArray cArray::InsertionSortTang()
{
    cArray a = *this;
    for (int i =1; i<n; i++)
    {
        int k = a.p[i];
        int j;
        for (j = i-1; j>= 0; j--)
            if (a.p[j] > k)
            {
                a.p[j+1] = a.p[j];
            }
            else break;
        a.p[++j] = k;
    }
    return a;
} 

// Hàm sắp xếp Insertion Sort giảm
cArray cArray::InsertionSortGiam()
{
    cArray a = *this;
    for (int i =1; i<n; i++)
    {
        int k = a.p[i];
        int j;
        for (j = i-1; j>= 0; j--)
            if (a.p[j] < k)
            {
                a.p[j+1] = a.p[j];
            }
            else break;
        a.p[++j] = k;
    }
    return a;
} 

// Hàm heapify tăng
void heapifytang (int *a, int k, int n)
{
    int j = 2*k+1;
    while (j<n)
    {
        if (j+1<n && a[j] < a[j+1]) j++;
        if (a[k] >= a[j]) return;
        swap (a[k], a[j]);
        k = j;
        j = 2*k+1;
    }
}
// Hàm sắp xếp Heap Sort tăng
cArray cArray:: HeapSortTang()
{
    cArray res = *this;
    int tempSize = res.n; 
    
    // Build heap
    for (int i = (tempSize - 1) / 2; i >= 0; i--)
        heapifytang(res.p, i, tempSize);

    while (tempSize > 1) {
        tempSize--;
        swap(res.p[0], res.p[tempSize]);
        heapifytang(res.p, 0, tempSize);
    }
    return res;      
}

// Hàm heapify giảm
void heapifygiam (int *a, int k, int n)
{
    int j = 2*k+1;
    while (j<n)
    {
        if (j+1<n && a[j] > a[j+1]) j++;
        if (a[k] <= a[j]) return;
        swap (a[k], a[j]);
        k = j;
        j = 2*k+1;
    }
}
// Hàm sắp xếp Heap Sort giảm
cArray cArray:: HeapSortGiam()
{
    cArray res = *this;
    int tempSize = res.n; 
    
    // Build heap
    for (int i = (tempSize - 1) / 2; i >= 0; i--)
        heapifygiam(res.p, i, tempSize);

    while (tempSize > 1) {
        tempSize--;
        swap(res.p[0], res.p[tempSize]);
        heapifygiam(res.p, 0, tempSize);
    }
    return res;       
}
// Hàm sắp xếp Quick Sort đệ quy tăng
void QuickTang(int *a, int left, int right) {
    if (left >= right) return;
    int i = left;
    int j = right;
    int e = a[left + (right - left) / 2]; 
    while (i < j) {
        while (a[i] < e) i++;
        while (a[j] > e) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    QuickTang(a, left, j);
    QuickTang(a, i, right);
}

// Hàm sắp xếp Quick Sort tăng
cArray cArray::QuickSortTang()
{
    cArray a = *this;
    QuickTang (a.p, 0, a.n - 1);
    return a;
}

// Hàm sắp xếp Quick Sort đệ quy giảm
void QuickGiam(int *a, int left, int right) {
    if (left >= right) return;
    int i = left;
    int j = right;
    int e = a[left + (right - left) / 2]; 
    while (i < j) {
        while (a[i] > e) i++;
        while (a[j] < e) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    QuickGiam(a, left, j);
    QuickGiam(a, i, right);
}

// Hàm sắp xếp Quick Sort giảm
cArray cArray::QuickSortGiam()
{
    cArray a = *this;
    QuickGiam (a.p, 0, a.n - 1);
    return a;
}

// Hàm merge tăng trong khoảng từ left đến right
void mergeTang(int *input, int left, int mid, int right)
{
    int i = left, j = mid+1;
    int k = 0;
    int temp[MAXN];
    while (i <=mid && j<=right)
    {
        if (input[i]<input[j]) temp[k++] = input[i++];
        else temp[k++] = input[j++];
    }
    while (i<=mid)
    {
        temp[k++] = input[i++];
    }
    while (j<=right)
    {
        temp[k++] = input[j++];
    }
    for (int q =0; q<k;q++) input[left+q] = temp[q];
}

// Hàm merge sort đệ quy tăng
void mergeSortRangetang(int *input, int from, int to) {
    if (from < to) {
        int middle = (from + to) / 2;
        mergeSortRangetang(input, from, middle);
        mergeSortRangetang(input, middle + 1, to);
        mergeTang(input, from, middle, to);
    }
}
// Hàm sắp xếp merge sort tăng
cArray cArray::MergeSortTang() {

    cArray a = *this;
    mergeSortRangetang (a.p, 0, a.n - 1);
    return a;
}

// Hàm merge giảm trong khoảng từ left đến right
void mergeGiam(int *input, int left, int mid, int right)
{
    int i = left, j = mid+1;
    int k = 0;
    int temp[MAXN];
    while (i <=mid && j<=right)
    {
        if (input[i] > input[j]) temp[k++] = input[i++];
        else temp[k++] = input[j++];
    }
    while (i<=mid)
    {
        temp[k++] = input[i++];
    }
    while (j<=right)
    {
        temp[k++] = input[j++];
    }
    for (int q =0; q<k;q++) input[left+q] = temp[q];
}
// Hàm merge sort đệ quy giảm
void mergeSortRangegiam(int *input, int from, int to) {
    if (from < to) {
        int middle = (from + to) / 2;
        mergeSortRangegiam(input, from, middle);
        mergeSortRangegiam(input, middle + 1, to);
        mergeGiam(input, from, middle, to);
    }
}
// Hàm sắp xếp merge sort giảm
cArray cArray::MergeSortGiam() {
    cArray a = *this;
    mergeSortRangegiam(a.p, 0, a.n - 1);
    return a;
}