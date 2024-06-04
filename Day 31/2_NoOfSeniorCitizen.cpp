#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSeniors(vector<string>& d) {
        int cnt = 0;
        for(int i=0;i<d.size();i++){
            string s = "";
            s += d[i][11];
            s += d[i][12];

            if(stoi(s) > 60)
                cnt += 1;
        }
        return cnt;             
    }
};