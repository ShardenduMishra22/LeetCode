#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
static auto _ = [] () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

void SortInsert(stack<int>& s, int num) {
    if (s.empty() || s.top() <= num) {
        s.push(num);
        return;
    }
    int top = s.top();
    s.pop();
    SortInsert(s, num);
    s.push(top);
}

void SortStack(stack<int>& s) {
    if (s.empty()) {
        return;
    }
    int num = s.top();
    s.pop();
    SortStack(s);
    SortInsert(s, num);
}

int main() {
    stack<int> s;
    for (int i = 0; i < 5; ++i) {
        int x;
        cin >> x;
        s.push(x);
    }
    SortStack(s);

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}
