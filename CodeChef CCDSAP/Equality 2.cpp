#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

long long dp[100001] = {0}; long long dp2[100001] = {0};
void countIncreasing(long long * arr, ll n, ll l, ll r)
{
    ll count = 0;
    int flag = 0; ll temp = 1;
    for(ll i = l + 1; i <= r; i++)
    {
        if(arr[i] > arr[i - 1] && flag == 0)
        {
            flag = 1;
            dp[i - 1] = temp;
            if(i == r)
            {
                dp[i] = temp;
                temp++;
                count++;
            }
            continue;
        }
        else if(flag == 1 && arr[i] < arr[i - 1])
        {
            count++;
            flag = 0;
            dp[i - 1] = temp;
            temp++;
        }
        else if(arr[i] > arr[i - 1] && flag == 1)
        {
            if(i == r)
            {
                dp[i] = temp;
                temp++;
                count++;
            }
        }
    }
    return;
}



void buildTree(long long * arr, long long * tree, ll treeIndex, ll start, ll end)
{
    if(start == end)
    {
        tree[treeIndex] = 0;
        return;
    }

    ll mid = (start + end) / 2;
    buildTree(arr, tree, 2 * treeIndex, start, mid);
    buildTree( arr, tree, 2 * treeIndex + 1, mid + 1, end);

    if(arr[start] == arr[end])
    {
        tree[treeIndex] += 1;
    }
    else 
    {
        tree[treeIndex] = tree[2 * treeIndex] + tree[2 * treeIndex + 1];
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, q;
    cin >> n >> q;
    long long arr[n + 2];
    for(ll i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    long long tree[4 * n];
    buildTree(arr, tree, treeIndex, 1, n);

    while(q--)
    {
        ll l, r;
        cin >> l >> r;
        // cout << "countIncreasing: " << countIncreasing(arr, n, l, r) << endl;
        // cout << "countDecreasing: " << countDecreasing(arr, n, l, r) << endl;
        if(countIncreasing(arr, n, l, r) == countDecreasing(arr, n, l, r))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}