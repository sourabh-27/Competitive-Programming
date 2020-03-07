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

ll level = -1;
void leftView(node * root, ll currLevel){
    if(root == NULL){
        return;
    }
    if(currLevel > level){
        cout << root->data << " " << endl;
        level++;
    }
    leftView(root->left, currLevel + 1);
    leftView(root->right, currLevel + 1);

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
    leftView(root, 0);

    // pair<ll, ll> ans2 = maxDiameter(root);
    // cout << "Maximum diamter of tree is: " << ans2.first << endl;

    // cout << root->data << " " << root->left->data << " " << root->right->data << " " << root->left->left->data << " " << root->left->right->data << " " << root->right->left->data << " " << root->right->right->data << endl;
    // cout << "ans: " << ans << endl;


    return 0;
}