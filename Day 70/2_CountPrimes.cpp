#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        int cnt = 0;
        vector<bool> prm(n + 1, true);
        prm[0] = prm[1] = false;
        for (int i = 2; i < n; i++) {
            if (prm[i]) {
                cnt++;
                for (int j = i * 2; j < n; j = j + i) {
                    prm[j] = 0;
                }
            }
        }
        return cnt;
    }
};