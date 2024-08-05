#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int ans = 0, start = 0, currentCost = 0;
        
        for(int end = 0; end < s.length(); end++) {
            currentCost += abs(s[end] - t[end]);
            while(currentCost > maxCost) {
                currentCost -= abs(s[start] - t[start]);
                start++;
            }
            ans = max(ans,end - start + 1);
        }
        
        return ans;
    }
};