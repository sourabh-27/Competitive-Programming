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
    unordered_map<ll, ll> umap;
    for(ll i = 0; i < n; i++){
        cin >> arr[i];
        umap[arr[i]]++;
    }

    for(auto x = umap.begin(); x != umap.end(); x++){
        if(x->second >= 2){
            cout << x->first << " ";
        }
    }

    return 0;
}