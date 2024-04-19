#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        vector<int> left(n);
        left[0] = h[0];
        for(int i = 1; i < n; i++){
            left[i] = max(h[i], left[i-1]);
        }
        vector<int> right(n);
        right[n-1] = h[n - 1];
        for(int i = n - 2; i >= 0; i--){
            right[i] = max(h[i], right[i+1]);
        }
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += min(right[i], left[i]) - h[i];
        }
        return sum;
    }
};
