#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>&img) {
        vector<vector<int>> ans;
        vector<int> res;
        for(int i=0;i<img.size();i++){
            for(int j=0;j<img[0].size();j++){
                if(img[i][j]){
                    res.push_back(0);
                }else{
                    res.push_back(1);
                }
            }
            reverse(res.begin(),res.end());
            ans.push_back(res);
            res = {};
        }
        return ans;
    }
};