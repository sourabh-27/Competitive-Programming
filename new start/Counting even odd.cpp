#include<bits/stdc++.h>
using namespace std;

struct node{
    int odd;
    int even;
    node()
    {
        odd = even = 0;
    }
};

void buildTree(int * arr, node * tree, int start, int end, int treeIndex)
{
    if(start == end)
    {
        if(arr[start] % 2 == 0)
        {
            tree[treeIndex].even = 1;
        }
        else
        {
            tree[treeIndex].odd = 1;
        }
        return;
    }
    
    int mid = (start + end) / 2;
    buildTree(arr, tree, start, mid, 2 * treeIndex);
    buildTree(arr, tree, mid + 1, end, 2 * treeIndex + 1);
    
    tree[treeIndex].even = tree[2 * treeIndex].even + tree[2 * treeIndex + 1].even;
    tree[treeIndex].odd = tree[2 * treeIndex].odd + tree[2 * treeIndex + 1].odd;
    return;
}

void updateTree(int * arr, node * tree, int start, int end, int treeIndex, int index, int value)
{
    if(start == end)
    {
        arr[index] = value;
        if(value % 2 == 0)
        {
            tree[treeIndex].even = 1;
            tree[treeIndex].odd = 0;
        }
        else
        {
            tree[treeIndex].odd = 1;
            tree[treeIndex].even = 0;
        }
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

    tree[treeIndex].even = tree[2 * treeIndex].even + tree[2 * treeIndex + 1].even;
    tree[treeIndex].odd = tree[2 * treeIndex].odd + tree[2 * treeIndex + 1].odd;
    return;
}

node queryTree(node * tree, int start, int end, int treeIndex, int left, int right)
{
    node result;
    if(start > right || end < left)
    {
        return result;
    }

    if(start >= left && end <= right)
    {
        return tree[treeIndex];
    }

    int mid = (start + end) / 2;

    node ans1 = queryTree(tree, start, mid, 2 * treeIndex, left, right);
    node ans2 = queryTree(tree, mid + 1, end, 2 * treeIndex + 1, left, right);

    result.even = ans1.even + ans2.even;
    result.odd = ans1.odd + ans2.odd;
    return result;

}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    node tree[3 * n];
    buildTree(arr, tree, 0, n - 1, 1);

    // for(int i = 1; i < 3 * n; i++)
    // {
    //     cout << tree[i].odd << " " << tree[i].even << endl;
    // }

    int q;
    cin >> q;
    while(q--)
    {
        int z, x, y;
        cin >> z >> x >> y;
        if(z == 0)
        {
            updateTree(arr, tree, 0, n - 1, 1, x - 1, y);
        }
        else if(z == 1)
        {
            cout << queryTree(tree, 0, n - 1, 1, x - 1, y - 1).even << endl;
        }
        else
        {
            cout << queryTree(tree, 0, n - 1, 1, x - 1, y - 1).odd << endl;
        }
    }
}