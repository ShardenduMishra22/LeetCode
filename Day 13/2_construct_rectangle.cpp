#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> constructRectangle(int area) {
        int n = sqrt(area);
        vector<int> ans(2);
        for (int i = n; i >= 1; i--) {
            if (area % i == 0) {
                int width = i;
                int length = area / i;
                ans[0] = max(length, width);
                ans[1] = min(length, width);
                break; 
            }
        }
        return ans;
    }
};
