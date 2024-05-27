#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num){
        long long i=1,j=num;
        while(i<=j){
            long long m = i + (j-i)/2;
            if(m*m == num){
                return true;
            }else if(m*m < num){
                i = m+1;
            }else{
                j = m-1;
            }
        }
        return false;
    }

    // bool isPerfectSquare(int num) {
    //     int n = sqrt(num);
    //     return (n*n == num);
    // }
};