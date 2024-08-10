#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& og, vector<char>& chng, vector<int>& cst) {
        vector<vector<int>> dist(26, vector<int>(26, INT_MAX));
        
        for(int i = 0; i < cst.size(); i++){
            dist[og[i] - 'a'][chng[i] - 'a'] = min(dist[og[i] - 'a'][chng[i] - 'a'], cst[i]);
        }

        for(int k = 0; k < 26; k++) {
            for(int i = 0; i < 26; i++) {
                for(int j = 0; j < 26; j++) {
                    if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        long long cost = 0;

        for(int i = 0; i < source.size(); i++) {
            if(source[i] == target[i]) continue;
            int mn_cost = dist[source[i] - 'a'][target[i] - 'a'];
            if(mn_cost == INT_MAX) return -1; 
            cost += mn_cost;
        }
        return cost;
    }
};
