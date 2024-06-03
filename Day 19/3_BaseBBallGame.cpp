#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> s;
        for (int i = 0; i < ops.size(); i++) {
            if (ops[i] == "C") {
                s.pop();
            } else if (ops[i] == "D") {
                s.push(s.top() * 2);
            } else if (ops[i] == "+") {
                int top1 = s.top();
                s.pop();
                int top2 = s.top();
                s.push(top1);
                s.push(top1 + top2);
            } else {
                s.push(stoi(ops[i]));
            }
        }
        int sum = 0;
        while (!s.empty()) {
            sum += s.top();
            s.pop();
        }
        return sum;
    }
};
