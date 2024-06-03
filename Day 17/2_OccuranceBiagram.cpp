#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> result;
        stringstream ss(text);
        string word;
        string prev1, prev2;

        while (ss >> word) {
            if (prev1 == first && prev2 == second) {
                result.push_back(word);
            }
            prev1 = prev2;
            prev2 = word;
        }
        return result;
    }
};



// class Solution {
// public:
//     vector<string> findOcurrences(string text, string first, string second) {
//         vector<string> words;
//         string word = "";
//         for (char c : text) {
//             if (c == ' ') {
//                 words.push_back(word);
//                 word = "";
//             } else {
//                 word += c;
//             }
//         }
//         words.push_back(word);

//         vector<string> result;
//         for (int i = 0; i < words.size() - 2; ++i) {
//             if (words[i] == first && words[i + 1] == second) {
//                 result.push_back(words[i + 2]);
//             }
//         }
//         return result;
//     }
// };