#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
#define pb push_back
#define mp make_pair
typedef long long int ll;

long long pre[(int)(5 * 1e5 + 20)];
 
int main()
{
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        long long arr[n + 1];
        for(ll i = 0; i < n; i++){
            cin >> arr[i];
            // cout << "arr[i]: " << arr[i] << " ";
        }
        // cout << "YO" << endl;
        for(ll i = 0; i <= 2*k + 10; i++){
            pre[i] = 0;
        }
        // cout << "YO2" << endl;
        vector<pair<ll, ll>> vec;
        for(ll i= 0 ; i < n / 2; i++){
            ll a = min(arr[i], arr[n - i - 1]);
            ll b = max(arr[i], arr[n - i - 1]);
            // cout << "a1: " << i << " b1: " << n - i - 1 << endl;
            vec.pb(make_pair(a, b));
        }
        // cout << "YO3" << endl;
        map<ll, ll> umap;
        for(auto x : vec){
            ll a = x.first + 1;
            ll b = x.second + k;
            // cout << "a: " << a << " b: " << x.second << endl;
            umap[x.first + x.second]++;
            pre[a] += 1;
            pre[b + 1] -= 1;
        }
        // cout << "YO4" << endl;
        ll ans = n;
        for(ll i = 1; i < 2*k + 10; i++){
            pre[i] += pre[i - 1];
            // cout << "i: " << i << " pre: " << pre[i] << endl;
            ll z1 = pre[i] - umap[i];
            ll z2 = (n / 2) - (z1) - (umap[i]);
            ll count = z1 + (z2 * 2);
            ans = min(ans, count);
        }
        cout << ans << endl;
    }


    return 0;
}