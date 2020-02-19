#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;
 
int main()
{
    fast;
    ll n;
    cin >> n;
    ll k;
    cin >> k;
    long long start[30] = {0}; long long end[30] = {0};
    for(ll i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        start[x]++; end[y]++;
    }
    for(ll i = 0; i <= 15; i++)
    {
        cout << i << " ";
    }
    cout << endl;
    for(ll i = 0; i <= 15; i++)
    {
        cout << start[i] << " ";
    }
    cout << endl;
    for(ll i = 0; i <= 15; i++)
    {
        cout << end[i] << " ";
    }

    return 0;
}