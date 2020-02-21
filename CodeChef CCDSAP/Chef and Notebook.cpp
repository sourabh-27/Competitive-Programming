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
        ll x, y, k, n;
        cin >> x >> y >> k >> n;
        ll pagesR = x - y;
        // struct values arr[n + 1];
        bool ans = false;
        for(ll i = 0; i < n; i++)
        {
            ll p, c;
            cin >> p >> c;
            if(p >= pagesR)
            {
                if(n >= c)
                {
                    ans =  true;
                }
            }
        }
        if(ans)
        {
            cout << "LuckyChef" << endl;
        }
        else
        {
            cout << "UnluckyChef" << endl;
        }
    }

    return 0;
}