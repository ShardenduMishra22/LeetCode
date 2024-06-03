#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& n) {
        map<int,int>m;
        for(int i=0;i<n.size();i++){
            m[n[i]] += 1;
        }
        vector<int> ans;
        for(auto i : m){
            if(i.second == 1){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};