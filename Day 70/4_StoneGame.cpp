#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool stoneGame(vector<int>& tiles) {
        int n = tiles.size();
        int cnt1 = 0;
        int cnt2 = 0;
        int total = accumulate(tiles.begin(), tiles.end(), 0);

        for(int i=0;i<n;i+=2){
            cnt1 += tiles[i];
        }
        
        for(int i=1;i<n;i+=2){
            cnt2 += tiles[i];
        }       

        return cnt1 > total-cnt1 || cnt2 > total-cnt2; 
    }
};