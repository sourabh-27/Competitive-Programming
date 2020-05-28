#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

const int N = 1000001;

void sieve(vector<bool> &prime){
    for(ll i = 2; i * i <= N; i++){
        if(prime[i]){
            for(ll j = i * i; j <= N; j += i){
                prime[j] = false;
            }   
        }
    }
}
 
int main()
{
    fast;
    ll t;
    cin >> t;
    vector<bool> prime(N);
    prime[0] = prime[1] = false;
    for(ll i = 2; i <= N; i++){
        prime[i] = true;
    }
    sieve(prime);
    while(t--){
        ll n;
        cin >> n;
        ll primeCount = 0; ll nonPrime = 0;
        vector<ll> vec;
        for(ll i = 1; i <= n; i++){
            if(prime[i]){
                vec.push_back(i);
                primeCount++;
            }
        }
        nonPrime = n - primeCount;
        // cout << "primeCount: " << primeCount << " non Prime: " << nonPrime << endl;
        
    }

    return 0;
}