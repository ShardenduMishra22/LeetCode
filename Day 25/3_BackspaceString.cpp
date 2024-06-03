#include<bits/stdc++.h>
using namespace std;


// #include <stack>
// #include <string>

// using namespace std;

// class Solution {
// public:
//     bool backspaceCompare(string s, string t) {
//         stack<char> s1, t1;
        
//         for (int i = 0; i < s.size(); i++) {
//             if (s[i] == '#') {
//                 if (!s1.empty()) {
//                     s1.pop();
//                 }
//             } else {
//                 s1.push(s[i]);
//             }
//         }
        
//         for (int i = 0; i < t.size(); i++) {
//             if (t[i] == '#') {
//                 if (!t1.empty()) {
//                     t1.pop();
//                 }
//             } else {
//                 t1.push(t[i]);
//             }
//         }
        
//         string s2, t2;
//         while (!s1.empty()) {
//             s2 += s1.top();
//             s1.pop();
//         }
//         while (!t1.empty()) {
//             t2 += t1.top();
//             t1.pop();
//         }
        
//         return s2 == t2;
//     }
// };

class Solution {
public:
    string bs(string s){
        string res = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '#'){
                if(res.size() > 0)
                    res.pop_back();
            }else{
                res.push_back(s[i]);
            }
        }
        return res;
    }
    bool backspaceCompare(string s, string t) {
        return bs(s) == bs(t);
    }
};
