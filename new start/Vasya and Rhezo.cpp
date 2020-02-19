#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

struct node{
    int max;
    int min;
    node()
    {
        max = min = 0;
    }
}

void buildTree(int * arr, int * arr2, node * tree, int start, int end, int treeIndex)
{
    if(start == end)
    {
        tree[treeIndex].max = arr[start];
        tree[treeIndex].min = arr2[start];
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int arr[n], arr2[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }
    node tree[3 * n];
    buildTree(arr, arr2, tree, 0, n - 1, 1);
    return 0;
}