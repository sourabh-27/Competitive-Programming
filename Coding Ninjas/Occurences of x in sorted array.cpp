#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

ll firstOccur(long long * arr, ll start, ll end, ll key){
    ll n = end + 1;
    while(end - start > 1){
        ll mid = start + (end - start) / 2;
        if(arr[mid] < key){
            start = mid;
        }
        else{
            end = mid;
        }
    }
    if(arr[end] == key){
        return end;
    }
    return -1;
}

ll lastOccur(long long * arr, ll start, ll end, ll key){
    ll n = end;
    while(end - start > 1){
        ll mid = start + (end - start) /2 ;
        if(arr[mid] > key){
            end = mid;
        }
        else{
            start = mid;
        }
    }
    if(arr[start] == key){
        return start;
    }
    return -1;
}

 
int main()
{
    fast;
    ll n;
    cin >> n;
    long long arr[n + 1];
    for(ll i = 0; i < n; i++){
        cin >> arr[i];
    }
    ll key;
    cin >> key;
    ll k1 = firstOccur(arr, -1, n - 1, key);
    ll k2 = lastOccur(arr, 0, n, key);
    cout << "The distance is: " << k2 - k1 + 1 << endl;

    return 0;
}