#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> left(n, n);
        vector<int> right(n, n);
        vector<int> ans(n);      

        int lastPos = -n;
        for (int i = 0; i < n; i++) {
            if (s[i] == c) {
                lastPos = i;
            }
            left[i] = i - lastPos;
        }

        lastPos = 2 * n;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == c) {
                lastPos = i;
            }
            right[i] = lastPos - i;
        }

        for (int i = 0; i < n; i++) {
            ans[i] = min(left[i], right[i]);
        }

        return ans;
    }
};