#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
static auto _ = [] () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

bool RdntBrkt(const string& s) {
    stack<char> st;
    for (char ch : s) {
        if (ch == '(') {
            st.push(ch);
        } else if (ch == ')') {
            bool redundant = true;
            while (!st.empty() && st.top() != '(') {
                st.pop();
                redundant = false;
            }
            st.pop(); 
            if (redundant) {
                return true;
            }
        } else {
            st.push(ch);
        }
    }
    return false; 
}

int main() {
    string s = "((e+f)*(c+d))-(a+b)";
    bool RdntBracket = RdntBrkt(s);
    if (RdntBracket) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}
