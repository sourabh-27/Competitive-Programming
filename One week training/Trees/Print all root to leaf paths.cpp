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

void printAllRoot(node * root, long long * temp, ll count){
    if(root == NULL){
        return;
    }
    else if(root->left == NULL && root->right == NULL){
        for(ll i = 0; i < count; i++){
            cout << temp[i] << " ";
        }
        cout << endl;
        return;
    }
    else{
        temp[count] = root->data;
        printAllRoot(root->left, temp, count + 1);
        // temp[count] = root->data;
        printAllRoot(root->right, temp, count + 1);
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
    long long * temp = new long long[100];
    printAllRoot(root, temp, 0);
    // cout << "Height of tree: " << ans << endl;

    // cout << root->data << " " << root->left->data << " " << root->right->data << " " << root->left->left->data << " " << root->left->right->data << " " << root->right->left->data << " " << root->right->right->data << endl;
    // cout << "ans: " << ans << endl;


    return 0;
}