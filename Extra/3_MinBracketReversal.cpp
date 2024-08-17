#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
static auto _ = [] () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

int solve(string& s){
    stack<char> st;
    for(int i=0;i<s.size();i++){
        if(s[i] == '('){
            st.push(s[i]);
        }else{
            if(s[i] == ')' && st.top() == '('){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
    }
    int a = 0;
    int b = 0;
    while(!st.empty()){
        if(st.top() == '('){
            a += 1;
        }else{
            b += 1;
        }
        st.pop();
    }
    return ((a+1)/2 + (b+1)/2);
}

int main(){
    string s1 = "}{}{";
    string s2 = "}}}}";
    string s3 = "{{{{";

    cout<<solve(s1)<<endl;
    cout<<solve(s2)<<endl;
    cout<<solve(s3)<<endl;

    return 0;
}