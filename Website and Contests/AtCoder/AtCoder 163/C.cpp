#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
#define pb push_back
#define mp make_pair
typedef long long int ll;
 
int main()
{
    fast;
    ll n;
    cin >> n;
    long long arr[n + 1];
    map<ll, ll> umap;
    for(ll i = 0; i < n - 1; i++){
        cin >> arr[i];
        umap[arr[i]]++;
    }

    for(auto x: umap){
        cout << x.second << endl;
    }
    for(ll i = 0; i < n - umap.size(); i++){
        cout << 0 << endl;
    }

}