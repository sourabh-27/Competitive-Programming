#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

int val(char c)
{
    if(c >= '0' && c <= '9')
    {
        return (int)c - '0';
    }
    else
    {
        return (int)c - 'A' + 10;
    }
    
}

ll conDec(string y, ll b)
{
    ll ans = 0;
    ll len = y.length();
    ll pow = 1;
    for(ll i = len - 1; i >= 0; i--)
    {
        if(val(y[i] >= b)
        {
            return 0;
        }
        ans += val(y[i]) * pow;
        if(ans > 1e12)
        {
            return 0;
        }
        pow = pow * b;
    }
    return ans;
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
        int flag = 0;
        ll arr[n]; string arr2[n];
        for(ll i = 0; i < n; i++)
        {
            ll b; string y;
            cin >> b >> y;
            arr[i] = b; arr2[i] = y;
            if(b != -1)
            {
                ans = conDec(y, b);
                // cout << "The answer for b != -1 is : " << ans << endl;
                if(ans == 0)
                {
                    // cout << "The value of b and y for which ans == 0 is: " << b << " " << y << endl;
                    flag = 1;
                }
            }
        }
        if(flag == 1)
        {
            // cout << "YOOOO " << endl;
            cout << -1 << endl;
        }
        else
        {   
            int flag2 = 0; int flag3 = 0;
            for(ll i = 0; i < n; i++)
            {
                if(arr[i] != -1)
                {
                    continue;
                }
                else
                {
                    // cout << "The string is : " << arr2[i] << endl;
                    for(ll j = 2; j <= 36; j++)
                    {
                        if(ans == conDec(arr2[i], j))
                        {
                            // cout << "The base for i is " << i << " and base: " << j << endl;
                            flag2 = 1;
                            break;
                        }
                    }
                    if(flag2 == 0 && flag3 == 0)
                    {
                        flag3 = 1;
                        cout << -1 << endl;
                        break;
                    }
                    flag2 = 0;
                }  
            }
            if(flag3 == 0)
            {
                cout << ans << endl;
            }
        }
    }

    return 0;
}