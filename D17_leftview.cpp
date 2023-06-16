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


//Function to return a list containing elements of left view of the binary tree.
void f(TreeNode* root,int level , vector<int> &v){
    if(root == NULL) return ;
    
    if(v.size() == level ) v.emplace_back(root->val);
    if(root->left) f(root->left, level + 1, v);
    if(root->right) f(root->right, level + 1, v);
}
vector<int> leftView(TreeNode* root)
{
    //using recursion 
    vector<int> v;
    f(root, 0 , v);
    return v;
}
