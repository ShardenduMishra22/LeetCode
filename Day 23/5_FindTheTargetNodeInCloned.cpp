#include<bits/stdc++.h>
using namespace std;


 
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(!cloned) return nullptr;
        if(cloned->val == target->val)
            return cloned;

        cloned->left = getTargetCopy(original, cloned->left, target);
        cloned->right = getTargetCopy(original, cloned->right, target);

        if(cloned->right != NULL)
            return cloned->right;

        if(cloned->left != NULL)
            return cloned->left;

        return nullptr;
    }
};