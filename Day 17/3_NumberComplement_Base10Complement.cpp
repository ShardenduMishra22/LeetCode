#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bitwiseComplement(int num) {
        if(num == 0){
            return !num;
        }
        int n = 0;
        int bit = 0;
        while (num != 0) {
            int a = num & 1;
            n = n | (!a << (bit));
            num = num >> 1;
            bit++;
        }
        return n;
    }
};

// class Solution {
// public:
//     int findComplement(int num) {
//         int mask = 1;
//         while (mask < num) {
//             mask = (mask << 1) | 1;
//         }
//         return num ^ mask;
//     }
// };