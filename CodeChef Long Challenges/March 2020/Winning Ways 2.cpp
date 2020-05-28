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
        ll n;
        cin >> n;
        long long arr[n + 1];
        for(ll i = 0; i < n; i++){
            cin >> arr[i];
        }
        // sort(arr, arr + n);
        ll q;
        cin >> q;
        while(q--){
            ll l, r;
            cin >> l >> r;
            l--; r--;
            unordered_map<ll, pair<ll, bool>> umap;
            // ll countR = 0; ll countU = 0;
            for(ll i = l; i <= r; i++){
                umap[arr[i]].first++;
            }

            ll countE = 0, countO = 0, countU = 0; //even odd unique
            for(ll i = l; i <= r; i++){
                // cout << "arr[i]: " << arr[i] << " ";
                if(umap[arr[i]].first == 1){
                    countU++;
                }
                if(umap[arr[i]].first % 2 == 0 && umap[arr[i]].second == false && umap[arr[i]].first >= 2){
                    countE++;
                    umap[arr[i]].second = true;
                }
                else if(umap[arr[i]].first % 2 != 0 && umap[arr[i]].second == false && umap[arr[i]].first >= 2){
                    countO++;
                    umap[arr[i]].second = true;
                }
            }
            // cout << endl;
            // cout << "countE: " << countE << " countO: " << countO << " countU: " << countU << endl;
            if(countU % 2 == 0 && countE == 0 && countO == 0){
                cout << 0 << endl;
            }
            else if(countU % 2 != 0 && countE == 0 && countO == 0){
                cout << countU << endl;
            }
            else if(countU % 2 != 0 && countO % 2 != 0 && countE == 0){
                cout << r - l << endl;
            }
            else if(countU % 2 != 0 && countE % 2 != 0 && countO == 0){
                cout << r - l << endl;
            }
        }
    }

    return 0;
}