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
        ll n, m, k;
        cin >> n >> m >> k;
        deque<ll> deq; long long arr[n + 1];
        for(ll i = 0; i < n; i++)
        {
            ll k;
            cin >> k;
            deq.push_back(k);
            arr[i] = k;
        }

        ll start = 0; ll end = n - 1;
        ll ans = max(arr[start], arr[end]);
        m = m - 1;
        while(m--)
        {
            if(k > 0)
            {
                if(deq.front() < deq.back())
                {
                    deq.pop_front();
                    start = start + 1;
                }
                else
                {
                    deq.pop_back();
                    end = end - 1;
                }
            }
            else
            {
                if(deq.front() > deq.back())
                {
                    deq.pop_front();
                    start = start + 1;
                }
                else
                {
                    deq.pop_back();
                    end = end - 1;
                }
            }
            ans = max(arr[start], arr[end]);
            // cout << "start: " << start << " end: " << end << endl;
            k--;
            // cout << "k: " << k << endl;
        }
        cout << ans << endl;
    }

    return 0;
}