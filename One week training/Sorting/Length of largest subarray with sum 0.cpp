#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;
 
int main()
{
    fast;
    ll n;
    cin >> n;
    long long arr[n + 1];

    for(ll i = 0; i < n; i++){
        cin >> arr[i];
    }

    ll ans = INT_MIN;
    unordered_map<int, int> umap;
    long long prefixSum = 0;
    umap.insert({0, -1});
    for(ll i = 0; i < n; i++){
        prefixSum += arr[i];
        if(umap.count(prefixSum) == 0){
            umap[prefixSum] = i;
        }
        else{
            ll len = i - umap[prefixSum];
            ans = max(ans, len);
        }
    }
    cout << "Maximum length is: " << ans << endl;

    return 0;
}