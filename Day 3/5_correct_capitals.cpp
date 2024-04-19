#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.length() == 1) return true;
        for(int i = 1;i < word.length() ;i++){
            if( islower(word[i]) && isupper(word[i+1])) return false;
            if( islower(word[i+1]) && isupper(word[i])) return false;
        }
        if(isupper(word[0]) && isupper(word[1])) return true;
        if((isupper(word[0]) || islower(word[0])) && islower(word[1])) return true;
        return false;
    }
};