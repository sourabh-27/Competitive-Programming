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
        ll n, s;
        cin >> n >> s;
        ll left = 100 - s;
        long long price[n + 1];
        // vector<ll> vec1, vec2;
        ll mini1 = INT_MAX; ll mini2 = INT_MAX;
        for(ll i = 0; i < n; i++){
            cin >> price[i];
        }
        for(ll i = 0; i < n; i++){
            ll x; cin >> x;
            if(x == 1){
                mini1 = min(mini1, price[i]);
            }
            else{
                mini2 = min(mini2, price[i]);
            }
        }
        if(mini1 + mini2 <= left){
            cout << "yes" << endl;
        }
        else{
            cout << "no" << endl;
        }

    }


    return 0;
}