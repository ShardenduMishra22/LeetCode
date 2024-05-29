#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& w) {
        
        string s1 = "qwertyuiopQWERTYUIOP";
        string s2 = "asdfghjklASDFGHJKL";
        string s3 = "zxcvbnmZXCVBNM";
        
        map<char,string> m;
        for(int i=0;i<s1.length();i++){
            m[s1[i]] = "r1";
        }
        for(int i=0;i<s2.length();i++){
            m[s2[i]] = "r2";
        }
        for(int i=0;i<s3.length();i++){
            m[s3[i]] = "r3";
        }

        vector<string> res;
        for(int i=0;i<w.size();i++){
            string z;
            string s = m[w[i][0]];
            for(int j=0;j<w[i].length();j++){
                if(s == m[w[i][j]]){
                    z += w[i][j];
                }else{
                    z = "";
                    break;
                }
            }
            if(!z.empty()){
                res.push_back(z);
            }
        }
        return res;
    }
};