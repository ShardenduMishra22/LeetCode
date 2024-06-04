#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int buyChoco(vector<int>&p , int money) {
        sort(p.begin(),p.end());
        if( money - p[0] - p[1]  >= 0){
            return money - p[0] - p[1];
        }else{
            return money;
        }
    }
};

// class Solution {
// public:
//     int buyChoco(vector<int>& prices, int money) {
//         sort(prices.begin(), prices.end());
//         if(prices[0] + prices[1] <= money){
//             return money - (prices[0] + prices[1]);
//         }
//         return money;
//     }
// };