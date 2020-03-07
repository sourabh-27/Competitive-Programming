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

bool checkMirror(node * r1, node * r2){
    cout << "r1->data: " << r1->data << " r2->data: " << r2->data << endl;
    if(r1 == NULL && r2 == NULL){
        return true;
    }
    else if(r1 == NULL || r2 == NULL){
        return false;
    }
    else if(r1->data == r2->data && checkMirror(r1->left, r2) && checkMirror(r1, r2->right)){
        return true;
    }
    else{
        return false;
    }
}

bool isSymmetric(node * root){
    if(root == NULL){
        return true;
    }
    cout << "Hey I am at : " << root->data << endl;
    return checkMirror(root->left, root->right); 
}


 
int main()
{
    fast;
    node *root = newnode(10);
    // root->left = newnode(2);
    // root->right = newnode(2);
    // root->left->left = newnode(20);
    // root->left->right = newnode(1);
    // root->right->left = newnode(1);
    // root->right->right = newnode(20);
    bool ans = isSymmetric(root);
    cout << "ans: " << ans << endl;
    // cout << root->data << " " << root->left->data << " " << root->right->data << " " << root->left->left->data << " " << root->left->right->data << " " << root->right->left->data << " " << root->right->right->data << endl;
    // cout << "ans: " << ans << endl;


    return 0;
}