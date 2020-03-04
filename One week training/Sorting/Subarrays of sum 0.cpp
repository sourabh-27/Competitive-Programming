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
    long long prefix[n + 1];
    unordered_map<int, int> umap;
    prefix[0] = 0;
    for(ll i = 0; i < n; i++){
        cin >> arr[i];
    }

    for(ll i = 1; i < n; i++){
        prefix[i] = prefix[i] + prefix[i - 1];
        if(umap.count(prefix[i]) == 0){
            umap[prefix[i]] = 1;
        }
        else{
            cout << "It is possible" << endl;
            break;
        }
    }


    return 0;
}