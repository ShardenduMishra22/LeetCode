#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        int ans = 0;
        for(int i=1;i<=n;i++){
            n = n - i;
            if(n < 0){
                break;
            }
            ans += 1; 
        }
        return ans;
    }
};