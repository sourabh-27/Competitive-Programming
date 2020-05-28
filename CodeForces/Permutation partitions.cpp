#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;
 
int main()
{
    fast;
    ll n, k;
    cin >> n >> k;
    long long arr[n + 1];
    unordered_map<ll, ll> umap;
    for(ll i = 0; i < n; i++){
        cin >> arr[i];
        umap[arr[i]]++;
    }
    sort(arr, arr + n, greater<int>());
    ll sum = 0;
    for(ll i = 0; i < k; i++){
        sum = sum + arr[i];
    }


    return 0;
}