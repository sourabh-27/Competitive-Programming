#include<bits/stdc++.h>
using namespace std; 
#define mod 998244353
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

ll power(ll x, unsigned int y)  
{  
    ll res = 1;
    x = x % mod;
    if(x == 0) return 0;
    while(y > 0)  
    {    
        if (y & 1)  
            res = (res*x) % mod;  
        y = y >> 1;
        x = (x * x) % mod;  
    }  
    return res;  
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
        map<ll, ll> umap;
        for(ll i = 0; i < n; i++){
            cin >> arr[i];
            umap[arr[i]]++;
        }

        ll count = 1;
        vector<ll> ans;
        ll bre = 0; ll flag = 0;
        for(auto x : umap){
            if(x.first != count){
                flag = 1;
                bre += x.second;
                break;
            }
            else{
                ans.push_back(x.second);
                count++;
            }
        }
        if(flag == 1){
            ans.push_back(bre);
        }
        for(ll i = 0; i < ans.size(); i++){
            cout << "i: " << i << " ans: " << ans[i] << endl;
        }
    }


    return 0;
}