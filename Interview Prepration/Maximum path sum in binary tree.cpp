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

int findMaxUtil(node * root, int &res){
    if(root == NULL){
        return 0;
    }

    int l = findMaxUtil(root->left, res);
    int r = findMaxUtil(root->right, res);

    int maxi2 = max(max(l, r) + root->data, root->data);
    int maxi = max(maxi2, l + r + root->data);

    res = max(res, maxi);
    return maxi2;
}

int findMaxSum(node * root){
    int res = INT_MIN;
    findMaxUtil(root, res);
    return res;
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
    root->right->right->left = newnode(3);
    root->right->right->right = newnode(4);
    cout << findMaxSum(root) << endl; 

    return 0;
}