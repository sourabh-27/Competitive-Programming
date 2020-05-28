#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define INF 0x3f3f3f3f
#define all(x) (x).begin(),(x).end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
#define pb push_back
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define mp make_pair
#define print(v); for(auto x:v) cout<<x<<" "; cout<<endl;
typedef long long int ll;
int main()
{
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        unordered_map<ll, bool> umap;
        long long arr[n + 1];
        for(ll i =0 ; i < n; i++){
            cin >> arr[i];
        }
        ll maxi = arr[0]; ll count = 1;
        umap[arr[0]] = true;
        for(ll i = 1; i < n; i++){
            if(arr[i] < maxi && umap[arr[i]] == false){
                count++;
                umap[arr[i]] = true;
            }
            else{
                umap[arr[i]] = true;
                maxi = max(maxi, arr[i]);
            }
        }
        cout << count << endl;
    }


    return 0;
}