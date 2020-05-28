#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
#define high 1000000000
typedef long long int ll;

// void primeFactors()  
// {  
//     // Print the number of 2s that divide n  

//     while (high % 2 == 0)  
//     {  
//         cout << 2 << " ";  
//         high = high/2;  
//     }  
  
//     // n must be odd at this point. So we can skip  
//     // one element (Note i = i +2)  
//     for (int i = 3; i <= sqrt(high); i = i + 2)  
//     {  
//         // While i divides n, print i and divide n  
//         while (high % i == 0)  
//         {  
//             cout << i << " ";  
//             n = n/i;  
//         }  
//     }  
  
//     // This condition is to handle the case when n  
//     // is a prime number greater than 2  
//     if (n > 2)  
//         cout << n << " ";  
// }

ll factors(ll n){
    ll count = 0;
    while(n % 2 == 0){
        count++;
        n /= 2;
    }

    for(ll i = 3; i <= sqrt(n); i = i + 2){
        while(n % i == 0){
            count++;
            n = n / i;
        }
    }
    if(n > 2){
        count++;
    }
    return count;
}
 
int main()
{
    fast;
    ll t;
    cin >>  t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        ll ans = 1; int flag = 0;
        for(ll i = 1; i <= k; i++){
            // cout << "ans: " << ans << endl;
            ans = ans * 2;
            if(ans > n){
                flag = 1;
                break;
            }
        }
        if(flag == 1 || k == 0){
            cout << 0 << endl;
        }
        else{
            // cout << "YO" << endl;
            // cout << "factors(n): " << factors(n) << endl;
            if(factors(n) >= k){
                cout << 1 << endl;
            }
            else{
                cout << 0 << endl;
            }
        }
    }

    return 0;
}