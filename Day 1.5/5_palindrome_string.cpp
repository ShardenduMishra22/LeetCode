#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for (char c : s) {
            if (isalnum(c)) { // Check if c is alphanumeric
                str.push_back(tolower(c));
            }
        }
        int i = 0, j = str.length() - 1;
        while (i < j) {
            if (str[i++] != str[j--]) {
                return false;
            }
        }
        return true;
    }
};