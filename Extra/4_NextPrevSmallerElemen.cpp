#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
static auto _ = [] () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

vector<int> NextSmaller(vector<int>& arr) {
    stack<int> st;
    st.push(-1);
    int n = arr.size();
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--) {
        int curr = arr[i];
        while (st.top() >= curr) {
            st.pop();
        }
        ans[i] = st.top();
        st.push(curr);
    }
    return ans;
}

vector<int> PrevSmaller(vector<int>& arr) {
    stack<int> st;
    st.push(-1);
    int n = arr.size();
    vector<int> ans(n);
    for (int i = 0; i < n; i++){
        int curr = arr[i];
        while (st.top() >= curr){
            st.pop();
        }
        ans[i] = st.top();
        st.push(curr);
    }
    return ans;
}

int main() {
    vector<int> arr = {5,3,4,1,8,9,0};
    vector<int> next = NextSmaller(arr);
    vector<int> prev = PrevSmaller(arr);

    for (int i : next) {
        cout << i << " ";
    }
    cout<<endl;

    for (int i : prev) {
        cout << i << " ";
    }
    cout<<endl;

    return 0;
}
