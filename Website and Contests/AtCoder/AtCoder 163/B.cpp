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
        umap[arr[i] - 1]++;
    }
 
    for(ll i = 0; i < n; i++){
        if(umap.find(i) != umap.end()){
            cout << umap[i] << " ";
        }
        else{
            cout << 0 << " ";
        }
    }
    cout << endl;
 
}