#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;
 
int main()
{
    fast;
    ll t, s;
    cin >> t >> s;
    while(t--){
        ll n;
        cin >> n;
        long long arr[n + 1], arr2[n + 1];
        unordered_map<ll, ll> umap, umap2;
        for(ll i = 0; i < n; i++){
            cin >> arr[i];
            umap[arr[i]]++;
        }
        for(ll i = 0; i < n; i++){
            cin >> arr2[i];
            umap[arr2[i]]++;
            umap2[arr2[i]]++;
        }
        sort(arr, arr + n);
        sort(arr2, arr2 + n);
        // for(ll i = 0; i < n; i++){
        //     cout << arr[i] << " ";
        // }
        // cout << endl;
        // for(ll i = 0; i < n; i++){
        //     cout << arr2[i] << " ";
        // }
        // cout << endl;
        int flag = 0;
        ll count = 0;
        for(ll i = 0; i < n; i++){
            if(umap[arr[i]] == 1){
                count++;
                if(count == 2){
                    flag = 1;
                    break;
                }
            }
        }
        ll count2 = 0;
        for(ll i = 0; i < n; i++){
            if(umap2.find(arr[i]) == umap2.end()){
                count2++;
                // cout << "arr[i]: " << arr[i] << " not present and coun2: " << count2 << endl;
                umap2[arr[i]] = 10;
                if(count2 == 2){
                    flag = 1;
                    break;
                }
            }
        }
        // if(umap[arr[]])
        // cout << arr[0] << " " << arr2[0] << endl;
        for(ll i = 0; i < n; i++){
            if(arr2[i] <= arr[i]){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }

    return 0;
}