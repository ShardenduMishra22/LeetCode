#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    inline bool isVwl(char a){
        a = tolower(a);
        if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') return true;
        return false;
    }
    string reverseVowels(string s) {
        int i = 0;
        int j = s.length() - 1;
        while (i<=j){
            if(isVwl(s[i]) && isVwl(s[j])){
                swap(s[i++],s[j--]);
            }else{
                if(!isVwl(s[i])){
                    i++;
                }
                if(!isVwl(s[j])){
                    j--;
                }
            }
        }
        return s;
    }
};