#include <bits/stdc++.h>
using namespace std;

#define frb(i, len) for(int i = len-1; i >= 0; i--)
#define fr(i, len) for(int i = 0; i < len; i++)

#define rvrs(a) reverse(a.begin(),a.end())
#define srt(a) sort(a.begin(),a.end())

#define YES cout<<"Yes \n";
#define NOO cout<<"No  \n";
#define nl cout<<"\n";

#define MAX_SIZE 10000
#define nptr nullptr

typedef stringstream strgm;
typedef long long int ll;
typedef const int c_int;
typedef unsigned unsg;
typedef double dbl;

typedef vector<vector<string>> vvstr;
typedef vector<vector<bool>> vvbl;
typedef vector<vector<int>> vvint;
typedef vector<vector<ll>> vvll;

typedef vector<string> vstr;
typedef vector<int> vint;
typedef vector<bool> vbl;
typedef vector<ll> vll;

typedef stack<string> sstr;
typedef stack<bool> sbl;
typedef stack<int> sint;
typedef stack<ll> sll;

typedef queue<string> qstr;
typedef queue<bool> qbl;
typedef queue<int> qint;
typedef queue<ll> qll;

c_int MOD = 1e9 + 7;
c_int Mx_row = 100;
c_int Mx_col = 100;
int size_stack = 0;
int InvrsnCnt = 0;
int size_arr = 0;
int size_ll = 0;
int top = -1;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

class Solution {
public:
    int solve(vector<int>& day, vector<int>& cost, int idx) {
        int n = day.size();
        vector<int> dp(n + 1, 0); 

        for (int k = n - 1; k >= 0; k--) {
            int op1 = cost[0] + dp[k + 1];

            int i;
            for (i = k; i < n && day[i] < day[k] + 7; i++);
            int op2 = cost[1] + dp[i];

            for (i = k; i < n && day[i] < day[k] + 30; i++);
            int op3 = cost[2] + dp[i];

            dp[k] = min(op1, min(op2, op3));
        }

        return dp[0]; 
    }

    int mincostTickets(vector<int>& day, vector<int>& cost) {
        return solve(day, cost, 0);
    }
};



// class Solution {
// public:
//     int solve(vector<int>& day, vector<int>& cost,int idx,vector<int>& dp){
//         int n = day.size();
//         if(idx >= n){
//             return 0;
//         }
//         if(dp[idx] != -1){
//             return dp[idx];
//         }

//         int op1 = cost[0] + solve(day,cost,idx+1,dp);

//         int i;
//         for(i = idx;i < n && day[i] < day[idx]+7;i+=1);
//         int op2 = cost[1] + solve(day,cost,i,dp);

//         for(i = idx;i < n && day[i] < day[idx]+30;i+=1);
//         int op3 = cost[2] + solve(day,cost,i,dp);

//         dp[idx] = min(op1,min(op2,op3));
//         return dp[idx];
//     }

//     int mincostTickets(vector<int>& day, vector<int>& cost) {
//         int idx = 0;
//         vector<int> dp(day.size()+1,-1);
//         return solve(day,cost,idx,dp);
//     }
// };

// class Solution {
// public:
//     int solve(vector<int>& day, vector<int>& cost,int idx){
//         int n = day.size();
//         if(idx >= n){
//             return 0;
//         }
//         int op1 = cost[0] + solve(day,cost,idx+1);

//         int i;
//         for(i = idx;i < n && day[i] < day[idx]+7;i+=1);
//         int op2 = cost[1] + solve(day,cost,i);

//         for(i = idx;i < n && day[i] < day[idx]+30;i+=1);
//         int op3 = cost[2] + solve(day,cost,i);

//         return min(op1,min(op2,op3));
//     }

//     int mincostTickets(vector<int>& day, vector<int>& cost) {
//         int idx = 0;
//         return solve(day,cost,idx);
//     }
// };

// class Solution {
// public:
//     int solve(vector<int>& day, vector<int>& cost,int idx,vector<int>& dp){
//         int n = day.size();
//         if(idx >= n){
//             return 0;
//         }
//         if(dp[idx] != -1){
//             return dp[idx];
//         }

//         int op1 = cost[0] + solve(day,cost,idx+1,dp);

//         int i;
//         for(i = idx;i < n && day[i] < day[idx]+7;i+=1);
//         int op2 = cost[1] + solve(day,cost,i,dp);

//         for(i = idx;i < n && day[i] < day[idx]+30;i+=1);
//         int op3 = cost[2] + solve(day,cost,i,dp);

//         dp[idx] = min(op1,min(op2,op3));
//         return dp[idx];
//     }

//     int mincostTickets(vector<int>& day, vector<int>& cost) {
//         int idx = 0;
//         vector<int> dp(day.size()+1,-1);
//         return solve(day,cost,idx,dp);
//     }
// };

// class Solution {
// public:
//     int solve(vector<int>& day, vector<int>& cost,int idx){
//         int n = day.size();
//         if(idx >= n){
//             return 0;
//         }
//         int op1 = cost[0] + solve(day,cost,idx+1);

//         int i;
//         for(i = idx;i < n && day[i] < day[idx]+7;i+=1);
//         int op2 = cost[1] + solve(day,cost,i);

//         for(i = idx;i < n && day[i] < day[idx]+30;i+=1);
//         int op3 = cost[2] + solve(day,cost,i);

//         return min(op1,min(op2,op3));
//     }

//     int mincostTickets(vector<int>& day, vector<int>& cost) {
//         int idx = 0;
//         return solve(day,cost,idx);
//     }
// };