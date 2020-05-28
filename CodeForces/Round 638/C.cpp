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
        ll n, k;
        cin >> n >> k;
        string str;
        cin >> str;
        string str2 = str;
        sort(all(str2));
        // cout << "str2: " << str2 << endl;
        if(k == 1){
            cout << str2 << endl;
            continue;
        }
        else{
            vector<string> vec(k + 10), vec2(k + 10);
            for(ll i = 0; i < k; i++){
                vec[i] += str2[i]; vec2[i] += str2[i];
                // cout << "i: " << i << " vec[i]: " << vec[i] << endl;
            }
            for(ll i = k; i < n; i++){
                vec2[0] += str2[i];
                vec[i % k] += str2[i];
            }
            sort(all(vec)); sort(all(vec2));
            // for(ll i = 0; i < vec.size(); i++){
            //     cout << vec[i] << " ";
            // }
            // cout << endl;
            // for(ll i = 0; i < vec2.size(); i++){
            //     cout << vec2[i] << " ";
            // }
            // cout << endl;
            cout << min(vec[vec.size() - 1], vec2[vec2.size() - 1]) << endl;
        }

    }


    return 0;
}