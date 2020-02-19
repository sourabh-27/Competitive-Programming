#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

bool findSquare(ll n) 
{ 
    unordered_map<int, int> k; 
    for (int i = 1; i * i <= n; ++i)
    { 
        k[i * i] = 1; 
        if (k.find(n - i * i) != k.end()) { 
            return true; 
        } 
    } 
    return false; 
} 

pair<ll, ll> ans(ll n) 
{ 
    unordered_map<int, int> s; 
    for (ll i = 1; i * i <= n; ++i) { 
        s[i * i] = 1; 
        if (s.find(n - i * i) != s.end()) { 
            pair<ll, ll> ans;
            ans.first = sqrt(n - i * i);
            ans.second = i;
            return ans; 
        } 
    }  
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while(t--)
    {
        ll a, b;
        cin >> a >> b;
        ll sum = a * a + b * b;
        // cout << "sum : " << sum << endl;
        ll start = 1; ll start2 = 1;
        pair<ll, ll> k;
        ll temp = 0;
        for(ll i = 1; i < 10000000; i++)
        {
            if(findSquare(i))
            {
                if(i > sum)
                {
                    if(findSquare(i * sum))
                    {
                        k = ans(i);
                        break;
                    }
                }
            }
        }
        cout << k.first << " " << k.second << endl;
    }

    return 0;
}