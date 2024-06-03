#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum = 0;
        for(int i=0;i<apple.size();i++)
            sum += apple[i];
        
        sort(capacity.begin(),capacity.end());
        int cnt = 0;
        for(int i=capacity.size()-1;i>=0;i--){
            if(sum <= 0){
                break;
            }
            cnt += 1;
            sum -= capacity[i];
        }
        return cnt;
    }
};