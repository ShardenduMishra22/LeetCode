#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;
        vector<string> words;
        string word = "";
        
        for (int i = 0; i <= s.length(); i++) {
            if (i == s.length() || s[i] == ' ') {
                words.push_back(word);
                word = "";
            } else {
                word += s[i];
            }
        }
        
        if (words.size() != pattern.size()) return false;
        
        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            string w = words[i];
            
            if (charToWord.count(c)) {
                if (charToWord[c] != w) return false;
            } else {
                if (wordToChar.count(w)) {
                    if (wordToChar[w] != c) return false;
                }
                
                charToWord[c] = w;
                wordToChar[w] = c;
            }
        }
        
        return true;
    }
};
