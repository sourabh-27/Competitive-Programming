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

class Scissors{
    public:
    int openingTime(int n){
        int ans = 0;
        while(n > 0){
            n = n / 2;
            ans = ans + 10;
        }
        return ans;
    }
};
int main()
{
    fast;
    ll n;
    cin >> n;
    Scissors obj;
    cout << obj.openingTime(n) << endl;
    return 0;
}