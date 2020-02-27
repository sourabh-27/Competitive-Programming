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

struct qItem{
    node *pointer;
    int depth;
};

node *newnode(int data){
    node *temp = new node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

int minDepth(node *root){
    if(root == NULL){
        return 0;
    }

    queue<qItem> q;
    qItem qi = {root, 1};
    q.push(qi);

    while(!q.empty())
    {
        qi = q.front();
        q.pop();

        node *temp = qi.pointer;
        int depth = qi.depth;

        if(temp->left == NULL && temp->right == NULL){
            return depth;
        }

        if(temp->left != NULL){
            qi.pointer = temp->left;
            qi.depth = depth + 1;
            q.push(qi);
        }

        if(temp->right != NULL){
            qi.pointer = temp->right;
            qi.depth = depth + 1;
            q.push(qi);
        }
    }
    return 0;
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