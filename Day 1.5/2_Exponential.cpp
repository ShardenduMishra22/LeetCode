#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(n < 0) {
            x = 1 / x;
        } 
        long num = labs(n);
        double pow = 1;
        while(num){ 
            if(num & 1) {
                pow *= x;
            }
            
            x *= x;
            num >>= 1;
        }
        return pow;
    }
};

// BAD APPROACH / USE FAST EXPONENTIAL

// #include <cmath>
// class Solution {
// public:
//     double myPow(double x, long long n) {
//         if (n == 0) return 1;
//         if (n < 0) {
//             x = 1 / x;
//             n = -n;
//         }
//         double result = 1;
//         while (n > 0) {
//             if (n % 2 == 1) {
//                 result *= x;
//             }
//             x *= x;
//             n /= 2;
//         }
//         return result;
//     }
// };