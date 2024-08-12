#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reformatNumber(string num) {
        string cleaned = "";
        string ans = "";

        for (char ch : num) {
            if (isdigit(ch)) {
                cleaned += ch;
            }
        }

        int n = cleaned.size();
        int i = 0;

        while (n > 0) {
            if (n > 4) {
                ans += cleaned.substr(i, 3) + "-";
                i += 3;
                n -= 3;
            } else if (n == 4) {
                ans += cleaned.substr(i, 2) + "-" + cleaned.substr(i + 2, 2);
                n = 0;
            } else {
                ans += cleaned.substr(i, n);
                n = 0;
            }
        }
        return ans;
    }
};
