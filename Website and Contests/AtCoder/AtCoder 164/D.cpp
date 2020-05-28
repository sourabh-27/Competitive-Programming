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

ll modexp(ll a,ll b,ll m)
{
    ll r=1;
    a=a%m;
    while(b>0)
    {
        if(b&1)r=(r*a)%m;
        b = b>>1;
        a=(a*a)%m;
    }
    return r%m;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    string s; cin>>s;
    reverse(all(s));
    ll n = s.size();
    vector<ll> arr(n);
 
    for(ll i=0;i<n;i++)
    {
        arr[i] = (s[i]-'0');
        // cout << "iE: " << i << " arr[i]: " << arr[i] << endl;
        arr[i] *= (modexp(10,i,2019))%2019;
        // cout << "i: " << i << " arr[i]: " << arr[i] << endl;
    }
    vector<ll> pref(n);
    pref[0] = arr[0];
    rep(i,1,n)pref[i]= (pref[i-1]+arr[i])%2019;
    rep(i,0,n)cout<<pref[i]<<endl;
    map<ll,ll>mp;
    ll ans = 0;
    for(ll i=0;i<n;i++)
    {
        cout << "i: " << i << " pref[i]: " << pref[i] << endl;
        if(pref[i]==0)ans++;
        cout << "i: " << i << " ans: " << ans << endl;
        ans+=mp[pref[i]];
        cout << "add map from pref[i]: " << pref[i] << " to: " << mp[pref[i]] << endl;
        mp[pref[i]]++;
    }
    cout<<ans<<endl;
    return 0;
}