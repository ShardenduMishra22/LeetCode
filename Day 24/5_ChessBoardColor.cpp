#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool squareIsWhite(string c) {
        int a = (c[0]-'a');
        int b = (c[1]-'0');

        if((a+b)&1)
            return false;
        return true;
    }
};