// #include<bits/stdc++.h>
// using namespace std;

// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     void solve(vector<vector<int>>& mat, vector<int>& arr) {
//         int Rst = 0;
//         int Cst = 0;
//         int Rend = mat.size() - 1;
//         int Cend = mat[0].size() - 1;
//         int temp = 0;

//         while (Rst <= Rend && Cst <= Cend && temp < arr.size()) {
//             for (int i = Cst; i <= Cend && temp < arr.size(); i++) {
//                 mat[Rst][i] = arr[temp++];
//             }
//             Rst++;
//             for (int i = Rst; i <= Rend && temp < arr.size(); i++) {
//                 mat[i][Cend] = arr[temp++];
//             }
//             Cend--;
//             if (Rst <= Rend) {
//                 for (int i = Cend; i >= Cst && temp < arr.size(); i--) {
//                     mat[Rend][i] = arr[temp++];
//                 }
//                 Rend--;
//             }
//             if (Cst <= Cend) {
//                 for (int i = Rend; i >= Rst && temp < arr.size(); i--) {
//                     mat[i][Cst] = arr[temp++];
//                 }
//                 Cst++;
//             }
//         }
//     }

//     vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
//         ListNode* temp = head;
//         vector<int> arr;
//         while (temp) { 
//             arr.push_back(temp->val);
//             temp = temp->next;
//         }
//         vector<vector<int>> mat(m, vector<int>(n, -1));
//         solve(mat, arr);
//         return mat;
//     }
// };
