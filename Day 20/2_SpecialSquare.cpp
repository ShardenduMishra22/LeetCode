#include<bits/stdc++.h>
using namespace std;

class{
    private:
    bool isSpecial(int row, int col , int n , int m, vector<vector<int>>& mat){
        for(int i = 0 ; i < n ; i++){
            if(mat[i][col] == 1 && i != row){
                return false;
            }
        }
        for(int i = 0 ; i < m ;i++){
            if(mat[row][i] == 1 && i!= col){
                return false;
            }
           
        }
        return true;
    }
public:
    int numSpecial(vector<vector<int>>& mat){

        int count = 0 ;
        int n = mat.size();
        int m = mat[0].size();

        for(int row = 0 ; row < n ; row++){
            for(int col = 0 ; col < m ; col++){
                if(mat[row][col] == 1){
                    if(isSpecial(row , col , n , m,mat)){
                        count++;
                    }
                }
            }
        }

        return count;
        
    }
};

// class{
// public:
//     bool check(vector<vector<int>>& mat, int i, int {
//         int up = i - 1, dn = i + 1;
//         int l = j - 1, r = j + 1;
//         int rr = mat.size();
//         int rc = mat[0].size();
        
   
//         while (up >= {
//             if (mat[up][j] == {
//                 return false;
//             }
//             up--;
//         }
        
     
//         while (dn < r{
//             if (mat[dn][j] == {
//                 return false;
//             }
//             dn++;
//         }
        

//         while (l >= {
//             if (mat[i][l] == {
//                 return false;
//             }
//             l--;
//         }
        
       
//         while (r < r{
//             if (mat[i][r] == {
//                 return false;
//             }
//             r++;
//         }
        
//         return true;
//     }

//     int numSpecial(vector<vector<int>>& ma{
//         int cnt = 0;
//         for (int i = 0; i < mat.size(); {
//             for (int j = 0; j < mat[0].size(); {
//                 if (mat[i][j] == 1 && check(mat, i, {
//                     cnt++;
//                 }
//             }
//         }
//         return cnt;
//     }
// };
