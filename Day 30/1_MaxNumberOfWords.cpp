#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mostWordsFound(vector<string>& snt) {
        int mx = 0; 
        for(int i=0;i<snt.size();i++){
            int cnt = 0;
            stringstream ss(snt[i]);
            string wrd;
            while(ss >> wrd){
                cnt += 1;
            }
            mx = max(mx,cnt);
        }
        return mx;
    }
};