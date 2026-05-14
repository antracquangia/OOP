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
// Hàm kiểm tra số double
bool CheckDouble (string s)
{
    bool Dot = 0;
    for (int i =0; i<s.size(); i++)
    {
        if (i == 0 && s[i] == '-') continue;
        else if (s[i] == '.' && Dot == 0)
            Dot = 1;
        else if (s[i] >= '0' && s[i] <= '9') continue;
        else return false; 
    }
    return true;
}