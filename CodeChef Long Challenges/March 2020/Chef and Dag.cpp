#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;
 
int main()
{
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        long long arr[k + 1][n + 1];
        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < n; j++){
                arr[i][j] = 0;
            }
        }
        unordered_map<ll, ll> umap;
        for(ll i = 0; i < k; i++){
            for(ll j = 0; j < n; j++){
                cin >> arr[i][j];
            }
        }
        for(ll i = 0; i < k; i++){
            for(ll j = 1; j < n; j++){
                if(umap.find(arr[i][j]) == umap.end()){
                    umap[arr[i][j]] = arr[i][j];
                }
            }
        }
    }

    return 0;
}