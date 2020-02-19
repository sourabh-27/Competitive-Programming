#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

int fun( int curr_ind, int itr , ll * a)

{

 if(itr==0)

    return 0;

 return a[curr_ind] + fun( a[curr_ind] , itr-1 , a);
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
        ll n, q;
        cin >> n >> q;
        ll arr[n + 2];
        for(ll i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        while(q--)
        {
            ll c, d;
            cin >> c >> d;
            int ans = fun(c, d, arr);
            cout << ans << endl;
        }
    }

    return 0;
}