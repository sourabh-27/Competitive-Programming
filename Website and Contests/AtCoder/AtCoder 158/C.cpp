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
    long double a, b;
    cin >> a >> b;
    for(long double i = 1; i <= 10000000; i++){
        if(floor(i * 0.08) == a && floor(i * 0.1) == b){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;


    return 0;
}