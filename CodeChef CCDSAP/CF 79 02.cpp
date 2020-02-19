#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while(t--)
    {
        ll n, s;
        cin >> n >> s;
        vector<ll> vec, vec2;
        for(ll i = 0; i < n; i++)
        {
            ll k;
            cin >> k;
            vec.push_back(k);
        }
        vec2 = vec;
        sort(vec.begin(), vec.end());
        ll sum = 0; ll i = 0;
        while(sum <= s)
        {
            sum += vec[i];
            i++;
        }
        ll actual_deleted = n - (i - 1);
        vector<ll>::iterator itr;
        ll to_find = vec[n - actual_deleted];
        cout << "to_find: " << to_find << endl;
        ll posi;
        for(i = 0; i < vec.size(); i++)
        {
            if(vec2[i] == to_find)
            {
                posi = i;
                break;
            }
        }
        ll estimated_deleted = n - posi;
        if(actual_deleted == estimated_deleted)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << actual_deleted << endl;
        }
    }

    return 0;
}