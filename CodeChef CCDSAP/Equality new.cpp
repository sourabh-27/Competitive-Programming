#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

void buildTree(long long * arr, long long * tree, ll treeIndex, ll start, ll end)
{
    if(start == end)
    {
        tree[treeIndex] = arr[start];
        return;
    }
    ll mid = (start + end) / 2;

    buildTree(arr, tree, 2 * treeIndex, start, mid);
    buildTree(arr, tree, 2 * treeIndex + 1, mid + 1, end);

    if(tree[2 * treeIndex] < tree[2 * treeIndex + 1])
    {
        tree[treeIndex] = 0;
    }
    else if(tree[2 * treeIndex] == 1)
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, q;
    cin >> n >> q;
    long long arr[n + 1];
    for(ll i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    long long tree[3 * n] = {0};
    buildTree(arr, tree, 0, 1, n);

    while(q--)
    {
        ll l, r;
        cin >> l >> r;
        getQuery(tree, l, r);
    }

    return 0;
}