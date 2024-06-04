#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> alph(52, 0);
        for (char i : s) {
            if (islower(i))
                alph[i - 'a'] += 1;
            else
                alph[i - 'A' + 26] += 1;
        }
        int cnt = 0;
        for (int i = 0; i < 52; i++) {
            if (!(cnt & 1)) {
                cnt += alph[i];
                alph[i] = 0;
            } else {
                cnt += alph[i] - 1;
                alph[i] = 1;
            }
        }
        for (int i : alph) {
            if (i == 1) {
                cnt += 1;
                break;
            }
        }
        return cnt;
    }
};
