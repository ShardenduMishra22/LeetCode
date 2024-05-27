#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {
        int mx = INT_MIN;
        for (int i = 0;i < num.length() - 2;i++){
            if(num[i] == num[i+1] && num[i] == num[i+2]){
                string temp;
                temp[0] = num[i]; 
                temp[1] = num[i+1]; 
                temp[2] = num[i+2];
                int n = stoi(temp);
                mx = max(mx,n);
            }
        }
        if(mx == INT_MIN){
            return "";
        }else if(mx == 0){
            return "000";
        }
        string s = to_string(mx);
        return s;
    }
};