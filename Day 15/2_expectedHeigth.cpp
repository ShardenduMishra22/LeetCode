#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> ans(heights);
        sort(ans.begin(),ans.end());
        int a = 0;
        for(int i=0;i<heights.size();i++){
            if(heights[i] != ans[i]){
                a += 1;
            }
        }
        return a;
    }
};
