#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

struct node{
    int max;
    int smax;
};

void buildTree(int * arr, node * tree, int treeIndex, int start, int end)
{
    if(start == end)
    {
        tree[treeIndex].max = arr[start];
        tree[treeIndex].smax = INT_MIN;
        return;
    }
    int mid = (start + end) / 2;
    buildTree(arr,tree, 2*treeIndex, start, mid);
    buildTree(arr, tree, 2*treeIndex + 1, mid + 1, end);
    node left = tree[2 * treeIndex];
    node right = tree[2 * treeIndex + 1];
    tree[treeIndex].max = max(left.max, right.max);
    tree[treeIndex].smax = min(max(left.max, right.smax), max(right.max, left.smax));
    return;
}

void updateTree(int * arr, node * tree, int treeIndex, int start, int end, int index, int value)
{
    if(start == end)
    {
        arr[index] = value;
        tree[treeIndex].max = value;
        tree[treeIndex].smax = INT_MIN;
        return;
    }
    int mid = (start + end) / 2;
    if(index > mid)
    {
        updateTree(arr, tree, mid + 1, end, 2 * treeIndex + 1, index, value);
    }
    else
    {
        updateTree(arr, tree, start, mid, 2 * treeIndex, index, value);
    }
    tree[treeIndex].max = max(tree[2*treeIndex].max, tree[2*treeIndex + 1].max);
    tree[treeIndex].smax = min(max(tree[2*treeIndex].max, tree[2*treeIndex + 1].smax), max(tree[2*treeIndex + 1].smax, tree[2 * treeIndex].max));
}

node queryTree(node * tree, int treeIndex, int start, int end, int left, int right)
{
    node result;
    result.max = result.smax = -1;
    if(start > right || end < left)
    {
        return result;
    }

    if(start >= left && end <= right)
    {
        return (tree[treeIndex]);
    }

    int mid = (start + end) / 2;
    if(left > mid)
    {
        return queryTree(tree, 2*treeIndex, mid + 1, end, left, right);
    }
    if(right <= mid)
    {
        return queryTree(tree, 2*treeIndex + 1, start, mid, left, right);
    }

    node ans1 = queryTree(tree, 2*treeIndex + 1, start, mid, left, right);
    node ans2 = queryTree(tree, 2*treeIndex, mid + 1, end, left, right);

    result.max = max(ans1.max, ans2.max);
    result.smax = min(max(ans1.max, ans2.smax), max(ans2.max, ans1.smax));

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

    node *tree = new node[3 * n];
    for(int i = 0; i < 3*n; i++)
    {
        tree[i].max = 0;
        tree[i].smax = 0;
    }
    buildTree(arr, tree, 1, 0, n - 1);

    for(int i = 0; i < 3*n; i++)
    {
        cout << tree[i].max << " " << tree[i].smax << endl;
    }

    int q;
    cin >> q;
    while(q--)
    {
        char c;
        cin >> c;
        int x, y;
        cin >> x >> y;
        if(c == 'Q')
        {
            node result = queryTree(tree, 1, 0, n - 1, x, y);
            cout << result.max + result.smax << endl;
        }
        else
        {
            updateTree(arr, tree, 1, 0, n - 1, x, y);
        } 
    }
    return 0;
}