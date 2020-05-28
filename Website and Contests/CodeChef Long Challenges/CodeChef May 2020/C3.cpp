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

bool isSorted(long long * arr, ll n){
    for(ll i = 1; i <= n; i++){
        if(arr[i] != i){
            return false;
        }
    }
    return true;
}

int main()
{
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        long long arr[n + 2];
        ll count = 0;
        for(ll i = 1; i <= n; i++){
            cin >> arr[i];
            if(arr[i] != i){
                count++;
            }
        }
        // if(count <= 2){
        //     // cout << "YO" << endl;
        //     cout << -1 << endl;
        //     continue;
        // }
        // else{
            vector<tuple<ll, ll, ll>> vec;
            ll flag = 0;
            for(ll i = 1; i <= n; i++){
                if(arr[i] == i){
                    continue;
                }
                // cout << "i: " << i << endl;
                ll e1, e2, e3; 
                ll val1, val2, val3;
                e1 = i; val1 = arr[i];
                e2 = val1; val2 = arr[arr[i]];
                e3 = -1; flag = 0;
                if(arr[arr[i]] == i){ //the biggest bakchodi here 
                    for(ll j = n; j >= 1; j--){ //forward lookout
                        if(arr[j] == j || j == e1 || j == e2){
                            continue;
                        }
                        else{
                            e3 = j;
                            val3 = arr[e3];
                            break;
                        }
                    }
                    // if(e3 == -1){ //backward lookout
                    //     for(ll j = e1 - 1; j >= 1; j--){
                    //         if(arr[j] == j || j == e1 || j == e2){
                    //             continue;
                    //         }
                    //         else{
                    //             e3 = j;
                    //             val3 = arr[e3];
                    //             break;
                    //         }
                    //     }
                    // }
                }
                else{
                    e3 = val2;
                    val3 = arr[e3];
                }
                // cout << "e1: " << e1 << " e2: " << e2 << " e3: " << e3 << endl;
                if(e3 == -1){
                    continue;
                }
                if(e3 == -1 || (e1 == e2 || e2 == e3 || e3 == e1)){
                    flag = 1;
                    break;
                }
                // cout << "i: " << i << " arr[arr[i]]: " << arr[arr[i]] << endl;
                if(arr[arr[i]] == i){
                    // cout << "YO" << endl;
                    val2 = arr[e3];
                    val3 = arr[val1 - 1];
                    arr[i] = val3;
                    arr[e3] = val1;
                    arr[val1 - 1] = val2;
                    tuple<ll, ll, ll> tup(i, e3, val1);
                    vec.pb(tup);
                }
                else{
                    //swap values and push in tuple
                    // cout << "YO" << endl;
                    arr[e1] = val3;
                    arr[e2] = val1;
                    arr[e3] = val2;
                    tuple<ll, ll, ll> tup(e1, e2, e3);
                    vec.pb(tup);
                }
                // // cout << "YO" << endl;
                // if(vec.size() > k){
                //     flag = 1;
                //     break;
                // }
                // for(ll j = 1; j <= n; j++){
                //     cout << arr[j] << " ";
                // }
                // cout << endl;
                // cout << "YO" << endl;
            }
            
            // cout << "flag: " << flag << " vec.size(): " << vec.size() <<  " isSorted(arr,n): " << isSorted(arr, n) << endl;
            if(flag == 1 || vec.size() > k || !isSorted(arr, n)){
                cout << -1 << endl;
                continue;
            }
            else{
                cout << vec.size() << endl;
                for(ll i = 0; i < vec.size(); i++){
                    cout << get<0>(vec[i]) << " " << get<1>(vec[i]) << " " << get<2>(vec[i]) << endl;
                }
            }

        // }
    }


    return 0;
}