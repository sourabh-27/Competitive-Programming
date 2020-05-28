// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 
#define ll long long 
#define MAX 100002 
#define pb push_back 
 
unordered_map<int, int> cnts[MAX], cnts2[MAX]; 

ll countSubarrays(long long * arr, ll n) 
{ 
	ll left = 0, right = 0; 
	ll ans = 0; ll num = 0;
    long long temp[n + 1];
    for(ll i = 0; i < n; i++){
        temp[i] = arr[i];
    }
	while(right < n) { 
        while(temp[right] % 2 == 0){ 
            num++; 
            cnts[right][2]++; 
            temp[right] /= 2; 
        } 
		int flag = 0; 
        if(num < 1){ 
            flag = 1; 
        } 
		if (!flag){ 
			ans += n - right; 
			num -= cnts[left][2]; 
			left++; 
		} 
		else { 
			right++; 
		} 
	} 

    ll left2 = 0, right2 = 0; 
	ll ans2 = 0; ll num2 = 0;
	while (right2 < n) {
        while (arr[right2] % 2 == 0) { 
            num2++; 
            cnts2[right2][2]++; 
            arr[right2] /= 2; 
        }  
		int flag = 0; 
		if (num2 < 2){ 
			flag = 1;  
		} 
		if(!flag){ 
			ans2 += n - right2; 
			num2 -= cnts2[left2][2]; 
			left2++; 
		} 
		else{ 
			right2++; 
		} 
	}
	cout << "2: " << ans << endl;
    cout << "4: " << ans2 << endl;
    return ans + ans2;
} 

// Driver code 
int main() 
{ 
	long long arr[] = { 2, 5, 6 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	// int k = 2; 

	cout << countSubarrays(arr, n); 

	return 0; 
} 
