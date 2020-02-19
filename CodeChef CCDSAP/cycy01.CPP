#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
ll modi = 1000000000;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    vector<ll> vec;
    set<ll> myset;
    for(ll i = 1; i<=1000; i++){
        vec.push_back(i*i*i);
    }
    for(ll i = 0; i<vec.size(); i++){
        for(ll j = i+ 1; j<vec.size(); j++){
           myset.insert(vec[i] + vec[j]);
           myset.insert(abs(vec[i] - vec[j]));
        }
    }
    while(t--)
    {
        ll k;
        scanf("%lld", &k);
        ll flag = 1;
        set<ll>::iterator itr = myset.find(k); 
        if(itr == myset.end())flag = 0;
        if(flag == 1)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }

    return 0;
}