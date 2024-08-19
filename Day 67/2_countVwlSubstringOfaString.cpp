#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isVwl(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    int solve(string& wrd, int st, int end) {
        int cnt = 0;
        map<char, int> m;
        int start = st;
        
        for (int i = st; i <= end; i++) {
            m[wrd[i]] += 1;
            if (m.size() == 5){
                int k = start;
                while (m.size() == 5) {
                    m[wrd[k]] -= 1;
                    if (m[wrd[k]] == 0) {
                        m.erase(wrd[k]);
                        break;
                    }
                    k++;
                }
                int prf = k - start + 1;
                int sfx = end - i + 1;
                cnt += prf * sfx;
                start = k + 1;
            }
        }
        return cnt;
    }

    int countVowelSubstrings(string wrd) {
        int cnt = 0;
        for (int i = 0; i < wrd.size(); i++) {
            if (!isVwl(wrd[i])) continue;
            int j = i + 1;
            while (j < wrd.size() && isVwl(wrd[j])) {
                j++;
            }
            cnt += solve(wrd, i, j - 1);
            i = j;
        }
        return cnt;
    }
};

// class Solution {
// public:
//     bool isVwl(char c) {
//         return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
//     }

//     int countVowelSubstrings(string w) {
//         int cnt = 0;
//         for(int i=0;i<w.size();i++){
//             unordered_set<char>set;
//             for(int j=i;j<w.size();j++){
//                 if(!isVwl(w[j])){
//                     break;
//                 }
//                 set.insert(w[j]);
//                 if(set.size() == 5){
//                     cnt += 1;
//                 }
//             }
//         }
//         return cnt;
//     }
// };