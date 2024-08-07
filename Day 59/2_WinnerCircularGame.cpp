#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> circle;
        for (int i = 1; i <= n; i++) {
            circle.push_back(i);
        }
        int st_idx = 0;
        while (circle.size() > 1) {
            int removalIndex = (st_idx + k - 1) % circle.size();
            circle.erase(circle.begin() + removalIndex);
            st_idx = removalIndex;
        }
        return circle.front();
    }
};