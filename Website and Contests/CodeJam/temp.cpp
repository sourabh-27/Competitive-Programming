#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
#define pb push_back
#define mp make_pair
typedef long long int ll;
 
ll findAns(ll n, ll m, vector<pair<ll, ll>> &vec) {
	if(n == 1){
        return 0;
    }
	for(ll i = 1; i <= m - 1; i++){
		 pair<ll,ll> pii;
		 pii.first = (m - i) * n + (i - 1) * (n - 1);
		 pii.second = n - 1;
		 vec.push_back(pii);
	}

	return (findAns(n - 1, m, vec) + m - 1);
}
 
int main() {
	ll t; cin>>t;
	for(ll xi = 1; xi <= t; xi++) {
 
		ll final = 0,n,m;  cin>>n>>m;
		vector<pair<ll,ll>> vec;
 
		final = findAns(n, m, vec);
 
		cout<<"Case #" << xi << ": " << final << endl;	
		for(ll i=0;i<vec.size();i++) {
			cout<< vec[i].first << " " << vec[i].second <<endl;
		}
        vec.clear();
	}
	return 0;
}