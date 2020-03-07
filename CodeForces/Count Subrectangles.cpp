#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;
 
int main()
{
    fast;
    ll n, m, k;
    cin >> n >> m >> k;
    long long arr[n + 1];
    long long arr2[n + 1];
    for(ll i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(ll i = 0; i < n; i++){
        cin >> arr2[i];
    }

    vector<ll> rect;
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        // cout << "arr[i]: " << arr[i] << endl;
        if(arr[i] == 1)
        {
            for(ll j = 0; j < n; j++){
                if(j == n - 1 && ans != 0){
                    if(arr[j] == 1){
                        ans = ans + 1;
                    }
                    rect.push_back(ans);
                    // cout << "i: " << i << endl;
                    ans = 0;
                }
                else if(arr2[j] == 0){
                    rect.push_back(ans);
                    // cout << "i: " << i << endl;
                    ans = 0;
                }
                else{
                    ans = ans + arr2[j];
                }
            }
        }
    }
    ll final = 0;
    for(ll i = 0; i < rect.size(); i++){
        final = final + rect[i] / k + 1;
    }
    cout << final << endl;

    return 0;
}