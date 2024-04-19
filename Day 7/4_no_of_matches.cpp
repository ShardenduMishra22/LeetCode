#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfMatches(int n) {
        int sum = 0;
        while(n != 1){
            if(!(n&1)){
                sum += n / 2;
                n = n / 2;
            }else{
                sum += (n - 1) / 2;
                n = 1  + (n - 1) / 2;
            }
        }
        return sum;
    }
};