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
typedef long long int ll;
 
int main()
{
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        long long arr[n + 1];
        for(ll i = 0; i < n; i++){
            cin >> arr[i];
        }
        ll i;
        for(i = 0; i < n - 1; ){
            if(arr[i + 1] == arr[i] + 1 || arr[i + 1] < arr[i]){
                i++;
            }
            else{
                break;
            }
        }
        if(i == n - 1){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }


    return 0;
}