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
    stack<ll> s;
    long long arr[n + 1];
    for(ll i = 0; i < n; i++){
        ll k;
        cin >> arr[i];
    }
    
    long long temp[n + 1];
    for(ll i = 0; i < n; i++){
        ll top = arr[i];
        while(!s.empty() && top > arr[s.top()]){
            temp[s.top()] = top;
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()){
        temp[s.top()] = NULL;
        s.pop();
    }

    for(ll i = 0; i < n; i++){
        cout << temp[i] << " ";
    }
    cout << endl;

    return 0;
}