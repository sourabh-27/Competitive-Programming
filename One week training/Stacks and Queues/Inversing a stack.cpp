#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

void reverse(stack<ll> s, ll n){
    if(s.empty()){
        return;
    }
    ll k = s.top();
    s.pop();
    reverse(s, n);
    s.push(k);
}
 
int main()
{
    fast;
    ll n;
    cin >> n;
    stack<ll> s;
    for(ll i = 0; i < n; i++){
        ll k; cin >> k;
        s.push(k);
    }

    reverse(s, n);

    for(ll i = 0; i < n; i++){
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}