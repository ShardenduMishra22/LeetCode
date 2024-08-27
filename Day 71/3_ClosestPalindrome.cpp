#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(long long left,bool even){
        long long res = left;
        if(!even){
            left /= 10;
        }
        while(left > 0){
            res = res*10 + left%10;
            left /= 10;
        }
        return res;
    }

    string nearestPalindromic(string n) {
        int len = n.size();
        int i = (!(len&1)) ? len/2-1 : len/2;

        long long FrstHlf = stoll(n.substr(0,i+1));
        vector<long long> ans;
        ans.push_back(solve(FrstHlf,!(len&1)));
        ans.push_back(solve(FrstHlf + 1,!(len&1)));
        ans.push_back(solve(FrstHlf - 1,!(len&1)));
        ans.push_back((long long)pow(10,len-1)-1);
        ans.push_back((long long)pow(10,len)+1);

        long long diff = LLONG_MAX, res = 0,nl = stoll(n);
        for(auto i : ans){
            if(i == nl){
                continue;
            }
            if(abs(i - nl) < diff){
                diff = abs(i - nl);
                res = i;
            }else if(abs(i - nl) == diff){
                res = min(res,i);
            }
        }

        return to_string(res);
    }
};