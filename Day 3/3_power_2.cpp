#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        while(n != 0){
            int m = n&1;
            n = n >> 1;
            if(n == 0 && m == 1) return true;
            if(n != 0 && m == 1) return false;
        }
        return false;
    }
};