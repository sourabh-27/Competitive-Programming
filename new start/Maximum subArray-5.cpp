#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

struct node{
    int maxsum, prefixsum, suffixsum, totalsum;
    node()
    {
        maxsum = prefixsum = suffixsum = totalsum = -0x3f3f3f3f;
    }
};

node merge(node leftChild, node rightChild)
{
    node parentNode;
    parentNode.prefixsum = max(leftChild.prefixsum, leftChild.totalsum + rightChild.prefixsum);
    parentNode.suffixsum = max(leftChild.suffixsum + rightChild.totalsum, rightChild.suffixsum);
    parentNode.totalsum = leftChild.totalsum + rightChild.totalsum;
    parentNode.maxsum = max(leftChild.maxsum, max(rightChild.maxsum, leftChild.suffixsum + rightChild.prefixsum));
    // parentNode.maxsum = max(parentNode.maxsum, max(parentNode.prefixsum, parentNode.suffixsum));

    return parentNode;
}

void buildTree(long long * arr, node * tree, int start, int end, int treeIndex)
{
    if(start == end)
    {
        tree[treeIndex].maxsum = arr[start];
        tree[treeIndex].prefixsum = arr[start];
        tree[treeIndex].suffixsum = arr[start];
        tree[treeIndex].totalsum = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    buildTree(arr, tree, start, mid, 2 * treeIndex);
    buildTree(arr, tree, mid + 1, end, 2 * treeIndex + 1);

    tree[treeIndex] = merge(tree[2 * treeIndex], tree[2 * treeIndex + 1]);
}

node queryTree(node * tree, int start, int end, int treeIndex, int left, int right)
{
    if(start > right || end < left)
    {
        node nullNode;
        return nullNode;
    }

    if(start >= left && end <= right)
    {
        return tree[treeIndex];
    }

    int mid = (start + end) / 2;
    node l = queryTree(tree, start, mid, 2 * treeIndex, left, right);
    node r = queryTree(tree, mid + 1, end, 2 * treeIndex + 1, left, right);

    node res = merge(l, r);
    return res;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    long long arr[n];
    for(ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    node tree[3*n];
    buildTree(arr, tree, 0, n - 1, 1);

    ll m;
    cin >> m;
    while(m--)
    {
        ll x, y;
        cin >> x >> y;
        cout << queryTree(tree, 0, n - 1, 1, x - 1, y - 1).maxsum << endl;
    }

    return 0;
}