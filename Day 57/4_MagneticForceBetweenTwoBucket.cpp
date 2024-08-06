#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool PossibleToPlace(int mid, const vector<int>& posn, int m) {
        int cnt = 1;
        int last_position = posn[0];

        for (int i = 1; i < posn.size(); i++) {
            if (posn[i] - last_position >= mid) {
                cnt += 1;
                last_position = posn[i];
            }
            if (cnt >= m) {
                return true;
            }
        }
        return false;
    }

    int maxDistance(vector<int>& posn, int m) {
        sort(posn.begin(),posn.end());
        int n = posn.size();
        int MnDst = 1;
        int ans = 0;
        int MxDst = posn[n - 1] - posn[0];
        while(MnDst <= MxDst){
            int mid = MnDst + (MxDst - MnDst)/2;
            if(PossibleToPlace(mid,posn,m)){
                MnDst = mid + 1;
                ans = mid;
            }else{
                MxDst = mid - 1;  
            }
        }
        return ans;
    }
};