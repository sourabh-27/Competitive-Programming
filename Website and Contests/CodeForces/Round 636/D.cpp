#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
#define pb push_back
#define mp make_pair
typedef long long int ll;

ll findAns(long long * arr, ll n, ll element, ll k){
    ll ans2 = 0;
    for(ll i = 0; i < n / 2; i++){
        if(arr[i] + arr[n - i - 1] == element){
            continue;
        }
        else if((element - arr[i] <= k && element - arr[i] > 0) || (element - arr[n - i - 1] <= k && element - arr[n - i - 1] > 0)){
            ans2 += 1;
        }
        else{
            ans2 += 2;
        }
    }
    return ans2;
}
 
int main()
{
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        long long arr[n + 1];
        ll count = 0;
        for(ll i = 0; i < n; i++){
            cin >> arr[i];
            if(arr[i] > k){
                count++;
            }
        }
        // cout << "count: " << count << endl;
        ll ans = findAns(arr, n, k, k);
        // cout << "ans: " << ans << endl;
        unordered_map<ll, ll> umap;
        ll maxi = INT_MIN; ll element;
        for(ll i= 0 ; i < n / 2; i++){
            if(arr[i] > k || arr[n - i - 1] > k){
                continue;
            }
            else{
                umap[arr[i] + arr[n - i - 1]]++;
                if(maxi < umap[arr[i] + arr[n - i - 1]]){
                    maxi = umap[arr[i] + arr[n - i - 1]];
                    element = arr[i] + arr[n - i - 1];
                }
            }
        }
        // cout << "element: " << element << endl;
        ll final = INT_MIN;
        for(auto x: umap){
            if(x.second == maxi){
                final = max(final, x.first);
            }
        }

        ll mini = INT_MAX;
        // for(ll i = 2 * k; i >= 2; i--){
        //     ll z = findAns(arr, n, i, k);
        //     // cout << "i: " << i << " z: " << z << endl;
        //     if(z < mini){
        //         mini = z;
        //     }
        //     // if(z > mini){
        //     //     break;
        //     // }
        // }
        for(auto x: umap){
            ll z = findAns(arr, n, x.first, k);
            if(z < mini){
                mini = z;
            }
        }
        ll ans2 = findAns(arr, n, final, k);
        ll ans3 = findAns(arr, n, 2 * k, k);
        cout << min(ans, min(ans2, min(ans3, mini))) << endl;
    }


    return 0;
}