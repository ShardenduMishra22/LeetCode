#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int d=0,md = 0;
        stack<int>st;
        for(int i=0;i<s.length();i++){
            if(s[i] == '('){
                st.push(s[i]);
                d += 1;
                md = max(d,md);
            }else if(s[i] == ')'){
                st.pop();
                d -= 1;
            }
        }
        return md;
    }
};