#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

void subSequence2(ll arr[], ll n, ll k, ll start, ll currLen, bool * visited, ll &mini, ll &count)
{
    if(currLen == k)
    {
        ll sum = 0;
        for(ll i = 0; i < n; i++)
        {
            if(visited[i])
            {
                sum += arr[i];
                if(sum > mini)
                {
                    break;
                }
            }
        }
        if(sum < mini)
        {
            mini = sum;
            count = 1;
        }
        else if(sum == mini)
        {
            count++;
        }
        return;
    }
    if(start == n)
    {
        return;
    }

    visited[start] = true;
    subSequence2(arr, n, k, start + 1, currLen + 1, visited, mini, count);
    visited[start] = false;
    subSequence2(arr, n, k, start + 1, currLen, visited, mini, count);
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while(t--)
    {
        ll n, k;
        cin >> n >> k;
        ll arr[n];
        for(ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        bool * visited = new bool[n];
        for(ll i = 0; i < n; i++)
        {
            visited[i] = false;
        }
        ll mini = INT_MAX; ll count = 0;
        subSequence2(arr, n, k, 0, 0, visited, mini, count);
        cout << count << endl;
        // ll count = 0; ll mini = INT_MAX;
        // subSequence(arr, n, k, 0, 0, mini, count);
        // cout << count << endl;
    }

    return 0;
}