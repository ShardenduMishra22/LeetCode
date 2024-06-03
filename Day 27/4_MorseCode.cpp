#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> ref = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> ans;
        for(int i = 0; i < words.size(); i++) {
            string morseCode;
            for(int j = 0; j < words[i].size(); j++) {
                morseCode += ref[words[i][j] - 'a'];
            }
            ans.insert(morseCode);
        }
        return ans.size();
    }
};