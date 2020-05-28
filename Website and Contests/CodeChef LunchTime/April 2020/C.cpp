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
        ll n, k;
        cin >> n >> k;
        long long arr[n + 2];
        long long arr2[n + 2];
        for(ll i = 1; i <= n; i++){
            cin >> arr2[i];
            arr[i] = arr2[i];
        }
        sort(arr2 + 1, arr2 + n + 1);
        map<ll, vector<ll>> umap;
        for(ll i = 1; i <= n; i++){
            umap[arr2[i]].pb(i);
            // cout << "i: " << i << endl;
        }
        ll flag = 0;
        for(ll i = 1; i <= n; i++){
            // cout << "pos: " << umap[arr[i]] << endl;
            if(arr[i] == arr2[i]){
                continue;
            }
            ll flag2 = 0;
            for(auto x: umap[arr[i]]){
                if((abs(i - x)) % k == 0){
                    flag2 = 1;
                    break;
                }
            }
            if(flag2 == 0){
                flag = 1;
            }
        }
        if(flag == 1){
            cout << "no" << endl;
        }
        else{
            cout << "yes" << endl;
        }
    }


    return 0;
}