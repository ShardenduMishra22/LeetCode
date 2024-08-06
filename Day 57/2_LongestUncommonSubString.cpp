#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(const string& str, const string& s) {
        int j = 0;
        for (char ch : s) {
            if (ch == str[j]) {
                j++;
                if (j == str.size()) return true;
            }
        }
        return false;
    }
    
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end(), [](const string& a, const string& b) {
            return a.size() > b.size();
        });
        
        for (int i = 0; i < strs.size(); ++i) {
            bool is_unique = true;
            for (int j = 0; j < strs.size(); ++j) {
                if (i != j && strs[i].size() <= strs[j].size() && isSubsequence(strs[i], strs[j])) {
                    is_unique = false;
                    break;
                }
            }
            if (is_unique) return strs[i].size();
        }
        
        return -1;
    }
};