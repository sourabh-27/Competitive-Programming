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
        ll n;
        cin >> n;
        // cout << "n: " << n << endl;
        long long arr[n + 1]; ll flag = 0;
        long long arr2[n + 1];
        for(ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            arr2[i] = arr[i];
            if(arr[i] != -1)
            {
                flag = 1;
            }
        }

        if(flag == 0)
        {
            cout << 0 << " " << 0 << endl;
        }
        else
        {
            ll maxi = 0; ll sum = 0;
            set<ll> s; ll minElement = 10000000000;
            // cout << "YO" << endl;
            for(ll i = 0; i < n - 1; i++)
            {
                if(arr[i] != -1 && arr[i + 1] != -1)
                {
                    maxi = max(maxi, abs(arr[i] - arr[i + 1]));
                }
            }
            if(flag != 0)
            {
                for(ll i = 0; i < n; i++)
                {
                    if(arr[i] != -1)
                    {
                        minElement = min(minElement, arr[i]);
                        s.insert(arr[i]);
                    }
                }
            }
            set<ll>::iterator itr;
            if(!s.empty())
            {
                for(itr = s.begin(); itr != s.end(); ++itr)
                {
                    sum = sum + *itr;
                }
            }
            // cout << "sum: " << sum << endl;
            ll count = s.size();
            ll ans = 0;
            if(sum % count == 0)
            {   
                ans = sum / count;
            }
            else
            {
                ans = (sum / count) + 1;   
            }

            for(ll i = 0; i < n; i++)
            {
                if(arr[i] == -1)
                {
                    arr[i] = ans;
                }
            }
            for(ll i = 0; i < n; i++)
            {
                if(arr2[i] == -1)
                {
                    arr2[i] = ans - 1;
                }
            }

            ll maxi1 = INT_MIN; ll maxi2 = INT_MIN;
            for(ll i = 0; i < n - 1; i++)
            {
                maxi1 = max(maxi1, abs(arr[i] - arr[i + 1]));
                maxi2 = max(maxi2, abs(arr2[i] - arr2[i + 1]));
            }
            if(maxi1 < maxi2)
            {
                if(maxi >= maxi1)
                {
                    cout << "YO " endl;
                    cout << maxi << " " << minElement << endl;
                }
                else
                {
                    cout << maxi1 << " " << ans << endl;
                }
            }
            else
            {
                if(maxi >= maxi2)
                {
                    cout << maxi << " " << minElement << endl;
                }
                else
                {
                    cout << maxi2 << " " << ans - 1 << endl;
                }
            }
            
        }


    }


    return 0;
}