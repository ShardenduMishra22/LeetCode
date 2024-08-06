// class Solution {
// public:
//     int minimumPushes(string word) {
//         vector<int> Alph(26,0);
//         for(char& c : word){
//             Alph[c-'a'] += 1;
//         }
//         sort(Alph.rbegin(),Alph.rend());
//         int total = 0;
//         for(int i=0;i<26;i++){
//             if(!Alph[i]) break;
//             total += ((i/8 + 1)*Alph[i]);
//         }
//         return total;
//     }
// };