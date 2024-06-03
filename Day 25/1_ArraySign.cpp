#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int num = 1;
        int CntNeg = 0;
        for(auto i : nums){
            if(i == 0) return 0;
            if(i < 0)
                CntNeg += 1;
        }        
        if(CntNeg&1) 
            return -1;
        return 1;
    }
};

// Fails for Large Numbers
// class Solution {
// public:
//     long long signFunc(long long n){
//         if(!n) return 0;
//         if(n>0) return 1;
//         return -1;
//     }

//     int arraySign(vector<int>& nums) {
//         long long num = 1;
//         for(auto i:nums)
//             num *= i;
//         return signFunc(num);
//     }
// };

// Fails for Large Numbers
// class Solution {
// public:
//     long long signFunc(long long n){
//         if(!n) return 0;
//         if(n>0) return 1;
//         return -1;
//     }

//     int arraySign(vector<int>& nums) {
//         long long num = 1;
//         for(auto i:nums)
//             num *= i;
//         return signFunc(num);
//     }
// };