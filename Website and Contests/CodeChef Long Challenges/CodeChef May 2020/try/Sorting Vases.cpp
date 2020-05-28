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
        ll n, m;
        cin >> n >> m;
        long long arr[n + 2];
        for(ll i = 1; i <= n; i++){
            cin >> arr[i];
        }
        long long arr2[m + 1];
        for(ll i = 1; i <= m; i++){
            cin >> arr2[i];
        }
        ll count = 0;
        for(ll i = 1; i <= n; i++){
            if(arr[i] == i){
                continue;
            }
            else{
                count++;
                ll e1 = i; ll e2 = arr[i];
                ll val1 = arr[e1]; ll val2 = arr[e2];
                arr[e1] = val2; arr[e2] = val1;
            }
        }
        cout << count << endl;
    }


    return 0;
}