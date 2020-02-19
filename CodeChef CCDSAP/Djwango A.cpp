#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    ll temp = n;
    ll total = 0;
    vector<pair<string, ll>> vec;
    while(n--)
    {
        string str;
        cin >> str;
        ll t;
        cin >> t;
        vec.push_back(make_pair(str, t));
    }
    string x;
    cin >> x; 
    int flag = 0;
    for(ll i = 0; i < temp; i++)
    {
        if(flag == 1)
        {
            total += vec[i].second;
        }
        if(vec[i].first == x)
        {
            flag = 1;
        }
    }
    cout << total << endl;

    return 0;
}