#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(string word){
        for(int i=0;i<word.size()/2;i++){
            if(word[i] !=word[word.size()-i-1])
                return false;
        }
        return true;
    }

    string firstPalindrome(vector<string>& words) {
        string ans;
        int mn = INT_MAX;
        for(int i=0;i<words.size();i++){
            if(solve(words[i])){
                ans = words[i];
                break;
            }
        }
        return ans;
    }
};