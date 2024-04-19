#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isHappy(long long num) {
        long long slow = num;
        long long fast = num;
        
        do {
            slow = calculateSum(slow);
            fast = calculateSum(calculateSum(fast));
            if (fast == 1) return true;
        } while (slow != fast); 
        return false;
    }
    
    long long calculateSum(long long n) {
        long long sum = 0;
        while (n != 0) {
            long long digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }
};
