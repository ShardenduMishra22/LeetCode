#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> Next(vector<int>& arr){
        int n = arr.size();
        vector<int> ans(n, n);
        stack<int> st;
        st.push(n);
        for(int i = n - 1; i >= 0; i--){
            int curr = arr[i];
            while(st.top() != n && arr[st.top()] >= curr){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    
    vector<int> Prev(vector<int>& arr){
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;
        st.push(-1);
        for(int i = 0; i < n; i++){
            int curr = arr[i];
            while(st.top() != -1 && arr[st.top()] >= curr){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    int Area_Histogram(vector<int>& heights){
        int n = heights.size();
        vector<int> next = Next(heights);
        vector<int> prev = Prev(heights);

        int mx = 0;
        for(int i = 0; i < n; i++){
            int height = heights[i];
            int width = next[i] - prev[i] - 1;
            mx = max(mx, height * width);
        }

        return mx;
    }

    int maximalRectangle(vector<vector<char>>& mat) {
        if(mat.empty()) return 0;
        
        int m = mat.size();
        int n = mat[0].size();
        
        vector<int> prev(n, 0);
        vector<int> curr(n, 0);

        int mx = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == '0'){
                    curr[j] = 0;
                } else {
                    curr[j] = 1 + prev[j];
                }
            }
            mx = max(mx, Area_Histogram(curr));
            prev = curr;
        }
        return mx;
    }
};