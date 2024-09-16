#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> m;
        int mask = 0;
        m[mask] = -1;

        int result = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a') {
                mask ^= (1 << 0);
            } else if (s[i] == 'e') {
                mask ^= (1 << 1); 
            } else if (s[i] == 'i') {
                mask ^= (1 << 2);
            } else if (s[i] == 'o') {
                mask ^= (1 << 3);
            } else if (s[i] == 'u') {
                mask ^= (1 << 4);
            }

            if (m.find(mask) != m.end()) {
                result = max(result, i - m[mask]);
            } else {
                m[mask] = i;
            }
        }
        
        return result;
    }
};

// class Solution {
// public:
//     int findTheLongestSubstring(string s) {
//         unordered_map<string, int> m;
//         string currState = "00000"; 
//         m[currState] = -1;
//         vector<int> state(5, 0);
//         int result = 0;

//         for (int i = 0; i < s.size(); i++) {
//             if (s[i] == 'a') {
//                 state[0] = (state[0] ^ 1);
//             } else if (s[i] == 'e') {
//                 state[1] = (state[1] ^ 1);
//             } else if (s[i] == 'i') {
//                 state[2] = (state[2] ^ 1);
//             } else if (s[i] == 'o') {
//                 state[3] = (state[3] ^ 1);
//             } else if (s[i] == 'u') {
//                 state[4] = (state[4] ^ 1);
//             }

//             currState = "";
//             for (int j = 0; j < 5; j++) {
//                 currState += to_string(state[j]);
//             }

//             if (m.find(currState) != m.end()) {
//                 result = max(result, i - m[currState]);
//             } else {
//                 m[currState] = i;
//             }
//         }
//         return result;
//     }
// };


// class Solution {
// public:
//     int findTheLongestSubstring(string s) {
//         unordered_map<string, int> m;
//         string currState = "00000"; 
//         m[currState] = -1;
//         vector<int> state(5, 0);
//         int result = 0;

//         for (int i = 0; i < s.size(); i++) {
//             if (s[i] == 'a') {
//                 state[0] = (state[0] ^ 1);
//             } else if (s[i] == 'e') {
//                 state[1] = (state[1] ^ 1);
//             } else if (s[i] == 'i') {
//                 state[2] = (state[2] ^ 1);
//             } else if (s[i] == 'o') {
//                 state[3] = (state[3] ^ 1);
//             } else if (s[i] == 'u') {
//                 state[4] = (state[4] ^ 1);
//             }

//             currState = "";
//             for (int j = 0; j < 5; j++) {
//                 currState += to_string(state[j]);
//             }

//             if (m.find(currState) != m.end()) {
//                 result = max(result, i - m[currState]);
//             } else {
//                 m[currState] = i;
//             }
//         }
//         return result;
//     }
// };