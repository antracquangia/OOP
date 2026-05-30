#include "header.h"
// Hàm kiểm tra số nguyên không âm
bool CheckInt (string s)
{
    for (const char i : s)
        if (i < '0' || i > '9')
            return 0;
    return 1;
}
// Hàm kiểm tra số double
bool CheckDouble( string s)
{
    bool NumDot = 0;
    for (int i =0; i<s.size(); i++)
    {
        if (s[i] == '.' ) 
        {
            if (NumDot)
                return false;
            NumDot = 1;
        }
        else if (s[i] >= '0' && s[i] <= '9') continue;
        else return false; 
    }
    return true;
}
