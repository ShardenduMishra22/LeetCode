#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int ransomNoteSize = ransomNote.size();
        int magazineSize = magazine.size();
        if (ransomNoteSize > magazineSize) {
            return false;
        }
        int characters_occurrences[26] = {0};
        for (int i = 0; i < magazineSize; i++) {
            characters_occurrences[magazine[i] - 97]++;
        }
        for (int i = 0; i < ransomNoteSize; i++) {
            if (characters_occurrences[ransomNote[i] - 97] == 0) {
                return false;
            }
            characters_occurrences[ransomNote[i] - 97]--;
        }
        return true;
    }
};


// #include <string>
// #include <map>

// using namespace std;

// class Solution {
// public:
//     bool canConstruct(string r, string m) {
//         map<string, int> mp;
//         for (int i = 0; i < m.length(); i++) {
//             mp[m.substr(i, 1)]++; 
//         }
//         for (int i = 0; i < r.length(); i++) {
//             mp[r.substr(i, 1)]--; 
//         }
//         for (auto i : mp) {
//             if (i.second < 0) return false;
//         }
//         return true;
//     }
// };