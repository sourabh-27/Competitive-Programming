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
    cout << 1 << endl;
    ll start = 1;
    for(ll i = 2; i <= n; i++)
    {
        cout << start;
        for(ll j = 1; j < i - 1; j++)
        {
            cout << 0;
        }
        cout << start << endl;
        start = start + 1;
    }

    return 0;
}