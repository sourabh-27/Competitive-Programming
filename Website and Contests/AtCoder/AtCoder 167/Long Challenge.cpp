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

bool isSorted(long long * arr, ll n){
    for(ll i = 1; i <= n; i++){
        if(arr[i] != i){
            return false;
        }
    }
    return true;
}

int main()
{
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        long long arr[n + 2];
        ll count = 0;
        map<ll, ll> umap;
        for(ll i = 1; i <= n; i++){
            cin >> arr[i];
            umap[arr[i]] = i;
            if(arr[i] != i){
                count++;
            }
        }
        // if(count <= 2){
        //     // cout << "YO" << endl;
        //     cout << -1 << endl;
        //     continue;
        // }
        // else{
            vector<tuple<ll, ll, ll>> vec;
            ll flag = 0;
            for(ll i = 1; i <= n; i++){
                if(arr[i] == i || umap[i] == i || arr[i] == umap[i]){
                    continue;
                }
                // cout << "i: " << i << endl;
                ll e1, e2, e3; 
                ll val1, val2, val3;
                e1 = i; val1 = arr[i];
                e2 = val1; val2 = arr[arr[i]];
                // e3 = umap[i];
                // if(arr[i] != umap[i]){
                    e3 = umap[i];
                    val3 = i;
                    // cout << "e1: " << e1 << " e2: " << e2 << " e3: " << e3 << endl;
                    arr[i] = i; 
                    arr[e2] = val1;
                    arr[e3] = val2;
                    umap[i] = i; umap[val1] = e2; umap[val2] = e3;
                    tuple<ll, ll, ll> tup(e1, e2, e3);
                    vec.pb(tup);
                // }
                if(isSorted(arr, n)){
                    goto here;
                }
            }

            // for(ll i = 1; i <= n; i++){
            //     cout << arr[i] << " ";
            // }
            // cout << endl;
            if(isSorted(arr, n)){
                goto here;
            }

            for(ll i = 1; i <= n; i++){
                if(umap[i] == i){
                    continue;
                }
                // cout << "i: " << i << endl;
                ll e1, e2, e3; 
                ll val1, val2, val3;
                e1 = i; val1 = arr[i];
                e2 = -1;
                e3 = umap[i]; val3 = i; flag = 0;
                for(ll j = n; j > i; j--){
                    if(arr[j] != j && j != i && j != umap[i]){
                        e2 = j;
                        val2 = arr[e2];
                        break;
                    }
                }
                if(e2 == i || e2 == umap[i] || e2 == -1){
                    break;
                }
                else{
                    // cout << "e1: " << e1 << " e2: " << e2 << " e3: " << e3 << endl;
                    arr[i] = i;
                    arr[e2] = val1;
                    arr[e3] = val2;
                    umap[i] = i; umap[val1] = e2; umap[val2] = e3;
                    tuple<ll, ll, ll> tup(e1, e2, e3);
                    vec.pb(tup);
                }
                if(isSorted(arr, n)){
                    goto here;
                }
            }

            for(ll i = 1; i <= n; i++){
                if(umap[i] == i){
                    continue;
                }
                // cout << "i: " << i << endl;
                ll e1, e2, e3; 
                ll val1, val2, val3;
                e1 = i; val1 = arr[i];
                e2 = -1;
                e3 = umap[i]; val3 = i; flag = 0;
                for(ll j = n; j > i; j--){
                    if(arr[j] != j && j != i && j != umap[i]){
                        e2 = j;
                        val2 = arr[e2];
                        break;
                    }
                }
                if(e2 == i || e2 == umap[i] || e2 == -1){
                    break;
                }
                else{
                    // cout << "e1: " << e1 << " e2: " << e2 << " e3: " << e3 << endl;
                    arr[i] = i;
                    arr[e2] = val1;
                    arr[e3] = val2;
                    umap[i] = i; umap[val1] = e2; umap[val2] = e3;
                    tuple<ll, ll, ll> tup(e1, e2, e3);
                    vec.pb(tup);
                }
                if(isSorted(arr, n)){
                    goto here;
                }
            }

            for(ll i = 1; i <= n; i++){
                if(umap[i] == i){
                    continue;
                }
                // cout << "i: " << i << endl;
                ll e1, e2, e3; 
                ll val1, val2, val3;
                e1 = i; val1 = arr[i];
                e2 = -1;
                e3 = umap[i]; val3 = i; flag = 0;
                for(ll j = n; j > i; j--){
                    if(arr[j] != j && j != i && j != umap[i]){
                        e2 = j;
                        val2 = arr[e2];
                        break;
                    }
                }
                if(e2 == i || e2 == umap[i] || e2 == -1){
                    break;
                }
                else{
                    // cout << "e1: " << e1 << " e2: " << e2 << " e3: " << e3 << endl;
                    arr[i] = i;
                    arr[e2] = val1;
                    arr[e3] = val2;
                    umap[i] = i; umap[val1] = e2; umap[val2] = e3;
                    tuple<ll, ll, ll> tup(e1, e2, e3);
                    vec.pb(tup);
                }
                if(isSorted(arr, n)){
                    goto here;
                }
            }

            // for(ll i = 1; i <= n; i++){
            //     cout << arr[i] << " ";
            // }
            // cout << endl;
            
            // cout << "flag: " << flag << " vec.size(): " << vec.size() <<  " isSorted(arr,n): " << isSorted(arr, n) << endl;
            here:
                if(vec.size() > k || !isSorted(arr, n)){
                    cout << -1 << endl;
                    continue;
                }
                else{
                    cout << vec.size() << endl;
                    for(ll i = 0; i < vec.size(); i++){
                        cout << get<0>(vec[i]) << " " << get<1>(vec[i]) << " " << get<2>(vec[i]) << endl;
                    }
                }

        // }
    }


    return 0;
}