#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<ll> vec;
    set<ll> s;
    ll m, n;
    cin >> m >> n;
    long long arr[m][n];
    for(ll i = 0; i < m; i++)
    {
        for(ll j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            s.insert(arr[i][j]);
        }
    }

    for(ll i = 0; i < m; i++)
    {
        for(ll j = 0; j < n; j++)
        {
            set<ll>::iterator it = s.find(arr[i][j]);
            ll index = distance(s.begin(), it);
            cout << index + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}