#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<ll> vec;
    vec.push_back(0);
    ll lastPos = 0;
    for(ll i = 0; i < 132; i++)
    {
        // cout << "vec.size() : " << vec.size() << endl;
        for(ll j = 0; j < vec.size() - 1; j++)
        {
            if(vec[i] == vec[j])
            {
                // cout << "I am looking for: " << vec[i] << " and got it at : " << j << endl;
                lastPos = j;
            }
        }
        if(lastPos == 0 && i != 1)
        {
            vec.push_back(0);
        }
        else
        {
            vec.push_back(i - lastPos);
        }
        lastPos = 0;
    }

    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        ll toFind = vec[n - 1];
        ll count = 0;
        for(ll i = 0; i < n; i++)
        {
            if(vec[i] == toFind)
            {
                count++;
            }
        }
        cout << count << endl;
    }



    return 0;
}