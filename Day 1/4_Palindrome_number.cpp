#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(long long x){
        if (x < 0) return false;
        long long num = 0,dummy = x;
        while(dummy != 0){
            long long m = dummy % 10;
            num = num*10 + m;
            dummy /= 10;
        }
        return !(num - x);
    }
};