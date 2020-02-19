#include<bits/stdc++.h>
using namespace std;

void buildTree(int * arr, int *tree, int treeIndex, int start, int end)
{
    if(start == end)
    {
        if(arr[start] > 0)
        {
            tree[treeIndex] += arr[start];
        }
        return;
    }
    int mid = (start + end) / 2;
    buildTree(arr, tree, 2*treeIndex, start, mid);
    buildTree(arr, tree, 2*treeIndex + 1, mid + 1, end);
    
    if(tree[2*treeIndex] > 0)
    {
        tree[treeIndex] += tree[2*treeIndex];
    }
    if(tree[2*treeIndex + 1] > 0)
    {
        tree[treeIndex] += tree[2*treeIndex + 1];
    }
    return;
}

int queryTree(int * tree, int treeIndex, int start, int end, int left, int right)
{
    if(start > right || end < left)
    {
        return 0;
    }
    if(start >= left && end <= right)
    {
        return tree[treeIndex];
    }

    int mid = (start + end) / 2;
    int ans1 = queryTree(tree, 2*treeIndex, start, mid, left, right);
    int ans2 = queryTree(tree, 2*treeIndex + 1, mid + 1, end, left, right);
    return ans1 + ans2;
}

int main() 
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    int tree[3*n];
    for(int i = 0; i < 3*n; i++)
    {
        tree[i] = 0;
    }
    
    buildTree(arr, tree, 1, 0, n - 1);
    // for(int i = 0; i < 3*n; i++)
    // {
    //     cout << tree[i] << endl;
    // }
    int m;
    cin >> m;
    while(m--)
    {
        int x, y;
        cin >> x >> y;
        cout << queryTree(tree, 1, 0, n - 1, x - 1, y - 1);
    }
}