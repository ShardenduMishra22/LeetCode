#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words){
        vector<bool>vec(26,false);
        for(auto &i:allowed)
        {
            vec[i-'a']=true;
        }
        int ans=0;
        for(auto &word:words)
        {
            bool flag=true;
            for(auto &ch:word)
            {
                if(!vec[ch-'a'])
                {
                    flag=false;
                    break;
                }
            }
            ans+=flag;
        }
        return ans;
    }
};

// class Solution {
// public:
//     int countConsistentStrings(string alw, vector<string>& words) {
//         map<char,bool> m;
//         for(auto i : alw)
//             m[i] = true;

//         int cnt = 0;
//         for(int i=0;i<words.size();i++){
//             bool flg = true; 
//             for(int j=0;j<words[i].size();j++){
//                 if(m[words[i][j]] == false){
//                     flg = false;
//                     break; 
//                 }
//             }
//             if(flg){
//                 cnt += 1;
//             }
//         }
//         return cnt;
//     }
// };
