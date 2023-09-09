#include <iostream>
using namespace std;

// multiply every bit with 5^(index of  bit) to get magic number. Example = 6th magic number, 6 in binary = 110 ; 1*5^3+1*5^2+0*5^1;

int NthMagicNumber(int n)
{
    int ans = 0;
    int base = 5;
    while (n > 0)
    {
        int last = n & 1;
        // right shift by 1;
        n = n >> 1;
        ans += last * base;
        base = base * 5;
    }
    return ans;
}