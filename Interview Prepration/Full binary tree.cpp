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

bool isFullTree(node *temp)
{
    if(temp == NULL){
        return true;
    }
    if(temp->left == NULL && temp->right == NULL){
        return true;
    }

    if(temp->left != NULL && temp->right != NULL){
        return (isFullTree(temp->left) && isFullTree(temp->right));
    }
    return false;
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
    root->right->right->left = newnode(3);
    root->right->right->right = newnode(4);

    if (isFullTree(root)) 
        printf("The Binary Tree is full\n"); 
    else
        printf("The Binary Tree is not full\n"); 

    return 0;
}