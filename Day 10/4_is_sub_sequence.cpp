#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sl = s.length();
        int tl = t.length();
        
        if (sl > tl) return false;
        else if (sl == tl) return s == t;
        else {
            int i = 0;
            int j = 0;

            while (i < sl && j < tl) {
                if (s[i] == t[j]) {
                    i++;
                }
                j++;
            }
            
            return i == sl;
        }
    }
};



// Fails when the element are present but arent in the same sequence in t as in s

// class Solution {
// public:
//     bool isSubsequence(string s, string t) {
//         int sl = s.length();
//         int tl = t.length();
//         if(sl>tl) return false;
//         else if (sl == tl) return s == t;
//         else{
//             map <char,int>m;
//             for(int i=0;i<tl;i++){
//                 m[t[i]]++;
//             }
//             for(int i=0;i<sl;i++){
//                 if(m[s[i]] <= 0){
//                     return false;
//                 }
//                 m[s[i]]--;
//             }
//         }
//         return true;
//     }
// };