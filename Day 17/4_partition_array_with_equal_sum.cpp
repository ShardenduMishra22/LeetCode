#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
        }
        if (sum % 3 != 0) {
            return false;
        }
        
        int temp = 0;
        int target = sum / 3;
        int count = 0;
        
        for (int i = 0; i < arr.size(); i++) {
            temp += arr[i];
            if (temp == target) {
                count++;
                temp = 0;
            }
        }
        
        return count >= 3;
    }
};