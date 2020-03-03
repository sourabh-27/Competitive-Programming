#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

struct node{
    int data; int hd;
    node *left, *right;
};

node *newnode(int data){
    node *temp = new node;
    temp->data = data;
    temp->left = temp->right = NULL;
    temp->hd = 0;
}

void topView(node * root){
    if(root == NULL){
        return;
    }

    int hd = 0;
    map<int, int> mp;
    queue<node *> q;
    root->hd = hd;
    q.push(root);

    while(!q.empty()){
        node *temp = q.front();
        q.pop();
        hd = temp->hd;
        if(mp.count(hd) == 0){
            mp[hd] = temp->data;
        }

        if(temp->left != NULL){
            temp->left->hd = hd - 1;
            q.push(temp->left);
        }

        if(temp->right != NULL){
            temp->right->hd = hd + 1;
            q.push(temp->right);
        }
    }

    for(auto it = mp.begin(); it != mp.end(); it++){
        cout << it->second << " ";
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
    root->right->right->left = newnode(3);
    root->right->right->right = newnode(4);
    topView(root);

    return 0;
}