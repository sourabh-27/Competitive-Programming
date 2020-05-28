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
        long long arr[n + 1];
        set<ll> se;
        for(ll i = 0; i < n; i++){
            cin >> arr[i];
            se.insert(arr[i]);
        }
        if(se.size() > k){
            cout << -1 << endl;
            continue;
        }
        else{
            cout << se.size() * n << endl;
            vector<ll> vec; vector<ll> vec2;
            for(auto x: se){
                vec.pb(x);
            }
            ll j = 0;
            for(ll i = 0; i < k; i++, j++){
                if(i % vec.size() == 0){
                    j = 0;
                }
                vec2.pb(vec[j]);
            }
            for(ll i = 0; i < se.size() * n; i++){
                cout << vec2[i % vec2.size()] << " ";
            }
        }
    }


    return 0;
}