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

ll func(ll num){
    if(num % 2 == 0){
        return num / 2;
    }
    return (num / 2) + 1;
}
int main()
{
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        long long arr[n + 1];
        unordered_map<ll, ll> umap;
        for(ll i = 0; i < n; i++){
            cin >> arr[i];
        }
        ll count = 1;
        for(ll i = 0; i < n - 1; i++){
            if(arr[i] != arr[i + 1]){
                // cout << "i: " << i << " count: " << count << endl;
                umap[arr[i]] += func(count);
                count = 1;
            }
            else{
                count++;
            }
        }
        umap[arr[n - 1]] += func(count);
        ll element; ll maxi = INT_MIN;
        for(auto x: umap){
            if(x.second > maxi){
                maxi = x.second;
                element = x.first;
            }
            else if(x.second == maxi){
                if(x.first < element){
                    element = x.first;
                }
            }
        }
        cout << element << endl;
    }


    return 0;
}