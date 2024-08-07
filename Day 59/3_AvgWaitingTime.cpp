#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& cstmr) {
        int PrvTimeCmpl = 0;
        double total_wait = 0;
        int cnt = cstmr.size();
        
        for(int i = 0; i < cnt; i++){
            if(PrvTimeCmpl > cstmr[i][0]){
                total_wait += (PrvTimeCmpl - cstmr[i][0]) + cstmr[i][1];
                PrvTimeCmpl += cstmr[i][1];
            } else {
                total_wait += cstmr[i][1];
                PrvTimeCmpl = cstmr[i][0] + cstmr[i][1];
            }
        }
        
        return total_wait / cnt;
    }
};