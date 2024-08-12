#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& dst, int start, int dstn) {
        int n = dst.size();
        int ans1 = 0;
        int ans2 = 0;

        int i = start;
        while(i != dstn){
            ans1 += dst[i];
            i = (i + 1)%n;
        }

        int j = dstn;
        while(j != start){
            ans2 += dst[j];
            j = (j + 1)%n;
        }
        return min(ans1,ans2);
    }
};