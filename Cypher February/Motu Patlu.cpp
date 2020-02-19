#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

//The following function is taken from GeeksForGeeks. The link is given below:
//https://www.geeksforgeeks.org/count-number-of-triplets-with-product-equal-to-given-number-with-duplicates-allowed-set-2/
ll countTriplets(ll a[], ll m, ll n) 
{ 
	unordered_map<ll, ll> frequency; 
 
	set<pair<ll, pair<ll, ll> > > st; 
	for (ll i = 0; i < n; i++) { 
		frequency[a[i]] += 1; 
	}  
	ll ans = 0; 

	for (ll i = 1; i * i <= m; i++) { 
 
		if (m % i == 0 and frequency[i]) 
        {
			ll num1 = m / i; 
			for (ll j = 1; j * j <= num1; j++) 
            {
				if (num1 % j == 0 and frequency[j]) 
                { 
					ll num2 = num1 / j; 
					if (frequency[num2]) 
                    { 
						ll temp[] = { num2, i, j }; 
						sort(temp, temp + 3); 
						ll setsize = st.size(); 

						st.insert({ temp[0], { temp[1], temp[2] } }); 

						if (setsize != st.size()) 
                        { 
							if (i != j and j != num2) 
								ans += frequency[i] * frequency[j] * frequency[num2]; 

							else if (i == j && j != num2) 
								ans += (frequency[i] * (frequency[i] - 1) / 2) 
									* frequency[num2]; 
							else if (j == num2 && j != i) 
								ans += (frequency[j] * (frequency[j] - 1) / 2) 
									* frequency[i]; 

							else if (i == j and j == num2) 
								ans += (frequency[i] * (frequency[i] - 1) * (frequency[i] - 2) / 6); 

							else
								ans += (frequency[i] * (frequency[i] - 1) / 2) 
									* frequency[j]; 
						} 
					} 
				} 
			} 
		} 
	} 

	return ans; 
}
 
int main()
{
    fast;
    ll n, p;
    cin >> n >> p;
    long long arr[n + 1];
    for(ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    ll ans = countTriplets(arr, p, n);
    cout << ans << endl;

    return 0;
}