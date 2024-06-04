#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkString(string s) {
        int idx_a = -1,idx_b=-1;
        bool flg = true;
        for(int i=0;i<s.size();i++){
            if(s[i] == 'a'){
                idx_a = i;
            }
            if(flg && s[i] == 'b'){
                idx_b = i;
                flg = false;
            }
        }
        if(idx_b == -1 || idx_a == -1) 
            return true;
        return idx_a < idx_b;
    }
};

