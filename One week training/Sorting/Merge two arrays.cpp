#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

vector<ll> merge(long long * arr, long long * arr2, ll m, ll n){
    vector<ll> vec;
    ll i = 0; ll j = 0; ll k = 0;
    while(i < m && j < n){
        if(arr[i] > arr2[j]){
            vec.push_back(arr2[j]);
            j++; k++;
        }
        else{
            vec.push_back(arr[i]);
            i++; k++;
        }
    }

    while(i < m){
        vec.push_back(arr[i]);
    }
    while(j < n){
        vec.push_back(arr2[j]);
    }
    return vec;
}
 
int main()
{

    fast;
    ll m;
    cin >> m;
    long long arr[m + 1], arr2[n + 1];

    for(ll i = 0; i < m; i++){
        cin >> arr[i];
    }

    ll n;
    cin >> n;
    for(ll j = 0; j < n; j++){
        cin >> arr2[j];
    }

    vector<ll> ans = merge(arr, arr2, m, n);
    for(ll i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}