#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26);
        for(auto c: s){
            freq[c-'a']++;
        }
        for(int i = 0; i < s.size(); i++){
            if(freq[s[i]-'a'] == 1){
                return i;
            }
        }
        return -1;
    }
};

// class Solution {
// public:
//     int firstUniqChar(string s) {
//         map<char, int> m; 
//         for (int i = 0; i < s.length(); i++) {
//             m[s[i]]++;
//         }

//          for (int i = 0; i < s.length(); i++) {
//             if (m[s[i]] == 1) {
//                 return i; 
//             }
//         }

//         return -1;
//     }
// };
