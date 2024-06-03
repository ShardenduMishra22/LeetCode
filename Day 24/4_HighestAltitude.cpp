#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int mx = INT_MIN;
        int curr = 0;
        for(auto i : gain){
            mx = max(curr,mx);
            curr += i;
        }
        return max(mx,curr);
    }
};