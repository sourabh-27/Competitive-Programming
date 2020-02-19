#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
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

    while(q--)
    {
        ll l, r;
        cin >> l >> r;
        int start, end;
        start = (arr[l] < arr[l + 1]) ? 1 : 0;
        end = (arr[r - 1] < arr[r]) ? 1: 0;
        if(start == end)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }

    return 0;
}