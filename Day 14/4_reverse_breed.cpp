#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int i=0;
        int j=0;
        while(j!=s.size()+1){
            if(s[j] == ' ' || j == s.size()){
                reverse(s.begin()+i,s.begin()+j);
                i=j+1;
            }
            j++;
        }
        return s;
    }
};

// class Solution {
// public:
//     string reverseWords(string s) {
//         string rev = "";
//         string ans = "";
//         for (int i = 0; i < s.length(); i++) {
//             if (s[i] == ' ') {
//                 reverse(rev.begin(), rev.end());
//                 ans += rev;
//                 ans += " "; 
//                 rev = "";
//             } else {
//                 rev += s[i];
//             }
//         }
//         reverse(rev.begin(), rev.end());
//         ans += rev;
//         return ans;
//     }
// };

