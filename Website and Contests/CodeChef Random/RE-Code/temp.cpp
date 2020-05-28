/* Read input from STDIN. Print your output to STDOUT*/
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
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
        
    }


    return 0;
}
int main(int argc, char *a[])
{
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		long long arr[n + 1], arr2[n + 1];
		// unordered_map<ll, bool> umap;
		for(ll i = 0; i < n; i++){
			cin >> arr[i];
			// umap[i] = false;
		}
        sort(arr, arr + n);
		ll count = 0;
		for(ll i = 0; i < n; i++){
			cin >> arr2[i];
		}
        sort(arr2, arr2 + n);
        for(ll i = 0; i < n; i++){
            auto upperBound = upper_bound(arr, arr + n, arr2[i]) - arr;
            // cout << "upperBound: " << upperBound << endl;
            if(upperBound != n){
                if(arr[upperBound] > arr2[i]){
                    arr[upperBound] = -1;
                    count++;
                    // cout << "i: " << i << " count: " << count << endl;
                }
            }
        }
        cout << count << endl;


	}
	//Write code here
}
