#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> m;
        for(int i = 0; i < arr.size(); i++) {
            m[arr[i]] += 1;
        }
        
        vector<int> occ;
        for(auto it = m.begin(); it != m.end(); ++it) {
            occ.push_back(it->second);
        }
        
        sort(occ.begin(), occ.end());
        for(int i = 1; i < occ.size(); i++) {
            if(occ[i] == occ[i-1]) return false;
        }
        
        return true;
    }
};
