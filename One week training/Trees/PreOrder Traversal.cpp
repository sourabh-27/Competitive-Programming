#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

struct node{
    int data;
    node *left, *right;
};

node *newnode(int data){
    node *temp = new node;
    temp->data = data;
    temp->left = temp->right = NULL;
}

void preOrderTraversal(node * root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void preOrderStack(node * root){
    if(root == NULL){
        return;
    }
    stack<ll> st;
    st.push(root->data);
    while(!st.empty()){
        
    }
}
 
int main()
{
    fast;
    node *root = newnode(10);
    root->left = newnode(2);
    root->right = newnode(10);
    root->left->left = newnode(20);
    root->left->right = newnode(1);
    root->right->right = newnode(-25);
    root->right->left = newnode(6);
    root->right->right->right = newnode(3);
    // root->right->right->right->right = newnode(32);  

    preOrderTraversal(root);

    preOrderStack(root);

    // pair<ll, ll> ans2 = maxDiameter(root);
    // cout << "Maximum diamter of tree is: " << ans2.first << endl;

    // cout << root->data << " " << root->left->data << " " << root->right->data << " " << root->left->left->data << " " << root->left->right->data << " " << root->right->left->data << " " << root->right->right->data << endl;
    // cout << "ans: " << ans << endl;


    return 0;
}