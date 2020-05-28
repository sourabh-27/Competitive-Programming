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
        long long arr[n + 2];
        unordered_map<ll, ll> umap;
        vector<ll> vec;
        vector<tuple<ll, ll, ll>> final;
        for(ll i = 1; i <= n; i++){
            cin >> arr[i];
            umap[arr[i]] = i;
            if(arr[i] != i){
                vec.pb(i);
            }
        }
        if(n % 4 > 1){
            cout << -1 << endl;
            continue;
        }

        ll x = 0;
        for(ll i = 1; i <= n - 2; i++){
            if(arr[i] == i){
                continue;
            }
            ll e1, e2, e3;
            if(!vec.empty()){
                e1 = vec[x]; e2 = vec[x+1];
                e3 = umap[i];
                if(e3 == e1 || e3 == e2){
                    // cout << "YO1" << endl;
                    e3 = vec[x+2];
                    final.pb(make_tuple(e3,e1,e2)); //e3 e2 e1
                    ll val1 = arr[e1]; ll val2 = arr[e2]; ll val3 = arr[e3];
                    arr[e1] = val2; arr[e2] = val3; arr[e3] = val1;
                }
                else{
                    // cout << "YO2" << endl;
                    final.pb(make_tuple(e1,e2,e3));
                    // swap(arr[e3], arr[e1]);
                    // swap(arr[e1], arr[e2]);
                    ll val1 = arr[e1]; ll val2 = arr[e2]; ll val3 = arr[e3];
                    // cout << "v1: " << val1 << " val2: " << val2 << " val3: " << val3 << endl;
                    arr[e1] = val3; arr[e2] = val1; arr[e3] = val2;
                }
                x++;
            }
            // cout << "e1: " << e1 << " e2: " << e2 << " e3: " << e3 << endl;
            // for(ll j = 1; j <= n; j++){
            //     cout << arr[j] << " ";
            // }
            // cout << endl;
        }
        // cout << "vec.sizee(): " << final.size() << endl;
        // for(ll j = 1; j <= n; j++){
        //     cout << arr[j] << " ";
        // }
        // cout << endl;
        ll flag = 0;
        for(ll i = 1; i <= n; i++){
            if(i != arr[i]){
                // cout << "i: " << i << " arr[i]: " << arr[i] << endl;
                flag = 1;
                break;
            }
        }
        if(final.size() > k || flag == 1){
            cout << -1 << endl;
        }
        else{
            cout << final.size() << endl;
            for(ll i = 0; i < final.size(); i++){
                cout << get<0>(final[i]) << " " << get<1>(final[i]) << " " << get<2>(final[i]) << endl;
            }
        }
    }


    return 0;
}