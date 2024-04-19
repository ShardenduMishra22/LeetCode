#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& v) {
        int n = v.size();
        for(int i = n-1; i >= 0; i--){
            if(i == n-1)
                v[i]++;
            if(v[i] == 10){
                v[i] = 0;
                if(i != 0){
                    v[i-1]++;
                }
                else{
                    v.push_back(0);
                    v[i] = 1;
                }
            }
        }
        return v;
    }
};

// Does not work for very large numbers
// class Solution {
// public:
//     vector<int> plusOne(vector<int>& digits) {
//         int num = 0;
//         stack <int>st;
//         for (int i = 0;i < digits.size() ;i++){
//             num = num*10 + digits[i]; 
//         }
//         num = num + 1; 
//         while (num != 0){
//             int a = num % 10;
//             st.push(a);
//             num /= 10;
//         }
//         vector<int> ans;
//         while (!st.empty()){
//             ans.push_back(st.top());
//             st.pop();
//         }
//         return ans;
//     }
// };