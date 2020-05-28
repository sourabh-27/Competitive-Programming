#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

ll sQ(ll x){
    return (1LL * x * x);
}

void findAns(vector<ll> vec1, vector<ll> vec2, vector<ll> vec3, ll & ans){
    for(auto x : vec1){
        auto v1 = lower_bound(vec2.begin(), vec2.end(), x);
        auto v2 = upper_bound(vec3.begin(), vec3.end(), x);
        if(v1 == vec2.end() || v2 == vec3.begin()) continue;
        v2--;
        ans = min(ans, sQ(x - *v1) + sQ(*v1 - *v2) + sQ(*v2 - x));
    }
}
 
int main()
{
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll rg, gg, bg;
        cin >> rg >> gg >> bg;
        vector<ll> rgVec(rg + 1);
        vector<ll> ggVec(gg + 1);
        vector<ll> bgVec(bg + 1);
        for(ll i = 0; i < rg; i++){
            ll x; cin >> x;
            rgVec.push_back(x);
        }
        for(ll i = 0; i < gg; i++){
            ll x; cin >> x;
            ggVec.push_back(x);
        }
        for(ll i = 0; i < bg; i++){
            ll x; cin >> x;
            bgVec.push_back(x);
        }
        sort(rgVec.begin(), rgVec.end()); sort(ggVec.begin(), ggVec.end()); sort(bgVec.begin(), bgVec.end());
        ll ans = 9e18;
        findAns(rgVec, ggVec, bgVec, ans); findAns(rgVec, bgVec, ggVec, ans);
        findAns(ggVec, rgVec, bgVec, ans); findAns(ggVec, bgVec, rgVec, ans);
        findAns(bgVec, rgVec, ggVec, ans); findAns(bgVec, ggVec, rgVec, ans);
        cout << ans << endl;
    }


    return 0;
}