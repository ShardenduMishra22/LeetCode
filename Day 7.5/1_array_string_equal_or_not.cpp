#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string str1 = "";
        for(int i = 0; i < word1.size(); i++){
            str1 += word1[i]; 
        }
        string str2 = "";
        for(int i = 0; i < word2.size(); i++){
            str2 += word2[i]; 
        }
        if(str1 == str2) {
            return true;
        }
        return false;
    }
};

//fails if the order of char is different bu the number of a char are overall equal
// class Solution {
// public:
//     bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
//         string str1 = "";
//         for(int i = 0; i < word1.size(); i++){ // Changed .length() to .size()
//             str1 += word1[i]; 
//         }
//         string str2 = "";
//         for(int i = 0; i < word2.size(); i++){ // Changed .length() to .size()
//             str2 += word2[i]; // Changed str1 to str2
//         }
//         vector<int> ans(26,0);
//         for(int i = 0; i < str1.length(); i++){
//             ans[str1[i] - 'a']++;
//         }
//         for(int i = 0; i < str2.length(); i++){
//             ans[str2[i] - 'a']--; // Changed str1 to str2
//         }
//         int sum = 0;
//         for(int i = 0; i < 26; i++){
//             sum += ans[i];
//         }
//         return sum == 0;
//     }
// };