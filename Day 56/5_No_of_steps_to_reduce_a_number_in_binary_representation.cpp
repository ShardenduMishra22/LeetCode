// class Solution {
// public:
//     int numSteps(string s) {
//         int n = s.size(),carry = 0,ans = 0,val = 0;

//         for(int i =n-1;i >= 1;i -= 1){
//             if(s[i] - '0' + carry == 1){
//                 ans += 2;
//                 carry = 1;
//             }else{
//                 ans += 1;
//             }
//         }
//         return carry + ans;
//     }
// };