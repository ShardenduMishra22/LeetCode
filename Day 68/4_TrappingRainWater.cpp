#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getLeft(const vector<int>& hght) {
        vector<int> left(hght.size());
        int mx = hght[0];
        left[0] = mx;
        for (int i = 1; i < hght.size(); i++) {
            mx = max(mx, hght[i]);
            left[i] = mx;
        }
        return left;
    }

    vector<int> getRight(const vector<int>& hght) {
        vector<int> right(hght.size());
        int mx = hght[hght.size() - 1];
        right[hght.size() - 1] = mx;
        for (int i = hght.size() - 2; i >= 0; i--) {
            mx = max(mx, hght[i]);
            right[i] = mx;
        }
        return right;
    }

    int trap(const vector<int>& hght) {
        if(hght.empty()) return 0;
        vector<int> left = getLeft(hght);
        vector<int> right = getRight(hght);

        int sum = 0;
        for (int i = 0; i < hght.size(); i++) {
            int h = min(left[i], right[i]) - hght[i];
            sum += h;
        }

        return sum;
    }
};