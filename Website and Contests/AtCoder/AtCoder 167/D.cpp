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
    ll n, k;
    cin >> n >> k;
    long long arr[n + 2];
    unordered_map<ll, ll> umap;
    for(ll i = 1; i <= n; i++){
        cin >> arr[i];
    }
    ll x = 1;
    ll count = 0; umap[x] = 1;  ll k2 = k;
    ll flag = 0; vector<ll> vec;
    ll start = -1;
    while(umap[x] <= 2){
        // cout << x << " ";
        x = arr[x];
        umap[x]++;
        // count++;
        k2--;
        if(k2 == 0 && k <= n){
            cout << x << endl;
            return 0;
        }
        if(umap[x] == 2){
            // cout << "x: " << x << endl;
            if(start == -1){
                start = x;
            }
            vec.pb(x);
            flag = 1;
        }
        if(flag == 1){
            count++;
        }
    }
    // cout << endl;
    // cout << "start: " << start << endl;
    vec.pb(x);
    count--;
    // cout << count << endl;
    ll ans = k % count;
    // cout << "umap[1]: " << umap[1] << endl;
    if(umap[start] == 1){
        ans = ans + 1;
    }
    // cout << "ans: " << ans << endl;
    // for(ll i = 0; i < vec.size(); i++){
    //     cout << vec[i] << " ";
    // }
    // cout << endl;
    cout << vec[ans] << endl;


    return 0;
}