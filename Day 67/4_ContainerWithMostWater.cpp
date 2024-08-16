#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxArea(vector<int>& hght) {
        int i = 0;
        int j = hght.size()-1;
        int mx = INT_MIN;
        while(i < j){
            mx = max(mx,min(hght[i],hght[j])*(j-i));
            if(hght[i] < hght[j]){
                i += 1;
            }else{
                j -= 1;
            }
        }
        return mx;
    }

    // int maxArea(vector<int>& hght) {
    //     int mx = INT_MIN;
    //     for(int i=0;i<hght.size();i++){
    //         for(int j=0;j<hght.size();j++){
    //             if(i == j) continue;
    //             mx = max(mx,min(hght[i],hght[j])*(j-i));
    //         }
    //     }
    //     return mx;
    // }
};