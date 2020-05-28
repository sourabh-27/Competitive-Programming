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
typedef unsigned long long int ull;

ll x, y, l, r;
ll powFunc(ll a, ll b){
    ull res = 1;
    for(ll i = 0; i < b; i++){
        res = res * 2;
    }
    return res;
}

void calcFunc(ull &maxi, ull &ans, ll pwr){
    ll possibility = (x & pwr) * (y & pwr);
    if(possibility > maxi){
        maxi = possibility;
        ans = pwr;
    }
    else if(possibility == maxi){
        if(pwr < ans){
            ans = pwr;
        }
    }
}

int main()
{
    fast;
    ll t;
    cin >> t;
    while(t--){
        cin >> x >> y >> l >> r;
        if(x == 0 || y == 0){
            cout << 0 << endl;
        }
        ll a = x; ll b = y; ll c = l; ll d = r; ll e = x | y;
        long long arr3[64], arr5[64];
        for(ll i = 0; i < 63; i++){
            arr3[i] = e & 1; e = e >> 1;
            arr5[i] = d & 1; d = d >> 1;
        }
        ull power = 0; ll index = 0; ull power2 = 0;
        for(ll i = 62; i >= 0; i--){
            if(arr3[i] == 1){
                // cout << "i: " << i << endl;
                index = i;
                break;
            }
        }
        for(ll i = index; i >= 0; i--){
            if(arr3[i] == 1){
                power += powFunc(2, i);
            }
        }
        for(ll i = index; i >= 0; i--){
            if(arr3[i] == 1 && arr5[i] == 1){
                power2 += powFunc(2, i);
            }
        }
        // cout << "power: " << power << endl;
        ull ans1 = 10e12 + 10; ull maxi = 0;
        if(power >= l && power <= r){
            calcFunc(maxi, ans1, power);
        }  
        // cout << "maxi: " << maxi << " ans1: " << ans1 << endl;

        if(power2 >= l && power2 <= r){
            calcFunc(maxi, ans1, power2);
        }
        // cout << "maxi: " << maxi << " ans11: " << ans1 << endl;
        // ll powe = powFunc(2, 62);
        // cout << "powe: " << powe << endl;
        for(ll i = 62; i >= 0; i--){
            if(arr5[i] == 1){
                ull pow1 = powFunc(2, 62) - powFunc(2, i + 1); pow1 = pow1 & r;
                ull pow2 = powFunc(2, i) - 1; pow2 = pow2 & power;
                ull poss = pow1 | pow2;
                if(poss >= l && poss <= r){
                    calcFunc(maxi, ans1, poss);
                }
            }
        }
        if(maxi != 0){
            cout << ans1 << endl;
        }
        else{
            cout << 0 << endl;
        }
    }


    return 0;
}