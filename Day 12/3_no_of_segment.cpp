#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSegments(string s) {
        int count = 0;
        bool inSegment = false;
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] != ' ' && !inSegment) {
                inSegment = true;
                ++count;
            } else if (s[i] == ' ') {
                inSegment = false;
            }
        }
        
        return count;
    }
};
