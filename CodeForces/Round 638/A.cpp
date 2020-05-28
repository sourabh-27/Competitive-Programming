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
        ll n;
        cin >> n;
        ll sum1 = 0, sum2 = 0;
        for(ll i = 1; i < n / 2; i++){
            sum1 += pow(2, i);
        }
        sum1 = sum1 + pow(2, n);
        for(ll i = n / 2; i < n; i++){
            sum2 += pow(2, i);
        }
        cout << abs(sum2 - sum1) << endl;
    }


    return 0;
}