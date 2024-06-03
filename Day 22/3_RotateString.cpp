#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool rotateString(string s,string goal){
        if(s.size()!=goal.size()){
            return false;
        }
        for(int i=0;i<s.size();i++){
            s=s.substr(1,s.size()) + s.substr(0,1);
            if(s == goal){
                return true;
            }
        }
        return false;
    }
};

// Fails if there are repeated elements 
// class Solution {
// public:
//     bool rotateString(string s, string goal) {
//         unordered_map<char, char> mp;
//         int n = s.length();
        
//         for (int i = 0; i < n; ++i) {
//             mp[s[i]] = s[(i + 1) % n];
//         }
        
//         for (int i = 0; i < n; ++i) {
//             if (mp[goal[i]] != goal[(i + 1) % n]) {
//                 return false;
//             }
//         }
        
//         return true;
//     }
// };
