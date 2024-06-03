#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int duplicateNumbersXOR(vector<int>& n) {
        map<int,int>m;
        for(int i=0;i<n.size();i++){
            m[n[i]] += 1;
        }
        int ans = 0;
        for(auto i : m){
            if(i.second > 1){
                ans = ans ^ i.first;
            }
        }
        return ans;
    }
};