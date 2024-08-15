// class Solution {
// public:
//     void solve(int idx, int trg, vector<int>& cndt, vector<vector<int>>& arr, vector<int>& ds) {
//         if (trg == 0) {
//             arr.push_back(ds);
//             return;
//         }
//         if (idx == cndt.size() || trg < 0) return;
        
//         if (cndt[idx] <= trg) {
//             ds.push_back(cndt[idx]);
//             solve(idx, trg - cndt[idx], cndt, arr, ds); 
//             ds.pop_back(); 
//         }
//         solve(idx + 1, trg, cndt, arr, ds);
//     }

//     vector<vector<int>> combinationSum(vector<int>& cndt, int trg) {
//         vector<vector<int>> arr;
//         vector<int> ds;
//         solve(0, trg, cndt, arr, ds);   
//         return arr;
//     }
// };