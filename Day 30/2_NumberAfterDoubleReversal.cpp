#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int num){
        int ans = 0;
        while(num!=0){
            ans = ans*10 + num%10;
            num /= 10;
        }
        return ans;
    }

    bool isSameAfterReversals(int num) {
        int a = solve(solve(num));
        return a == num;
    }
};