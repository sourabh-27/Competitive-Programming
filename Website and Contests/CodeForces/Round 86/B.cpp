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
        string t;
        cin >> t;
        ll len = t.length();
        ll zCount = 0; ll oCount = 0;
        for(ll i = 0; i < len; i++){
            if(t[i] == '0'){
                zCount++;
            }
            else{
                oCount++;
            }
        }
        string s = "";
        if(zCount == 0 || oCount == 0){
            cout << t << endl;
        }
        else{
            cout << t[0];
            for(ll i = 1; i < len; i++){
                // cout << "t[i]: " << t[i] << " t[i - 1]: " << t[i - 1] << endl;
                if(t[i] == t[i - 1]){
                    if(t[i] == '1'){
                        cout << '0';
                    }
                    else{
                        cout << '1';
                    }
                    cout << t[i];
                }
                else{
                    cout << t[i];
                }
            }
            cout << endl;
        }
    }


    return 0;
}