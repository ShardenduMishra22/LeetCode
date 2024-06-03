#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countOperations(int n1, int n2) {
        int cnt = 0;
        while(n1 != 0 && n2 != 0){
            if(n1 > n2){
                n1 = n1 - n2;
                cnt += 1;
            }else{
                n2 = n2 - n1;
                cnt += 1;
            }
        }
        return cnt;
    }
};