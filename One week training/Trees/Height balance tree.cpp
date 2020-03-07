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

map<node*, ll> htMap;

int getHeight(node * root){
    if(root == NULL){
        return 0;
    }
    ll h1 = getHeight(root->left);
    ll h2 = getHeight(root->right);
    htMap.insert({root, 1 + max(h1, h2)});
    return 1 + max(h1, h2);
}

bool ans = true;
void CHB(node * root){
    if(root == NULL){
        return;
    }
    ll h1 = getHeight(root->left);
    ll h2 = getHeight(root->right);
    if(abs(h1 - h2) > 1){
        ans = false;
        return;
    }
    CHB(root->left);
    CHB(root->right);
}

pair<ll, bool> AVL(node * root){
    if(root == NULL){
        return {0, 1};
    }
    pair<ll, bool> h1 = AVL(root->left);
    pair<ll, bool> h2 = AVL(root->right);
    if(abs(h1.first - h2.first) <= 1 && h1.second && h2.second){
        return {1 + max(h1.first, h2.first), true};
    }
    else{
        return {1 + max(h1.first, h2.first), false};
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
    getHeight(root);
    CHB(root);
    cout << "The tree is : (balanced/not balanced): " << ans << endl;

    cout << "Now trying using pair" << endl;
    pair<ll, bool> ans = AVL(root);
    cout << "The tree is: " << ans.second << endl;

    // pair<ll, ll> ans2 = maxDiameter(root);
    // cout << "Maximum diamter of tree is: " << ans2.first << endl;

    // cout << root->data << " " << root->left->data << " " << root->right->data << " " << root->left->left->data << " " << root->left->right->data << " " << root->right->left->data << " " << root->right->right->data << endl;
    // cout << "ans: " << ans << endl;


    return 0;
}