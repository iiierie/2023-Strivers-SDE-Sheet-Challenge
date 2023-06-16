#include <bits/stdc++.h>
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
    vector <int> bottomView(TreeNode *root){
        vector<int> result;
        if(root == NULL) return result;
        
        queue<pair<TreeNode*, int>> q;
            // q: {treenode, vertical}
        
        map <int,int> mp;
            // mp: {vertical, val}
        
        q.push({root, 0});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            TreeNode* temp = it.first;
            int v = it.second;
            
            //if already present then just overwrite
            if(mp.find(v) == mp.end()){
                mp[v] = temp->val;
                
            }
            else{
                mp.erase(v);
                mp[v] = temp->val;
                
            }
            
            
            if(temp->left) q.push({temp->left, v-1});
            if(temp->right) q.push({temp->right, v+1});
        }
        
        // push to result
        for(auto it:mp){
            result.push_back(it.second);
        }
        
        return result;
        
    }
};
