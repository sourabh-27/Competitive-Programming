#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
#define N 1000001

ll arr[20];

bool isPure(ll n)
{
    vector<ll> vec;
        for(ll i = 12; i >= 0; i--)
        {
            if((n / arr[i]) > 0)
            {
                ll times = n / arr[i];
                n = n - (arr[i] * times);
                if(times % 2 == 0)
                {
                    continue;
                    // vec.push_back(0);
                }
                else
                {
                    ll z1 = ((ll)((log2(arr[i])) / (log2(3))));
                    if(z1 != 0)
                    {
                        vec.push_back(z1);
                    }
                }
            }
        }
        ll ans2;
        if(!vec.empty())
        {
            ans2 = vec[0]; 
        }
        else
        {
            ans2 = n;
        }
        // for(ll i = 0; i < vec.size(); i++)
        // {
        //     cout << vec[i] << " ";
        // }
        // cout << endl;
        for(ll i = 1; i < vec.size(); i++)
        {
            ans2 = ans2 ^ vec[i];
        }
        // cout << "ans2: " << ans2 << endl;
        if(ans2 == 0)
        {
            return true;
        }
        return false;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    cout << "YO" << endl;
    ll k = 0; ll ans = 0;
    while(ans <= 1000000)
    {
        // 0 to 12 inclusive
        ans = pow(3, k);
        arr[k] = ans;
        // cout << arr[k] << " ";
        k++;
    }

    // cout << "Yo" << endl;
    ll dp[N + 2] = {0};
    dp[N-1] = 1000002;
    // cout << "dp[N-1]: " << dp[N - 1] << endl;
    // cout<<"isPure(1000002): " << isPure(N) << endl;
    for(ll i = N; i >= 0; i--)
    {
        if(isPure(i))
            dp[i] = i;
        else 
            dp[i] = dp[i+1];
        // cout << "YO" << endl;
    }
    
    while(t--)
    {
        ll n;
        cin >> n;
        cout << dp[n] << endl;
        // cout << dp[n] << endl;
    }

    return 0;
}