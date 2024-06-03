#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";

        bool isNeg = num < 0;
        if (isNeg)
            num = -num;

        string res = "";
        while (num != 0) {
            res = to_string(num % 7) + res;
            num /= 7;
        }

        if (isNeg)
            res = "-" + res;
            
        return res;
    }
};
