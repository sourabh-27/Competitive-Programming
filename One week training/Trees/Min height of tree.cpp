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

// int minHeight(node * root){ //else to make the code clean than simply return INT_MAX
//     if(root == NULL){ //first time call karenge tab shyd null 
//         return 0;
//     }
//     if(root->left == NULL && root->right == NULL){
//         return 1;
//     }
//     else if(root->left == NULL){
//         return 1 + minHeight(root->right);
//     }
//     else if(root->right == NULL){
//         return 1 + minHeight(root->left);
//     }
//     else{
//         return 1 + min(minHeight(root->left), minHeight(root->right));
//     }
// }

int minHeight(node * root){ //else to make the code clean than simply return INT_MAX
    if(root == NULL){ //first time call karenge tab shyd null 
        return INT_MAX;
    }
    else if(root->left == NULL && root->right == NULL){
        return 1;
    }
    return 1 + min(minHeight(root->left), minHeight(root->right));
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
    int ans = minHeight(root);
    cout << "Minimum Height of tree: " << ans << endl;

    // cout << root->data << " " << root->left->data << " " << root->right->data << " " << root->left->left->data << " " << root->left->right->data << " " << root->right->left->data << " " << root->right->right->data << endl;
    // cout << "ans: " << ans << endl;


    return 0;
}