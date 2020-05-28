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
    testcase:
        while(t--){
            ll n, k;
            cin >> n >> k;
            long long arr[n + 2];
            for(ll i = 1; i <= n; i++){
                cin >> arr[i];
            }

            vector<tuple<ll, ll, ll>> vec;
            for(ll i = 1; i <= n; i++){
                if(arr[i] == i){
                    continue;
                }
                else{
                    ll val1 = arr[i]; ll val2 = arr[arr[i]];
                    ll val3;
                    if(val2 == i){
                        val3 = -1;
                        // cout << -1 << endl;
                        // goto testcase;
                    }
                    else{
                        val3 = arr[arr[arr[i]]];
                    }
                    // cout << "i: " << i << " val1: " << val1 << " val2: " << val2 << " val3: " << val3 << endl;
                    if(val3 == -1){
                        // cout << "i: " << i << endl;
                        ll t1 = arr[i]; ll t2 = i;
                        int vall[4] = {0};
                        ll t3;
                        ll possible1 = min(t1, t2) - 1; ll possible2 = max(t1, t2) + 1; ll possible3 = i + 1;
                        // cout << "p1: " << possible1 << " p2: " << possible2 << " p3: " << possible3 << endl;
                        if(possible1 >= 1){
                            vec.pb(make_tuple(arr[i], i, possible1));
                        }
                        else if(possible2 <= n){
                            vec.pb(make_tuple(i, possible2, arr[i]));
                        }
                        else if(possible3 > i && possible3 < arr[i]){
                            // cout << "YO" << endl;
                            val3 = possible3;
                            vec.pb(make_tuple(i, possible3, arr[i]));
                            swap(arr[possible3], arr[arr[i]]);
                        }
                        // vec.pb(make_tuple(t1, t2, ));
                        // swap(arr[i], arr[arr[i]]);
                    }
                    // else{
                        // for(ll j = 1; j <= n; j++){
                        //     cout << arr[j] << " ";
                        // }
                        // cout << endl;
                        val1 = arr[i]; val2 = arr[arr[i]]; val3 = arr[arr[arr[i]]];
                        ll t1 = i; ll t2 = arr[i]; ll t3 = arr[arr[i]];
                        // cout << "t1: " << t1 << " t2: " << t2 << " t3: " << t3 << endl;
                        vec.pb(make_tuple(t1, t2, t3));
                        arr[arr[arr[i]]] = val2; arr[arr[i]] = val1; arr[i] = val3;
                    // }
                    

                }
            }
            // for(ll i = 1; i <= n; i++){
            //     cout << arr[i] << " ";
            // }
            // cout << endl;
            if(vec.size() > k){
                cout << -1 << endl;
            }
            else{
                cout << vec.size() << endl;
                for(ll i = 0; i < vec.size(); i++){
                    cout << get<0>(vec[i]) << " " << get<1>(vec[i]) << " " << get<2>(vec[i]) << endl;
                }
            }
        }


    return 0;
}