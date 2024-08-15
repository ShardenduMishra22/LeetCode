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