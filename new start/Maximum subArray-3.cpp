#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

struct node{
    int sum, prefixsum, suffixsum, maxsum;
};

void buildTree(int *arr, node * tree, int treeIndex, int start, int end)
{
    if(start == end)
    {
        tree[treeIndex].sum = arr[start];
        tree[treeIndex].prefixsum = arr[start];
        tree[treeIndex].suffixsum = arr[start];
        tree[treeIndex].maxsum = arr[start];
    }
    else
    {
        int mid = (start + end) / 2;
        buildTree(arr, tree, 2*treeIndex + 1, start, mid);
        buildTree(arr, tree, 2*treeIndex + 2, mid + 1, end);
        tree[treeIndex].prefixsum = max(tree[2*treeIndex + 1].prefixsum, tree[2*treeIndex + 1].sum + tree[2*treeIndex + 2].prefixsum);
        tree[treeIndex].suffixsum = max(tree[2*treeIndex + 2].suffixsum, tree[2*treeIndex + 2].sum + tree[2*treeIndex + 1].suffixsum);
        tree[treeIndex].maxsum = max(tree[treeIndex].prefixsum, max(tree[treeIndex].suffixsum, max(tree[2*treeIndex + 1].maxsum, max(tree[2*treeIndex + 2].maxsum, tree[2*treeIndex + 1].suffixsum + tree[2 * treeIndex + 2].prefixsum))));
    }
    
}

node queryTree(int * arr, node * tree, int treeIndex, int start, int end, int left, int right)
{
    node result;
    result.sum = result.maxsum = result.prefixsum = result.suffixsum = INT_MIN;
    if(right < start || left > end)
    {
        return result;
    }
    if(left <= start && right >= end)
    {
        return tree[treeIndex];
    }
    int mid = (start + end) / 2;
    if(left > mid)
    {
        return queryTree(arr, tree, 2*treeIndex + 2, mid + 1, end, left, right);
    }
    if(right <= mid)
    {
        return queryTree(arr, tree, 2*treeIndex + 1, start, mid, left, right);
    }
    node l = queryTree(arr, tree, 2 * treeIndex + 1, start, mid, left, right);
    node r = queryTree(arr, tree, 2 * treeIndex + 2, mid + 1, end, left, right);
    result.sum = l.sum + r.sum;
    result.prefixsum = max(l.prefixsum, l.sum + r.prefixsum);
    result.suffixsum = max(r.suffixsum, r.sum + l.suffixsum);
    result.maxsum = max(result.prefixsum, result.suffixsum);
    result.maxsum = max(result.maxsum, max(l.maxsum, r.maxsum));
    result.maxsum = max(result.maxsum, l.suffixsum + r.prefixsum);
    return result;
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
    buildTree(arr, tree, 0, 0, n - 1);
    int m;
    while(m--)
    {
        int x, y;
        cin >> x >> y;
        node answer = queryTree(arr, tree, 0, 0, n - 1, x - 1, y - 1);
        cout << answer.maxsum << endl;
    }

    return 0;
}