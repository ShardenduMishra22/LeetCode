#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValid(vector<vector<int>>& mat) {
        int n = mat.size();
        for(int i=0; i<n; i++){
            set<int> s;
            for(int j=0; j<n; j++){
                s.insert(mat[i][j]);
            }
            if(s.size() != n)
                return false;
        }
        for(int i=0; i<n; i++){
            set<int> s;
            for(int j=0; j<n; j++){
                s.insert(mat[j][i]);
            }
            if(s.size() != n)
                return false;
        }
        return true;
    }
};


// Fails in case where all the elements eventually add up to the sum 
// Example : [[2,2,2],[2,2,2],[2,2,2]]                            
//                                                                
// class Solution {
// public:
//     bool checkValid(vector<vector<int>>& mat) {
//         int sum = (1 + mat[0].size()) * mat[0].size() / 2; 
//         for(int i=0;i<mat.size();i++){
//             int sm = 0;
//             for(int j=0;j<mat[0].size();j++){
//                 sm += mat[i][j];
//             }
//             if(sm != sum)
//                 return false;
//         }
//         for(int i=0;i<mat.size();i++){
//             int sm = 0;
//             for(int j=0;j<mat[0].size();j++){
//                 sm += mat[j][i];
//             }
//             if(sm != sum)
//                 return false;
//         }
//         return true;
//     }
// };

// Fails because it doesent check all the rows 
// class Solution {
// public:
//     bool checkValid(vector<vector<int>>& mat) {
//         int sum = (1 + mat[0].size()) * mat[0].size() / 2; 
//         for(int i=0;i<mat.size();i++){
//             int sm = 0;
//             for(int j=0;j<mat[0].size();j++){
//                 sm += mat[i][j];
//             }
//             if(sm != sum)
//                 return false;
//         }
//         return true;
//     }
// };