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
        ll n, k;
        cin >> n >> k;
        long long arr[n + 2];
        for(ll i = 1; i <= n; i++){
            cin >> arr[i];
        }
        map<ll, ll> umap;
        ll count = 0;
        for(ll i = 1; i <= k; i++){
            if(i == 1 || i == k){
                continue;
            }
            if(arr[i] > arr[i - 1] && arr[i] > arr[i + 1]){
                count++;
            }
        }
        // cout << "count1: " << count << endl;
        umap[1] = count;
        for(ll i = 2; i <= n - k + 1; i++){
            if(arr[i] > arr[i - 1] && arr[i] > arr[i + 1]){
                count = count - 1;
            }
            // cout << "i: " << i << " count: " << count << " i+k-1: " << arr[i + k - 1] << endl;
            if(arr[i + k - 2] > arr[i + k - 3] && arr[i + k - 2] > arr[i + k - 1]){
                count++;
            }
            umap[i] = count;
            // cout << "i: " << i << " count: " << count << endl;
        }
        ll maxi = -1e18; ll index = 1;
        for(auto x: umap){
            // cout << " x.first " << x.first << " x.second: " << x.second << endl;
            if(x.second > maxi){
                maxi = x.second;
                index = x.first;
            }
        }
        cout << maxi + 1 << " " << index << endl;

    }


    return 0;
}