#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str2.length() > str1.length())
            return gcdOfStrings(str2, str1);

        if (str1 == str2)
            return str1;

        if (str1.substr(0, str2.length()) == str2)
            return gcdOfStrings(str1.substr(str2.length()), str2);
        
        return "";
    }
};


// class Solution {
// public:
//     string gcdOfStrings(string str1, string str2) {
//         return (str1 + str2 == str2 + str1) ? str1.substr(0, gcd(size(str1),size(str2))):"";
//     }
// };

// class Solution {
// public:
//     string gcdOfStrings(string str1, string str2) {
        
//         string gcd = "";
//         int l1 = str1.length();        
//         int l2 = str2.length();        

//         for(int i = 1; i < min(l1, l2) + 1; i++ ){       
//             if( l1 % i == 0 && l1 % i == 0 ){
                
//                 string sub = str1.substr(0, i);
//                 string s1; string s2;
                
//                 for( int j = 0; j < l1 / i; j++){
//                     s1 += sub;
//                 }
//                 for( int j = 0; j < l2 / i; j++){
//                     s2 += sub;
//                 }
//                 if( s1 == str1 && s2 == str2 ){
//                     gcd = sub;
//                 }
//             }
//         }

//     return gcd;

//     }
// };