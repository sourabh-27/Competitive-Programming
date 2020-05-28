#include<bits/stdc++.h>
using namespace std; 
#define mod 998244353
#define INF 0x3f3f3f3f
#define all(x) (x).begin(),(x).end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
#define pb push_back
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define mp make_pair
#define print(v); for(auto x:v) cout<<x<<" "; cout<<endl;
typedef long long int ll;
int main()
{
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll n, m, q;
        cin >> n >> m >> q;
        long long arr[n + 1];
        for(ll i = 1; i <= n; i++){
            cin >> arr[i];
        }
        while(q--){
            ll pos, val;
            cin >> pos >> val;
            arr[pos] = val;
            ll final = 0;
            for(ll i = 1; i <= (n - m + 1); i++){
                for(ll j = 1; j <= (n - m + 1); j++){
                    for(ll k = 0; k < m; k++){
                        // cout << "i: " << i << " j: " << j << " k: " << k;
                        final += ((arr[i + k]) * (arr[j + k])) % mod;
                        // cout << " final: " << final << endl;
                    }
                }
            }
            cout << final << endl;
        }
    }


    return 0;
}