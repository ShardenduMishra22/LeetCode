#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue <int> q;
        for(int i=0;i<stones.size();i++){
            q.push(stones[i]);
        } 
        while(1){
            if(q.size() == 1){
                return q.top();
            }else{
                int a = q.top();
                q.pop();

                int b = q.top();
                q.pop();

                if(q.size() == 0 && a == b){
                    return 0;
                }

                if(a == b){
                    continue;
                }else{
                    q.push(a-b);
                }
            }
        }
    }
}s;