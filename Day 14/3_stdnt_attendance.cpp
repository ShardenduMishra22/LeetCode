#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        int num_a = 0;
        for(int i=0;i<s.length();i++){
            if(s[i] == 'A'){
                num_a += 1;
            }
            if(s[i] == 'L' && s[i+1] == 'L' && s[i+2] == 'L'){
                return false;
            }
            if(num_a == 2){
                return false;
            }
        }
        return true;
    }
};