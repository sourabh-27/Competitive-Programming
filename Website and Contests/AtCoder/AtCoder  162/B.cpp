#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
#define pb push_back
#define mp make_pair
typedef long long int ll;
 
int main()
{
    fast;
    ll n;
    cin >> n;
    ll sum = 0;
    for(ll i = 1; i <= n; i++){
        if(i % 3 == 0 || i % 5 == 0){
            continue;
        }
        else{
            sum += i;
        }
    }
    cout << sum << endl;


    return 0;
}