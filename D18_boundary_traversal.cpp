// https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/0

#include <bits/stdc++.h>
using namespace std;
  struct Node {
      int data;
      Node *left;
      Node *right;
      Node() : data(0), left(nullptr), right(nullptr) {}
      Node(int x) : data(x), left(nullptr), right(nullptr) {}
      Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
 };



 //solution 

class Solution {
public:
    bool isLeaf(Node* root){
      if(root->left || root->right){
        return false;
      }
      return true;
    }
    
    void leftboundary(Node* root, vector<int> &ans){
        if(root== NULL){
            return;
        }
        if(!isLeaf(root)){
            ans.push_back(root->data);
        }
        if(root->left != NULL) leftboundary(root->left,ans);
        else if (root->right != NULL) leftboundary(root->right,ans);
    }
    
    
    void leafnodes(Node* root, vector<int> &ans){
        if(isLeaf(root)){
            ans.push_back(root->data);
            return;
        }
        if(root->left) leafnodes(root->left,ans);
        if(root->right) leafnodes(root->right,ans);
    }
    
    
    void rightboundary(Node* root, vector<int> &ans){
        if(root== NULL){
            return;
        }
        vector<int> v;

        if(!isLeaf(root)) v.push_back(root->data);
        if (root->right){rightboundary(root->right,ans);}
        else if (root->left) rightboundary(root->left,ans);
        for(int i = v.size()-1;i>=0;i--){
            ans.push_back(v[i]);
        }
    }
    
    
    
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        
        if(!isLeaf(root)){
            ans.push_back(root->data);
        }
        
        leftboundary(root->left,ans);
        leafnodes(root,ans);
        rightboundary(root->right,ans);
        return ans;
    }
};
