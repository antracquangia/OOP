#ifndef cArray_h
#define cArray_h
class cArray
{
    private:
        int n;
        int *p;
    public:
        cArray();
        cArray(int a, int *b);
        cArray(const cArray &a);
        cArray operator= (const cArray &a);
        ~cArray();
        int &operator[] (int i);
        void TaoNgauNhien();
        void Xuat();        
        int DemX();
        bool CheckTang();
        int MinOdd();
        int MaxPrime();
        cArray SelectionSortTang();
        cArray SelectionSortGiam();
        cArray InsertionSortTang();
        cArray InsertionSortGiam();
        cArray HeapSortTang();
        cArray HeapSortGiam();
        cArray QuickSortTang();
        cArray QuickSortGiam();
        cArray MergeSortTang();
        cArray MergeSortGiam();
};
#endif
