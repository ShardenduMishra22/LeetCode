#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        
        while (x != 0 || y != 0){
            int m = x & 1;
            int n = y & 1;
            
            if (m != n) {
                ans++;
            }
            
            x = x >> 1;
            y = y >> 1;
        }
        
        return ans;
    }
};
