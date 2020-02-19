#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

ll finder(ll n)
{
    ll modi = n % 4;
    if (modi == 0) return n; 
	else if (modi == 1) return 1; 
	else if (modi == 2) return n + 1; 
	else if (modi == 3) return 0; 
}

ll xorr(ll l, ll r)
{
    return (finder(l - 1) ^ finder(r));
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
        ll l, r;
        cin >> l >> r;
        ll ans;
        if(l == 0)
        {
            ans = xorr(1, r);
        }
        else
        {
            ans = xorr(l, r);
        }
        cout << ans << endl;
    }

    return 0;
}