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
        string str;
        cin >> str;
        string str2 = "";
        str2 = str[str.length() - 1];
        str2 = str2 + str.substr(0, str.length() - 1);
        // cout << "str2: " << str2 << endl;
        string str3 = "";
        str3 = str.substr(1);
        str3 = str3 + str[0];
        // cout << "str2: " << str2 << " str3: " << str3 << endl;
        if(str2 == str3){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }


    return 0;
}