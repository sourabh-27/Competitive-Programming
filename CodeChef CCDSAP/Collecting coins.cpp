#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while(t--)
    {
        ll a, b, c, n;
        cin >> a >> b >> c >> n;
        ll maxi = max(a, max(b, c));
        ll extra = (maxi - a) + (maxi - b) + (maxi - c);
        n = n - extra;
        if(n % 3 != 0 || n < 0)
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