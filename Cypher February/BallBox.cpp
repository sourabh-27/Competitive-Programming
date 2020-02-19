#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;
 
int main()
{
    fast;
    ll t;
    cin >> t;
    while(t--)
    {
        ll l, b, h;
        cin >> l >> b >> h;
        ll n;
        cin >> n;
        ll ans = __gcd(l, __gcd(b, h));
        ll ans2 = (l / ans) * (b / ans) * (h / ans);
        cout << ans2 - n << endl;
    }

    return 0;
}