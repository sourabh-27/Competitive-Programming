#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

struct node
{
    int max;
    int smax;
};

void buildTree(int *arr, node *tree, int treeIndex, int start, int end)
{
    if(start == end)
    {
        tree[treeIndex].max = arr[start];
        tree[treeIndex].smax = INT_MIN;
        return;
    }

    int mid = (start + end) / 2;
    buildTree(arr, tree, 2*treeIndex + 1, start, mid);
    buildTree(arr, tree, 2*treeIndex + 2, mid + 1, end);

    tree[treeIndex].max = max(tree[2*treeIndex + 1].max, tree[2*treeIndex + 2].max);
    tree[treeIndex].smax = min(max(tree[2*treeIndex + 1].max, tree[2*treeIndex + 2].smax), max(tree[2*treeIndex + 1].smax, tree[2*treeIndex + 2].max));
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
        return tree[treeIndex];
    }

    int mid = (start + end) / 2;
    if(left > mid)
    {
        return queryTree(tree, 2*treeIndex + 2, mid + 1, end, left, right);
    } 
    if(right <= mid)
    {
        return queryTree(tree, 2*treeIndex + 1, start, mid, left, right);
    }

    node ans1 = queryTree(tree, 2*treeIndex + 1, start, mid, left, right);
    node ans2 = queryTree(tree, 2*treeIndex + 2, mid + 1, end, left, right);

    result.max = max(ans1.max, ans2.max);
    result.smax = min(max(ans1.max, ans2.smax), max(ans1.smax, ans2.max));
    return result;
    
}

void updateTree(int * arr, node * tree, int treeIndex, int start, int end, int index, int value)
{
    if(start == end)
    {
        tree[treeIndex].max = value;
        tree[treeIndex].smax = INT_MIN;
    }
    else
    {
        int mid = (start + end) / 2;
        if(index <= mid)
        {
            updateTree(arr, tree, 2*treeIndex + 1, start, mid, index, value);
        }
        else
        {
            updateTree(arr, tree, 2*treeIndex + 2, mid + 1, end, index, value);
        }

        tree[treeIndex].max = max(tree[2*treeIndex + 1].max , tree[2*treeIndex + 2].max);
        tree[treeIndex].smax = min(max(tree[2*treeIndex + 1].max, tree[2*treeIndex + 2].smax), max(tree[2*treeIndex + 1].smax, tree[2*treeIndex + 2].max));
    }
    
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
        tree[i].max = 0;
        tree[i].smax = 0;
    }
    buildTree(arr, tree, 0, 0, n - 1);
    int q;
    cin >> q;
    while(q--)
    {
        char ch;
        cin >> ch;
        int x, y;
        cin >> x >> y;
        if(ch == 'Q')
        {
            node result = queryTree(tree, 0, 0, n - 1, x - 1, y - 1);
            cout << result.max + result.smax << endl;
        }
        else
        {
            updateTree(arr, tree, 0, 0, n - 1, x - 1, y);
        }
        
    }

    return 0;
}