#include <bits/stdc++.h>
using namespace std;


// class Solution {
// public:
//     vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
//         int n = arr.size();

//         vector<int> PrfXOR(n,0);
//         PrfXOR[0] = arr[0];

//         for(int i=1;i<arr.size();i++){
//             PrfXOR[i] = PrfXOR[i-1] ^ arr[i]; 
//         }

//         vector<int> res;
//         for(auto& i : queries){
//             int l = i[0];
//             int r = i[1];

//             int xor_val = PrfXOR[r] ^ (l == 0 ? 0 : PrfXOR[l-1]);
//             res.push_back(xor_val);
//         }

//         return res;
//     }
// };

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> res;

        for (auto& q : queries) {
            int xor_val = 0;
            for (int i = q[0]; i <= q[1]; i++) {
                xor_val ^= arr[i];
            }
            res.push_back(xor_val);
        }

        return res;
    }
};
