#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
#define pb push_back
#define mp make_pair
typedef long long int ll;
 
int main()
{
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;
        long long v[1000]; long long v2[1000];
        for(ll i = 0 ;i <  n; i++){
            cin >> v[i];
        }
        for(ll i = 0; i < m; i++){
            cin >> v2[i];
            v2[i] = v2[i] - 1;
        }
        sort(v2, v2 + m);
        for(ll i = 0; i < m; i++){
            for(ll j = 0; j < m; j++){
                cout << "YO" << endl;
                if(v[v2[j]] > v[v2[j + 1]]){
                    swap(v[v2[j]], v[v2[j + 1]]);
                    cout << "yO" << endl;
                }
            }
        }
        for(ll i = 0; i < n; i++){
            cout << v[i] << " ";
        }
        cout << endl;
        int flag = 0;
        for(ll i = 0; i < n - 1; i++){
            if(v[i] > v[i + 1]){
                flag = 1;
                break;
            }
        }
        if(flag == 1){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
    }


    return 0;
}