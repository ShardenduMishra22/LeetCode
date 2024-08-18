#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
    int n = prices.size();
    vector<int> ans(prices);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() > prices[i]) {
            st.pop();
        }
        if (!st.empty()) {
            ans[i] -= st.top();
        }
        st.push(prices[i]);
    }

    return ans;
}

};
