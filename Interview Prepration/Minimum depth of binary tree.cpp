#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

struct node{
    int data;
    struct node *left, *right;
};

node *newnode(int data){
    node * temp = new node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return (temp);
}

int minDepth(node * root){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return 1;
    }

    if(root->left == NULL){
        return minDepth(root->right) + 1;
    }

    if(root->right == NULL){
        return minDepth(root->left) + 1;
    }

    return min(minDepth(root->right), minDepth(root->left)) + 1;
}
 
int main()
{
    fast;
    node *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    cout << minDepth(root) << endl;

    return 0;
}