#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
inline bool CheckDouble( string s)
{
    bool NumDot = 0;
    for (int i =0; i<s.size(); i++)
    {
        if (i == 0 && s[i] == '-') continue;
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
#endif