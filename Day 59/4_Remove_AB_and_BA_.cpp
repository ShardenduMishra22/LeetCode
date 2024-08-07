#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int score = 0;

    string removePairs(string s, char first, char second, int cost) {
        string result;
        for (char c : s) {
            if (!result.empty() && result.back() == first && c == second) {
                result.pop_back();
                score += cost;
            } else {
                result.push_back(c);
            }
        }
        return result;
    }

    int maximumGain(string s, int x, int y) {
        if (x > y) {
            s = removePairs(s, 'a', 'b', x);
            s = removePairs(s, 'b', 'a', y);
        } else {
            s = removePairs(s, 'b', 'a', y);
            s = removePairs(s, 'a', 'b', x);
        }
        return score;
    }
};