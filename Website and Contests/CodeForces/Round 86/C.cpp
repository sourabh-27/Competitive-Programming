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
        ll a, b, q;
        cin >> a >> b >> q;
        ll lcm = (a * b) / (__gcd(a, b)); //yaha tak jyga
        long long * dp = new long long[200 * 200 + 10];
        for(ll i = 0; i <= a * b; i++){
            if(((i % a) % b) != ((i % b) % a)){ 
                dp[i] = 1;
            }
            else{
                dp[i] = 0;
            }
        }
        long long * dp2 = new long long[200 * 200 + 10];
        dp2[0] = 0;
        for(ll i = 1; i <= a * b; i++){
            dp2[i] = dp2[i - 1] + dp[i];
            // cout << "dp2: " << dp2[i] << endl;
        }
        // cout << "lcm: " << lcm << endl;
        while(q--){
            ll l, r;
            cin >> l >> r;
            l = l - 1;
            // if(r < b){
            //     cout << 0 << " ";
            //     continue;
            // }
            // cout << "l: " << dp2[l % (a * b)] << endl;
            // cout << "r: " << dp2[r % (a * b)] << endl;
            ll left = l / (a * b); ll right = r / (a * b);
            ll add = dp2[a * b - 1] * (right - left);
            // cout << "add: " << add << endl;
            // cout << "left: " << left << endl; cout << "right: " << right << endl;
            cout << dp2[r % (a * b)] - dp2[l % (a * b)] + add << " ";  

            // ll count = 0;
            // for(ll i = 0; i <= lcm; i++){
            //     if(((i % a) % b) != ((i % b) % a)){ 
            //         count++;
            //     }
            // }
            // cout << "count: " << count << endl;
        }
        cout << endl;
    }


    return 0;
}