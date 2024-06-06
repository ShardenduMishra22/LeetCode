#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dv, int ds) {
        if(dv == ds)
            return 1;

        bool sign = false;
        if((dv > 0 && ds < 0)||(dv < 0 && ds > 0)) 
            sign = true;

        long n = abs(dv);
        long d = abs(ds);

        ds = abs(ds);
        int q = 0;
        while(n >= d){
            int cnt = 0;
            while(n >= (d << (cnt+1))){
                cnt += 1;
            }
            q += 1<<cnt;
            n -= (d<<cnt);
        }
        if(q == (1<<31) && sign)
            return INT_MIN;

        if(q == (1<<31) && !sign)
            return INT_MAX;

        return sign ? -q : q ;

    }
};