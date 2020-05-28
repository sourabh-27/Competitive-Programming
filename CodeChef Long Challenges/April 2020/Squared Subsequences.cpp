#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
#define MAX 100002 
typedef long long int ll;

// ll countSubarrays2(long long * arr, ll n){
//     ll left = 0, right = 0; 
// 	ll ans = 0; ll num = 0;
//     ll countL = 0; ll countR = 0;
//     long long temp[n + 1], rCount[n + 1];
//     for(ll i = 0; i < n; i++){
//         temp[i] = arr[i];
//         rCount[i] = 0;
//     }
// 	while(right < n) { 
//         while(temp[right] % 2 == 0){ 
//             num++; 
//             rCount[right]++; 
//             // cout << "right: " << right << endl;
//             temp[right] /= 2; 
//         } 
// 		int flag = 0; 
//         if(num < 1){ 
//             flag = 1; 
//         } 
// 		if (!flag){ 
// 			ans += n - right; 
// 			num -= rCount[left]; 
// 			left++; 
// 		} 
// 		else { 
// 			right++; 
// 		} 
// 	} 
//     // cout << "2: " << ans << endl;
//     return ans;
// }

ll bruteForce(long long * arr, ll n){
    ll count = 0;
        for(ll i = 0; i < n; i++){
            ll mul = 1;
            // cout << "YO" << endl;
            for(ll j = i; j < n; j++){
                mul = mul * arr[j];
                // cout << "i: " << i << " j: " << j << endl;
                // cout << "mul:" << mul << endl;
                if(mul % 2 != 0 || mul % 4 == 0){
                    // cout << "mul:" << mul << endl;
                    count++;
                    if(mul >= 100){
                        mul = (((mul / 10) % 10) * 10) + (mul % 10);
                        // cout << "new mul: " << mul << endl;
                    }
                }
                // else{
                //     break;
                // }
            }
        }
    return count;
}

ll countSubarrays(long long * arr, ll n, ll k) 
{
    ll left = 0, right = 0; 
	ll ans = 0; ll num = 0;
    long long rCount[n + 1], temp[n + 1];
    for(ll i = 0; i < n; i++){
        temp[i] = arr[i];
        rCount[i] = 0;
    }
	while (right < n) {
        while (temp[right] % 2 == 0 && temp[right] != 0) { 
            num++; 
            rCount[right]++; 
            temp[right] /= 2; 
        }  
        // cout << "left: " << left <<  " right: " << right << endl;
		int flag = 0; 
		if (num < k){ 
			flag = 1;  
		} 
		if(!flag){ 
			ans += n - right; 
			num -= rCount[left]; 
			left++; 
		} 
		else{ 
			right++; 
		} 
	}
    // cout << "4: " << ans << endl;
    return ans;
}
 
int main()
{
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        long long arr[n + 1];
        int flag = 0;
        for(ll i = 0; i < n; i++){
            ll k;
            cin >> k;
            k = abs(k);
            if(k == 0){
                flag = 1;
            }
            arr[i] = k;
        }
        if(flag == 1){
            ll ans = bruteForce(arr, n);
            cout << ans << endl;
            continue;
        }
        ll total = (n * (n + 1)) / 2;
        ll ans = abs(total - countSubarrays(arr, n, 1));
        // cout << "ans: " << ans << endl;
        cout << ans + countSubarrays(arr, n, 2) << endl;
    }

    return 0;
}