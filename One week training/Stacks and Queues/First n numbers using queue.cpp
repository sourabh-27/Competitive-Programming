#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;
 
int main()
{
    fast;
    ll n;
    cin >> n;
    long long arr[n + 1];
    for(ll i = 0; i < n; i++){
        cin >> arr[i];
    }
    ll times;
    cin >> times; ll count = 0;
    queue<ll> q; q.push(0);
    while(count < times){
        ll x = q.front();
        q.pop();
        for(ll i = 0; i < n; i++){
            q.push(x * 10 + arr[i]);
        }
        if(x != 0){
            cout << x << " ";
            count++;
        }
    }

    return 0;
} 