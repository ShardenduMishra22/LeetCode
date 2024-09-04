#include<bits/stdc++.h>
using namespace std;
    
class Solution {
public:
    int robotSim(vector<int>& cmds, vector<vector<int>>& obst) {
        int mx = INT_MIN;
        int x = 0;
        int y = 0;

        unordered_map<string,int> mp;
        for(auto i : obst){
            string crd = to_string(i[0]) + "+" +  to_string(i[1]);
            mp[crd] += 1;
        }

        vector<vector<int>> direction = {{-1,0},{0,1},{1,0},{0,-1}};
        int dir = 1;
        for(int i : cmds){
            if(i == -1){
                dir = (dir + 1) % 4;
            }else if(i == -2){
                if(dir == 0){
                    dir = 3;
                }else{
                    dir -= 1;
                }
            }else{
                int k = i;
                for(int i = 1;i <= k;i++){
                    int nx = x + direction[dir][0];
                    int ny = y + direction[dir][1];
                    
                    string Crd_Check = to_string(nx) + "+" +  to_string(ny);
                    if(mp.find(Crd_Check) != mp.end()){
                        break;
                    }
                    x = nx;
                    y = ny;
                    mx = max(mx,x*x+y*y);
                }
            }
        }
        return mx == INT_MIN ? 0 : mx;
    }
};