#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> minVec(n);

        for(int i = 0; i < n; i++) {
            string time = timePoints[i];
            int hour = stoi(time.substr(0, 2));
            int minu = stoi(time.substr(3));

            minVec[i] = hour * 60 + minu;
        }

        sort(minVec.begin(), minVec.end());
        int res = INT_MAX;
        
        for(int i = 1; i < n; i++) {
            res = min(res, minVec[i] - minVec[i - 1]);
        }

        return min(res, (24 * 60 - minVec[n - 1] + minVec[0]));
    }
};
