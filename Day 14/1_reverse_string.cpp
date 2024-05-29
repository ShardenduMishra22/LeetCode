#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        for(int start = 0; start < n; start += 2*k){
            int end = min(start + k -1, n - 1 );
            reverse(s.begin() + start,s.begin()+end+1);
        }
        return s;
    }
};