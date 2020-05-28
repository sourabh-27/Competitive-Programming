#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

void maxIndWindow(long long * arr, ll n, ll k){
    deque<ll> deq;
    for(ll i = 0; i < k; i++){
        while(!deq.empty() && arr[i] > arr[deq.back()]){
            deq.pop_back();
        }
        deq.push_back(i);
    }

    for(ll i = k; i < n; i++){
        cout << arr[deq.front()] << " ";
        if(deq.front() <= i - k){
            deq.pop_front();
        }
        while(!deq.empty() && arr[i] > arr[deq.back()]){
            deq.pop_back();
        }
        deq.push_back(i);
    }
    // while(!deq.empty()){                                                                       
        
    //     cout << arr[deq.front()] << " ";
    //     deq.pop_front();
    // }
    cout << arr[deq.front()] << " ";
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
    ll k;
    cin >> k;
    maxIndWindow(arr, n, k);

    return 0;
}