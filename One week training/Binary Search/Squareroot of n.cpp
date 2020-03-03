#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

ll findSquare(ll n){
    ll low = 0; ll high = n;
    while(low <= high){
        ll mid = low + (high - low) / 2;
        if(mid * mid > n){
            high = mid - 1;
        }
        else if(mid * mid == n){
            return mid;
        }
        else{
            if((mid + 1) * (mid + 1) > n){
                return mid;
            }
            else{
                low = mid + 1;
            }
        }
    }
}

//low inclusive and high exclusive
ll findSquareExclusive(ll n){
    ll low = 0; ll high = n + 1;
    while(high - low > 1){
        ll mid = low + (high - low) / 2;
        if(mid * mid > n){
            high = mid;
        }
        else{
            low = mid;
        }
    }
    return low;
}
 
int main()
{
    fast;
    ll n;
    cin >> n;
    ll ans = findSquareExclusive(n);
    cout << "Square root is: " << ans << endl;

    return 0;
}