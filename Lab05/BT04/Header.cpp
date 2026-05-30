#include "header.h"
// Hàm kiểm tra xem chuỗi có phải là số nguyên
bool CheckInteger(const string& input)
{
    for (size_t i = 0; i < input.length(); i++)
        if (input[i] < '0' || input[i] > '9')
            return false;
    return true;
}