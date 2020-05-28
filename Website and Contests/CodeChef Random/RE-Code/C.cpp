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
    ll t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        if(n == 0){
            ll z1 = ((k % mod) * ((k - 1) % mod)) % mod;
            cout << z1 << endl;
            continue;
        }
        ll temp = k;
        ll sum = ((n % mod) + ((temp / 2) % mod)) % mod;
        ll sum2 = ((n % mod) + (((temp / 2) + 1) % mod)) % mod;
        ll ans = ((sum % mod) * (sum2 % mod)) % mod;
        // cout << "ans: " << ans << endl;
        if(k % 2 == 0){
            ll sub = (n % mod) + ((k / 2) % mod);
            sub = (sub * 2) % mod;
            ans = ans - sub + n;
        }
        else{
            ans = ans - n;
        }
        if(ans < 0){
            ans = ans + mod;
        }
        cout << ans % mod << endl;
    }


    return 0;
}