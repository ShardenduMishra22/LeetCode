#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int LenStr = chars.length();
        unordered_map<char,int> ans;
        for(int i = 0; i < LenStr; i++){
            ans[chars[i]]++;
        }
        int sum = 0;
        for(int i = 0; i < words.size(); i++){
            int freq[26] = {0};
            bool flag = false;
            for(int j = 0; j < words[i].length(); j++){
                freq[words[i][j] - 'a']++;
                if(freq[words[i][j] - 'a'] > ans[words[i][j]]){
                    flag = true;
                    break;
                }
            }
            if(!flag){
                sum += words[i].length();
            }
        }
        return sum;
    }
};
