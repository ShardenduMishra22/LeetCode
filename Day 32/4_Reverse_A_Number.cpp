#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN)
            return 0; 
         
        bool is_negative = x < 0;
        x = abs(x); 
        
        int reversed = 0;
        while (x) {
            if (reversed>INT_MAX/10 || (reversed == INT_MAX/10 && x%10 > 7)){
                return 0; 
            }
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }

        return is_negative ? -reversed : reversed;
    }
};
