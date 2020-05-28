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
        ll n, m, k;
        cin >> n >> m >> k;
        long long vec[n + 1][k + 1];
        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < k; j++){
                ll x;
                cin >> x;
                vec[i][j] = x;
            }
        }

        for(ll i = 0; i < n; i++){
            unordered_map<ll, ll> umap;
            ll maxi = INT_MIN; ll element; ll mini = INT_MAX; ll element2; ll final = 0;
            for(ll j = 0; j < k; j++){
                umap[vec[i][j]]++;
                if(umap[vec[i][j]] > maxi){
                    maxi = umap[vec[i][j]];
                    element = vec[i][j];
                }
                if(umap[vec[i][j]] < mini){
                    mini = umap[vec[i][j]];
                    element2 = vec[i][j]; 
                }
            }
            ll count = 0;
            for(ll j = 0; j < k; j++){
                if(umap[vec[i][j]] == maxi){
                    count++;
                }
            }
            if(count >= 2){
                cout << element2 << " ";
                continue;
            }
            cout << element << " ";
        }
        cout << endl;

    }
    return 0;
}