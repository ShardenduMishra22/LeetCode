#include<bits/stdc++.h>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& desc){
        unordered_map<int, TreeNode*> m;
        unordered_set<int> Child;
        for(auto vect : desc){
            int prnt = vect[0];
            int child = vect[1];
            int isLeft = vect[2];

            if(m.find(prnt) == m.end()){
                m[prnt] = new TreeNode(prnt);
            }

            if(m.find(child) == m.end()){
                m[child] = new TreeNode(child);
            }

            if(isLeft == 1){
                m[prnt]->left = m[child];
            }else{
                m[prnt]->right = m[child];
            }
            Child.insert(child);
        }

        for(auto vec : desc){
            int prnt = vec[0];
            if(Child.find(prnt) == Child.end()){
                return m[prnt];
            }
        }
        return nullptr;
    }
};