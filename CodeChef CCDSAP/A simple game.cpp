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
        ll n;
        cin >> n;
        vector<ll> vec;
        ll totalSum = 0; ll oddCount = 0;
        for(ll i = 0; i < n; i++)
        {
            ll c;
            cin >> c;
            ll mid = c / 2;
            ll arr2[c + 1];
            ll sum = 0;
            for(ll j = 0; j < c; j++)
            {
                cin >> arr2[j];
                if(j < mid)
                {
                    sum += arr2[j];
                }
            }
            if(c % 2 != 0)
            {
                oddCount++;
                vec.push_back(arr2[mid]);
            }
            // cout << "sum : " << sum << endl;
            totalSum += sum;
        }
        sort(vec.begin(), vec.end(), greater<int>());
        ll size = vec.size();
        for(ll i = 0; i < size; i += 2)
        {
            totalSum += vec[i];
        }
        cout << totalSum << endl;
    }

    return 0;
}