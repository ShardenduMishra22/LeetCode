#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string capitalizeTitle(string t) {
        stringstream ss(t);
        string ans, word;
        while (ss >> word) {
            for (int i = 0; i < word.size(); i++) {
                word[i] = tolower(word[i]);
            }
            if (word.size() > 2) {
                word[0] = toupper(word[0]);
            } else {
                word[0] = tolower(word[0]);
            }
            ans += word + " ";
        }
        if (!ans.empty()) {
            ans.pop_back(); 
        }
        return ans;
    }
};
