#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> t(n + 1);
        t[1] = 1;

        int t2 = 1, t3 = 1, t5 = 1;
        for (int i = 2; i <= n; i++) {
            int scnd = t[t2] * 2;
            int thrd = t[t3] * 3;
            int ftfh = t[t5] * 5;

            t[i] = min({scnd, thrd, ftfh});

            if (t[i] == scnd) t2++;
            if (t[i] == thrd) t3++;
            if (t[i] == ftfh) t5++;
        }
        return t[n];
    }
};