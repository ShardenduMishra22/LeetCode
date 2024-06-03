#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int N = code.size();
        vector<int> ans(N, 0);

        if (k == 0) {
            return ans;
        }

        if (k > 0) {
            for (int i = 0; i < N; i++) {
                int sum = 0;
                for (int j = 1; j <= k; j++) {
                    sum += code[(i + j) % N];
                }
                ans[i] = sum;
            }
        } else {
            for (int i = 0; i < N; i++) {
                int sum = 0;
                for (int j = 1; j <= -k; j++) {
                    sum += code[(i - j + N) % N];
                }
                ans[i] = sum;
            }
        }

        return ans;
    }
};