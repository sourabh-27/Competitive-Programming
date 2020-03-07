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

int getDiameter(node * root){
    if(root == NULL){
        return 0;
    }
    ll h1 = getDiameter(root->left);
    ll h2 = getDiameter(root->right);
    htMap.insert({root, 1 + max(h1, h2)});
    return 1 + max(h1, h2);
}

ll maxDia(node * root){
    if(root == NULL){
        return 0;
    }
    int ans1 = 1 + htMap[root->left] + htMap[root->right];
    int ans2 = htMap[root->left];
    int ans3 = htMap[root->right];
    return max(ans1, max(ans2, ans3));
}

pair<ll, ll> maxDiameter(node * root){ //the excellent method to find the diameter
    if(root == NULL){
        return {0, 0};
    }
    ll ans1 = 1 + maxDiameter(root->left).second + maxDiameter(root->right).second;
    ll ans2 = maxDiameter(root->left).first;
    ll ans3 = maxDiameter(root->right).first;
    ll dia = max(ans1, max(ans2, ans3));
    ll hei = 1 + max(maxDiameter(root->left).second, maxDiameter(root->right).second);
    return {dia, hei};
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
    getDiameter(root);
    int ans = maxDia(root);
    cout << "Height of tree: " << ans << endl;

    pair<ll, ll> ans2 = maxDiameter(root);
    cout << "Maximum diamter of tree is: " << ans2.first << endl;

    // cout << root->data << " " << root->left->data << " " << root->right->data << " " << root->left->left->data << " " << root->left->right->data << " " << root->right->left->data << " " << root->right->right->data << endl;
    // cout << "ans: " << ans << endl;


    return 0;
}