#include <vector>
using namespace std;

class Solution {
public:
    long long cmb(int n, int k) {
        if (k > n - k) {
            k = n - k;
        }
        long long res = 1;
        for (int i = 0; i < k; i++) {
            res *= (n - i);
            res /= (i + 1);
        }
        return res;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j <= i; j++) {
                ans[i].push_back(cmb(i, j));
            }
        }
        return ans;
    }
};
