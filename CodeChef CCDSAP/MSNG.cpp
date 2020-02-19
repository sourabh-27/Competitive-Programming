#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

int value(char k)
{
    if(k >= '0' && k <= '9')
    {
        return (int)k - '0';
    }
    else
    {
        return (int)k - 'A' + 10;
    }
}

ll toDecimal(string str, ll base)
{
    ll pow = 1;
    ll n = 0;
    ll len = str.length();
    for(ll i = len - 1; i >= 0; i--)
    {
        n += value(str[i]) * pow;
        pow = pow * base;
    }
    return n;
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
        ll n;
        cin >> n;
        ll ans = -1;
        // ll temp; ll dp[1000000] = {0};
        for(ll i = 1; i <= n; i++)
        {
            ll b;
            cin >> b;
            string y;
            cin >> y;
            if(b != -1)
            {
                ans = toDecimal(y, b);
            }
            // else
            // {
            //     for(ll j = 2; j <= 36; j++)
            //     {
            //         // cout << "YOOO" << endl;
            //         dp[toDecimal(y, j)] += 1;
            //         ll k = dp[toDecimal(y, j)];
            //         if(k == n)
            //         {
            //             temp = toDecimal(y, j);
            //         }
            //         cout << toDecimal(y, j) << " ";
            //     }
            //     cout << endl;
            // }
            
        }
        if(ans != -1)
        {
            cout << ans << endl;
        }
        // else
        // {
        //     cout << temp << endl;
        // }
        
    }

    return 0;
}