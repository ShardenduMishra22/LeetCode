#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minLength(string st){
        stack<char>s;
        for(int i=0;i<st.size();i++){
            if(!s.empty() && s.top() == 'A' && st[i] == 'B'){
                s.pop();
            }else if(!s.empty() && s.top() == 'C' && st[i] == 'D'){
                s.pop();
            }else{
                s.push(st[i]);
            }
        }
        return s.size();
    }
};