#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        // if(s.empty()) return 0;
        int len = 0;
        for(int i = s.length() - 1; i >= 0; i--){
            if(isalpha(s[i])){
                len++;
            }
            if(isalpha(s[i]) && (i == 0 || s[i - 1] == ' ')) break;
        }
        return len;
    }
};
