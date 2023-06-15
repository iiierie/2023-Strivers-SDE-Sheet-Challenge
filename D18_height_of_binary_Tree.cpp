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



// height using  recursion 

    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);


        return 1 + max(left,right);

    }

    
// time: O(N)
// space : O(1) + O(H) for ASS; H = height of binary tree


//using level order traversal
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int height = 0;
        queue<TreeNode*> q;
        q.push(root);
       
        while(!q.empty()){
            height ++;
            int size = q.size();
            
            for(int i = 0;i<size;i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left != NULL)q.push(temp->left);
                if(temp->right != NULL)q.push(temp->right);
                } 
            }
        
        return height;
    }
    
// time: O(N)
// space : O(N) for queue