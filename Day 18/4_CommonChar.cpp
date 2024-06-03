#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& w) {
        vector<int> MinFreq(26, INT_MAX);
        
        for (auto& j : w) {
            vector<int> ans(26, 0);
            for (char c : j) {
                ans[c - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                MinFreq[i] = min(MinFreq[i], ans[i]);
            }
        }
        
        vector<string> res;
        for (int i = 0; i < 26; i++) {
            while (MinFreq[i]-- > 0) {
                res.push_back(string(1, i + 'a'));
            }
        }
        
        return res;
    }
};