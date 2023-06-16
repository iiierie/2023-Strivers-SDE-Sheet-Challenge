#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    //constructor
    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};



node* create_a_tree_from_vector(vector<int> vec, int i){
    node* newnode = NULL;
    
    if(i < vec.size()){
        newnode = new node(vec[i]);
        int child = 2*i;
    newnode->left = create_a_tree_from_vector(vec,child+1);
    newnode->right = create_a_tree_from_vector(vec,child+2);
    }
    return newnode;
}

void pre_in_post_in_one(node* root, vector<int> &pre,vector<int> &in,vector<int> &post){
    if(root == NULL) return;

    stack<pair<node*,int>> st;
    st.push({root,1});


    while(!st.empty()){
        auto it = st.top();
        st.pop();

        if(it.second == 1){
            //pre
            pre.emplace_back(it.first->data);
            it.second++;
            st.push(it);

            if( it.first->left != NULL ){
                st.push({it.first->left,1});
            }}


        else if(it.second == 2){
            //in order
            in.emplace_back(it.first->data);
            it.second++;
            st.push(it);

            if( it.first->right != NULL ){
                st.push({it.first->right,1});
            }}
        else{
            post.emplace_back(it.first->data);
        }
    }
}

void print(vector<int> v){
    for(int i = 0;i<v.size();i++)
        cout<<v[i]<<" ";

    cout<<endl;
}

int main(){
    vector<int> vec = {1,2,3,4,5,6,7};
    node* root = create_a_tree_from_vector(vec,0);

    vector<int> pre, in, post;
    pre_in_post_in_one(root,pre,in,post);

    print(pre);
    print(in);
    print(post);
    

    
}