#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> a(n, 0);

        for (int i = n - 2; i >= 0; --i) {
            a[i] = a[i+1];
            if (s[i+1] == 'a') {
                a[i] += 1;
            }
        }

        int b = 0;
        int res = n;

        for (int i = 0; i < n; ++i) {
            res = min(res, b + a[i]);
            if (s[i] == 'b') {
                b += 1;
            }
        }
        return res;
    }
};