#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define all(x) (x).begin(),(x).end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
#define pb push_back
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define mp make_pair
typedef long long int ll;
 
int main()
{
    fast;
    ll n;
    cin >> n;
    long long parent[n + 5];
    for(ll i = 1; i <= n; i++){
        cin >> parent[i];
    }
    ll flag = 0;
    for(ll i = 1; i <= n; i++){
        ll x = parent[i];
        ll count = 1;
        while(x != i){
            count++;
            if(count > 3){
                break;
            }
            x = parent[x];
        }
        // cout << "count: " << count << endl;
        if(count == 3){
            flag = 1;
        }
    }
    cout << ((flag == 1) ? "YES":"NO") << endl;


    return 0;
}