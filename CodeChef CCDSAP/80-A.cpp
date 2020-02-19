#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

long long int minimumDays(ll x, ll d)
{
    return x + ceil((long double)d / (x + 1));
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
        ll n, d;
        cin >> n >> d;
        ll x1 = ceil((long double)(sqrt(d) - 1));
        ll x2 = floor((long double)(sqrt(d) - 1));
        // cout << "x1: " << x1 << " x2 : " << x2 << endl;
        ll mini = min(minimumDays(x1, d), minimumDays(x2, d));
        // cout << "minimum Days 1: " << minimumDays(x1, d) << endl;
        // cout << "minimum Days 2: " << minimumDays(x2, d) << endl;
        if(mini <= n)
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