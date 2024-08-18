#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> Next(vector<int>& arr){
        int n = arr.size();
        vector<int> ans(n);
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
        vector<int> ans(n);
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

    int largestRectangleArea(vector<int>& hght){
        int n = hght.size();
        vector<int> next = Next(hght);
        vector<int> prev = Prev(hght);

        int mx = 0;
        for(int i = 0; i < n; i++){
            int l = hght[i];
            int b = next[i] - prev[i] - 1;
            mx = max(mx, l * b);
        }
        return mx;
    }
};

// class Solution {
// public:
//     int largestRectangleArea(vector<int>& hght) {
//         if(hght.size() <= 1){
//             return hght[0];
//         }

//         int mx = *max_element(hght.begin(),hght.end());
//         for(int i = 0;i < hght.size();i++){
//             int mini = hght[i];
//             for(int j = i+1;j < hght.size();j++){
                
//                 mini = min(mini,hght[j]);
//                 mx = max(mx,mini*(j - i + 1));
//             }
//         }
//         return mx;
//     }
// };