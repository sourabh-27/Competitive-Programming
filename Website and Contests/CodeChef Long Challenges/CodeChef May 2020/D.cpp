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

ll powFunc(ll a, ll b){
    ll res = 1;
    for(ll i = 0; i < b; i++){
        res = res * 2;
    }
    return res;
}
int main()
{
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll x, y, l, r;
        cin >> x >> y >> l >> r;
        if(x == 0 || y == 0){
            cout << 0 << endl;
        }
        ll a = x; ll b = y; ll c = l; ll d = r; ll e = x | y;
        long long arr[64], arr2[64], arr3[64], arr4[64], arr5[64];
        for(ll i = 0; i < 63; i++){
            arr[i] = a & 1; a = a >> 1; //right shift
            arr2[i] = b & 1; b = b >> 1;
            arr3[i] = e & 1; e = e >> 1;
            arr4[i] = c & 1; c = c >> 1;
            arr5[i] = d & 1; d = d >> 1;
        }
        ll power = 0; ll flag = 0; ll power2 = 0;
        for(ll i = 62; i >= 0; i--){
            if(arr5[i] == 1 && arr3[i] == 1){
                flag = 1;
                power += powFunc(2, i);
            }
            if(flag == 1){
                power2 += powFunc(2, i);
            }
        }
        cout << "power: " << power << " power2: " << power2 << endl;
        ll ans1 = 0, ans2 = 0; ll maxi = 0;
        if(r > power){
            maxi = max(maxi, (x & ans1)*(y & ans2));
            ans1 = power;
        }  
        cout << "ans1: " << ans1 << endl;

        for(ll i = 62; i >= 0; i--){
            if(arr5[i] == 1){
                ll pow1 = powFunc(2, 62) - powFunc(2, i + 1); pow1 = pow1 & r;
                ll pow2 = powFunc(2, i); pow2 = (pow2 & power) - 1;
                ll poss = pow1 | pow2;
                if(r >= poss){
                    ll poss2 = (x & poss) * (y & poss);
                    if(poss2 == maxi){
                        ans1 = min(ans1, poss);
                    }
                    else if(poss2 > maxi){
                        ans1 = poss;
                    }
                    else{
                        continue;
                    }
                }
            }
        }
        cout << ans1 << endl;
    }


    return 0;
}