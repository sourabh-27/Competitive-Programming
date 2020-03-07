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

node * LCA(node * root, ll first, ll sec){
    if(root == NULL){
        return NULL;
    }
    if(root->data == first || root->data == sec){
        return root;
    }
    node * ans1 = LCA(root->left, first, sec);
    node * ans2 = LCA(root->right, first, sec);
    if(ans1 == NULL){
        return ans2;
    }
    else if(ans2 == NULL){
        return ans1;
    }
    else{
        return root;
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
    node * ans = LCA(root, 10, 6);
    cout << "The lowest common ancestor is: " << ans->data << endl;
    // cout << "Height of tree: " << ans << endl;

    // cout << root->data << " " << root->left->data << " " << root->right->data << " " << root->left->left->data << " " << root->left->right->data << " " << root->right->left->data << " " << root->right->right->data << endl;
    // cout << "ans: " << ans << endl;


    return 0;
}