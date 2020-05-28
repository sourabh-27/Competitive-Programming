#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
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
    ll n, m, x;
    cin >> n >> m >> x;
    long long arr[14][14]; long long cost[14];
    for(ll i = 1; i <= n; i++){
        cin >> cost[i];
        for(ll j = 1; j <= m; j++){
            cin >> arr[i][j];
        }
    }

    ll ans = 1e18;
    for(ll mask = 1; mask < (1 << n); mask++){
        // cout << mask << " " << endl;
        ll flag = 0;
        for(ll j = 1; j <= m; j++){
            ll sum = 0;
            for(ll i = 1; i <= n; i++){
                ll k = (mask & (1 << (i - 1)));
                if(k != 0){
                    sum = sum + arr[i][j];
                }
            }
            if(sum < x){
                flag = 1;
                break;
            }
            // cout << "sum: " << sum << endl;
        }
        if(flag == 0){
            ll val = 0;
            for(ll i = 1; i <= n; i++){
                ll k = (mask & (1 << (i - 1)));
                if(k != 0){
                    val += cost[i];
                }
            }
            ans = min(ans, val);
        }
    }
    if(ans == 1e18){
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;


    return 0;
}