#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int CountSetBits(int n){
        int count = 0; 
        while(n){
            n = n & (n - 1);
            count++;
        }
        return count;
    }

    vector<int> sortByBits(vector<int>& arr) {
        map<int, int>mp;

        for(int i = 0; i < arr.size(); i++){
            int SetBits = CountSetBits(arr[i]);
            mp[arr[i]] = SetBits;
        }   

        sort(arr.begin(), arr.end(),[&](int a , int b){
            if(mp[a] == mp[b])
                return a < b;

            return mp[a] < mp[b];
        });
        return arr;
    }
};