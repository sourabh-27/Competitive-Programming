#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

struct node{
    int prefixSum;
    int suffixSum;
    int totalSum;
    int maxSum;

    node()
    {
        prefixSum = suffixSum = totalSum = maxSum = INT_MIN;
    }
};

// void merge(nd)

void buildTree(int *arr, node *tree, int treeIndex, int start, int end)
{
    if(start == end)
    {
        tree[treeIndex].prefixSum = arr[start];
        tree[treeIndex].suffixSum = arr[start];
        tree[treeIndex].totalSum = arr[start];
        tree[treeIndex].maxSum = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    buildTree(arr, tree, 2*treeIndex, start, mid);
    buildTree(arr, tree, 2*treeIndex + 1, mid + 1, end);

    tree[treeIndex] = merge(tree[2*treeIndex], tree[2*treeIndex + 1]);
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    node tree[3*n];
    for(int i = 0; i < 3*n; i++)
    {
        tree[i] = 0;
    }

    buildTree(arr, tree, 1, 0, n -1);
    int m ;
    cin >> m;
    while(m--)
    {
        int x, y;
        cin >> x >> y;
        
    }

    return 0;
}