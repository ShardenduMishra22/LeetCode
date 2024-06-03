#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int appendCharacters(string s, string t) {
        int j=0;
        for(int i = 0;i<s.size();i++){
            if(t[j] == s[i]){
                j++;
            }
        }
        if(j == t.size()){
            return 0;
        }
        return t.size() - j ;
    }
};

// same code using while loop 
// class Solution {
// public:
//     int appendCharacters(string s, string t) {
//         int first = 0, longestPrefix = 0;
//         while (first < s.length()) {
//             if (s[first] == t[longestPrefix]) {
//                 longestPrefix++;
//             }
//             first++;
//         }
//         return t.length() - longestPrefix;
//     }
// };