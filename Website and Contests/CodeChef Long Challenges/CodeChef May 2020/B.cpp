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
        ll n, q;
        cin >> n >> q;
        string str;
        cin >> str;
        unordered_map<char, ll> umap;
        for(ll i = 0; i < str.length(); i++){
            umap[str[i]]++;
        }
        while(q--){
            ll c;
            cin >> c;
            ll ans = 0;
            for(auto x: umap){
                if(c < x.second){
                    ans = ans + x.second - c;
                }
            }
            cout << ans << endl;
        }
    }


    return 0;
}