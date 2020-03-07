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
    unordered_map<int, bool> umap;
    for(ll i = 0; i < n; i++){
        cin >> arr[i];
        // umap[arr[i]] = true;
        umap.insert({arr[i], true});
    }
    ll target;
    cin >> target;
    ll flag = 0;
    for(ll i = 0; i < n; i++){
        ll k = target - arr[i];
        if(target == k){
            continue;
        }
        else{
            if(umap.find(k) != umap.end()){
                flag = 1;
                cout << "I have found: " << arr[i] << " and " << k << endl;
            }
        }
    }
    if(flag == 0){
        cout << "Element not found" << endl;
    }

    return 0;
}