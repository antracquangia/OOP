#include "header.h"
// Hàm kiểm tra số nguyên
bool CheckInt( string s)
{
    for (int i =0; i<s.size(); i++)
    {
        if (i == 0 && s[i] == '-') continue;
        else if (s[i] >= '0' && s[i] <= '9') continue;
        else return false; 
    }
    return true;
}